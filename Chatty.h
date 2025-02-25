#pragma once
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
    
class Chatty {
    private:
        std::string api_key;
        std::string model_name;
        CURL* curl; //for HTTPS requests in C++

    public:
        Chatty(const std::string& key, const std::string& model = "claude-3-haiku-20240307");
        ~Chatty();  // constructor and destructor
        std::string chat(const std::string& message); // the main chat function of the Chatty class
    };


