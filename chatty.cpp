#include "Chatty.h"
#include <iostream>

//constructor to fill in the key,model variables, and intialize curl resources

Chatty::Chatty(const std::string& key, const std::string& model) 
    : api_key(key), model_name(model) { //list initlization
    curl = curl_easy_init();
}

Chatty::~Chatty() {
    if (curl) curl_easy_cleanup(curl); //normally destructor is automatically created but CURL* needs a specialized curl_easy_cleanup to prevent memory leaks
}

// Response data as output
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append((char*)contents, total_size); //derefrences output, then adds to itm same as (*output).append()
    return total_size;
}

// Send message to Claude API and get response
std::string Chatty::chat(const std::string& message) {
    std::string response_string;

    //gets a little complicated looking but its essentially just defining headers, and redying the 
    //JSON package and creating a parser to go through the response
    // no need to design this from scratch since it's a common implementation and 
    // there are plenty on the internet

    //creating a linked list for headers, just the way CURL needs to be implemented 
    struct curl_slist* headers = NULL;

    // Set up headers (Content-Type, API Key, Version) as per Claude documentation
    headers = curl_slist_append(headers, "Content-Type: application/json");
    std::string auth_header = "x-api-key: " + api_key;
    headers = curl_slist_append(headers, auth_header.c_str());
    headers = curl_slist_append(headers, "anthropic-version: 2023-06-01");

    // Create JSON payload to send to Claude serveers
    nlohmann::json payload = {
        {"model", model_name},
        {"max_tokens", 1000},
        {"system","You are a friendly chatbot named Chatty made by the R1 group, use some emojis in chat, and joke around"}, //role assigning 
        {"messages", nlohmann::json::array({
            {{"role", "user"}, {"content", message}}
        })}
    };
    
    std::string payload_str = payload.dump(); // json to string before sending

    // Configure to Send payload (as a string) to the given url with the configured headers
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.anthropic.com/v1/messages");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload_str.c_str());

    //Configure receive and store in string
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);


    CURLcode res = curl_easy_perform(curl); //send the Https request
    curl_slist_free_all(headers);

    nlohmann::json response_json = nlohmann::json::parse(response_string); // from json string to json object
    return response_json["content"][0]["text"]; //returns user request as JSON
}