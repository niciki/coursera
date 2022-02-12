#include "search_server.h"
#include "iterator_range.h"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>

vector<string_view> SplitIntoWords(string_view line) {
    vector<string_view> res;
    size_t curr = line.find_first_not_of(' ', 0);
    while (1) {
        auto space = line.find(' ', curr);
        res.emplace_back(line.substr(curr, space - curr));
        if (space == line.npos) {
            break;
        } else {
            curr = line.find_first_not_of(' ', space);
        }
        if (curr == line.npos) {
            break;
        }
    }
    return res;

}

SearchServer::SearchServer(istream& document_input) {
    UpdateDocumentBase(document_input);
}

void SearchServer::UpdateDocumentBase(istream& document_input) {
    InvertedIndex new_index;
    for (string current_document; getline(document_input, current_document); ) {
        new_index.Add(move(current_document));
    }
    {
        m.lock();
        // std::lock_guard<std::mutex> lock(m);
        swap(new_index, index);
        m.unlock();
    }
}

void SearchServer::AddQueriesStream(istream& query_input, ostream& search_results_output){

    auto fut = [&query_input, &search_results_output, this]() {
        vector<size_t> docs(50000);
        vector<size_t> indx(50000);
        for (string current_query; getline(query_input, current_query); ) {
            size_t curr_ind = 0;
            for (const auto& word : SplitIntoWords(current_query)){
                std::vector<std::pair<size_t, size_t>> vec;
                {
                    m.lock();
                    // std::lock_guard<std::mutex> lock(m);
                    vec = index.Lookup(word);
                    m.unlock();
                }
                for (const auto& [docid, count] : vec) {
                    if (docs[docid] == 0) {
                        indx[curr_ind++] = docid;
                    }
                    docs[docid] += count;
                }
            }

            vector<pair<size_t, size_t>> search_result;
            for (size_t i = 0; i < curr_ind; ++i) {
                size_t count = 0;
                size_t id = 0;
                swap(count, docs[indx[i]]);
                swap(id, indx[i]);
                search_result.emplace_back(id, count);
            }

            const size_t ANSWERS_COUNT = 5;
            partial_sort(begin(search_result), begin(search_result) + min<size_t>(ANSWERS_COUNT, search_result.size()),
                    end(search_result),
                [](pair<size_t, size_t> lhs, pair<size_t, size_t> rhs) {
                    int64_t lhs_docid = lhs.first;
                    auto lhs_hit_count = lhs.second;
                    int64_t rhs_docid = rhs.first;
                    auto rhs_hit_count = rhs.second;
                    return make_pair(lhs_hit_count, -lhs_docid) > make_pair(rhs_hit_count, -rhs_docid);
                });

            search_results_output << current_query << ':';
            for (auto [docid, hitcount] : Head(search_result, ANSWERS_COUNT)) {
                search_results_output << " {"
                                    << "docid: " << docid << ", "
                                    << "hitcount: " << hitcount << '}';
            }
            search_results_output << "\n";
        }
    };
    futures.push_back(async(fut));
}

void InvertedIndex::Add(string&& document){
    docs.push_back(move(document));
    size_t docid = docs.size() - 1;
    for (const auto& word : SplitIntoWords(docs.back())){
        auto& vec_pair = index[word];
        if (!vec_pair.empty() && vec_pair.back().first == docid) {
            vec_pair.back().second += 1;
        } else {
            vec_pair.emplace_back(docid, 1);
        }
    }
}

vector<pair<size_t, size_t>> InvertedIndex::Lookup(string_view word) const {
    return (index.count(word)) ? index.at(word) : vector<pair<size_t, size_t>>();
}

SearchServer::~SearchServer() {
    for (auto& i: futures) {
        i.get();
    }
}