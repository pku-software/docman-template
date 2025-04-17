#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <sstream>

// Singleton class to manage the API endpoint
class APIEndpoint {
private:
  std::string endpoint = "http://docman.zhuof.wang";
  APIEndpoint() {
    const char *env_override = std::getenv("DOCMAN_API_ENDPOINT");
    if (env_override != nullptr) {
      endpoint = env_override;
    }
  }

public:
  static const std::string &get() {
    static APIEndpoint instance;
    return instance.endpoint;
  }
};

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
            // convert to hex
            std::stringstream ss;
            ss << std::hex << (int) c;
            encoded += ss.str();
        }
    }
    return encoded;
}

#endif 
