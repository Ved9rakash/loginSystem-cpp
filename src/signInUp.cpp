#include "signInUp.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void sleep(int milliseconds)
{
    //sleeping the program for x milliseconds to make it more realistic
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

//Constructor
LoginInUp::LoginInUp(std::string name, std::string password)
{
    m_userName = name;
    m_userPassword = password;

    std::ifstream fin{ "loginCredentials.csv" };

    std::vector<std::string> row;
    std::string line{};
    std::string word{};
  
    if (!fin)
    {
        std::cout << " FILE CAN'T BE OPENED";
    }
 
    while (fin)
    {
        row.clear();
  
        std::getline(fin, line);
  
        std::stringstream s{line};
  
        while (std::getline(s, word, ','))
        {  
            row.push_back(word);
        }

        if (name == row[0])
        {
            m_number = row[2];
            m_age = std::stoi(row[3]);
        }
    }
}
//Checking is the username is already present or not
bool LoginInUp::isPresent(std::string name)
{
    std::ifstream fin{ "loginCredentials.csv" };

    std::vector<std::string> row;
    std::string line{};
    std::string word{};
  
    if (!fin)
    {
        std::cout << " FILE CAN'T BE OPENED";
    }
 
    while (fin)
    {
        row.clear();
  
        std::getline(fin, line);
  
        std::stringstream s{line};
  
        while (std::getline(s, word, ','))
        {  
            row.push_back(word);
        }

        if (name == row[0])
        {
            return 1;
        }
    }
    return 0;
}

bool LoginInUp::passwordCheck(std::string password)
{
    std::ifstream fin{ "loginCredentials.csv" };

    std::vector<std::string> row;
    std::string line{};
    std::string word{};
  
    if (!fin)
    {
        std::cout << " FILE CAN'T BE OPENED";
    }
    while (fin)
    {
        row.clear();
  
        std::getline(fin, line);
  
        std::stringstream s{line};
  
        while (std::getline(s, word, ','))
        {  
            row.push_back(word);
        }

        if (password == row[1])
        {
            std::cout << "Is this printing?";
            return 1;
        }
    }
    return 0;
}

//Adding new credentials in logincredentails.csv file
void LoginInUp::add(
        std::string name, 
        std::string password, 
        std::string number, 
        int age, 
        std::string gender
    )
    {
    std::ofstream outf{ "loginCredentials.csv", std::ios_base::app};

    if (!outf)
    {
        std::cout << "FILE CAN'T BE OPENED";
    }

    outf
        << '\n'
        << name << ','
        << password << ','
        << number << ','
        << age << ','
        << gender ;
}

//Getting age
int LoginInUp::age()
{
    return m_age;
}

//Getting Mobile Number
std::string LoginInUp::mobileNumber()
{
    return m_number;
}