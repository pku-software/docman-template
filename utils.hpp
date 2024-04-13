#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <fstream>

constexpr const auto& API_ENDPOINT = "http://docman.lcpu.dev";

inline std::string encodeUriComponent(const std::string& s) {
    std::string encoded;
    char c;
    for (size_t i = 0; i < s.length(); i++) {
        c = s[i];
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            encoded += c;
        } else if (c == ' ') {
            encoded += '+';
        } else {
            encoded += '%';
            encoded += std::to_string((int) c / 16);
            encoded += std::to_string((int) c % 16);
        }
    }
    return encoded;
}

inline std::string readFromFile(const std::string& filename) {
    std::fstream fin(filename);
    std::string content;
    std::string line;
    while (std::getline(fin, line)) {
        content += line;
    }
    return content;
}

#endif 