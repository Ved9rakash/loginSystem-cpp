#include "SystemAnalyser.hpp"
#include <iostream>
#include <string>
#include <array>
#include <memory>

SystemAnalyser::SystemAnalyser()
{

}

std::string SystemAnalyser::runCommand(const char *command)
{
    std::array<char, 128> buffer{};
    std::string results{};
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command, "r"), pclose);

    if (!pipe) {
        throw std::runtime_error("popen() failed");
    }

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        results += buffer.data();
    }

    std::cout << results << std::endl;
    return results;
}

void SystemAnalyser::storeOutput(std::string& result)
{

}

void SystemAnalyser::displayOutput()
{

}

SystemAnalyser::~SystemAnalyser()
{
    
}