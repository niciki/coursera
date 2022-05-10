#include "ini.h"

#include <iostream>

Ini::Section& Ini::Document::AddSection(string name) {
    return sections[name];
}

const Ini::Section& Ini::Document::GetSection(const string& name) const {
    return sections.at(name);
}

size_t Ini::Document::SectionCount() const {
    return sections.size();
}

Ini::Document Ini::Load(istream& input) {
    Ini::Document answ;
    string buffer;
    Ini::Section* current_section;
    string name;
    while(getline(input, buffer)) {
        if (buffer[0] == '[') {
            name = buffer.substr(1, buffer.size() - 2);
            current_section = &answ.AddSection(buffer.substr(1, buffer.size() - 2));
        } else if (buffer != "") {
            auto i = buffer.find('=');
            (*current_section)[buffer.substr(0, i)] = buffer.substr(i + 1);
        }
    }
    return answ;
}