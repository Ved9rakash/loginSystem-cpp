#ifndef __SYSTEM_ANALYSER_HPP__
#define __SYSTEM_ANALYSER_HPP__

#include <string>

class SystemAnalyser
{
public:
    SystemAnalyser();
    virtual void runCommand(const char *command);
    virtual void storeOutput(std::string& result);
    virtual void displayOutput();
    virtual ~SystemAnalyser();
};

#endif