#ifndef SIGNINUP_HPP
#define SIGNINUP_HPP

#include <iostream>
#include <string>

struct Data
{
    int id;
    int number;
};

class LoginInUp
{
private:
    std::string m_userName{};
    std::string m_userPassword{};
    int m_number{};
    int m_age{};

public:
    LoginInUp(std::string name, std::string password);

    static bool isPresent(std::string name, std::string password);

    // static bool isPresent(std::string name);

    static void add(std::string name, std::string password);

    int age();

    int mobileNumber();
};
#endif