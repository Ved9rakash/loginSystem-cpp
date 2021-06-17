#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <string>


class Login
{
private:
    std::string m_userName{};
    std::string m_userPassword{};

public:
    Login() = default;

    bool isPresent();
};

class Register
{
private:
    std::string m_userName{};
    std::string m_userPassword{};
    int finalCheck{0};

public:
    Register() = default;
    
    Register(std::string name, std::string password)
        : m_userName{name}, m_userPassword{password}
        {
        }
    
    friend bool Login::isPresent();

    void createAccount() { }

    virtual ~Register();
};



#endif