#include "httplib.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

// Setup model etc...

int main() {
    httplib::Server svr;

    svr.Post("/ask", [&](const httplib::Request& req, httplib::Response& res) {
        auto body = json::parse(req.body);
        std::string user_prompt = body["prompt"];

        // Your LLaMA inference logic here...
        std::string answer = run_llama(user_prompt);

        res.set_content(answer, "text/plain");
    });

    svr.listen("localhost", 8080);
}
