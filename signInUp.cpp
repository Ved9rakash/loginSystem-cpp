#include "signInUp.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void Register::createAccount()
{
    std::fstream fout;
    fout.open("loginCredentials.csv", std::ios::out | std::ios::app);
    fout << m_userName << ", " << m_userPassword;
}

bool Login::isPresent()
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