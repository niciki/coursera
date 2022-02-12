#include "search_server.h"
#include "iterator_range.h"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>

vector<string> SplitIntoWords(const string& line) {
    istringstream words_input(line);
    return {istream_iterator<string>(words_input), istream_iterator<string>()};
}

SearchServer::SearchServer(istream& document_input) {
    UpdateDocumentBase(document_input);
}

void SearchServer::UpdateDocumentBase(istream& document_input) {
    InvertedIndex new_index;

    for (string current_document; getline(document_input, current_document); ) {
        new_index.Add(move(current_document));
    }

    index = move(new_index);
}

void SearchServer::AddQueriesStream(istream& query_input, ostream& search_results_output){
    vector<size_t> docs(50000);
    vector<size_t> indx(50000);
    for (string current_query; getline(query_input, current_query); ){
        size_t curr_ind = 0;
        for (const auto& word : SplitIntoWords(current_query)){
            auto vec = index.Lookup(word);
            for (const auto& [docid, count] : vec){
                // cout << docid << " " << count << "\n";
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
            [](pair<size_t, size_t> lhs, pair<size_t, size_t> rhs)
            {
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

vector<pair<size_t, size_t>> InvertedIndex::Lookup(string word) const {
    return (index.count(word)) ? index.at(word) : vector<pair<size_t, size_t>>();
}