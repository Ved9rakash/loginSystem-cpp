#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Login
{
private:
    std::string m_userName{};
    std::string m_userPassword{};
public:

    Login() = default;

    bool isPresent()
    {
        std::ifstream check;
        check.open("loginCredentials.csv");

        while (std::getline(check, m_userName))
        {
            std::istringstream iss(m_userName);
            std::string name{};

            if (std::getline(iss, name))
            {
                return 0;
            }
        }
        return 1;
    }

};

#endif