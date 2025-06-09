#include <iostream>
#include <cstdio>
#include <memory>

#include <stdexcept>
#include <string>

std::string runPythonScript(const std::string& scriptPath) {
    std::string command = "python " + scriptPath + " 2>&1"; // Redirect stderr to stdout
    std::string result;
    char buffer[128];

    std::shared_ptr<FILE> pipe(_popen(command.c_str(), "r"), _pclose);
    if(!pipe) throw std::runtime_error("popen() failed");

    while(fgets(buffer, sizeof(buffer), pipe.get()) != nullptr){
        result += buffer;
    }

    return result;
}
