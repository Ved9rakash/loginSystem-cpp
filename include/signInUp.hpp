#ifndef SIGNINUP_HPP
#define SIGNINUP_HPP

#include <iostream>
#include <string>

class LoginInUp
{
private:
    std::string m_userName{};
    std::string m_userPassword{};
    std::string m_number{};
    int m_age{};

public:
    LoginInUp(std::string name, std::string password);

    static bool isPresent(std::string name);

    static bool passwordCheck(std::string password);

    static void add(
        std::string name, 
        std::string password, 
        std::string number, 
        int age, 
        std::string gender
    );

    int age();

    std::string mobileNumber();
};

#endif