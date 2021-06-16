#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Register
{
private:
    std::string m_userName{};
    std::string m_userPassword{};
    int finalCheck{0};

public:
    Register(std::string name, std::string password)
        : m_userName{name}, m_userPassword{password}
        {
        }
    
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
                std::cout << "This username already exists. Try another.";
                return 0;
            }
        }
        return 1;
    }

    void createAccount()
    {
        std::fstream fout;
        fout.open("loginCredentials.csv", std::ios::out | std::ios::app);
        fout << m_userName << ", " << m_userPassword;
    }
    
};

#endif