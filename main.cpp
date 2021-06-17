#include "signInUp.hpp"
#include "SystemAnalyser.hpp"

#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>
#include <chrono>
#include <thread>

void sleep(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void commandClear()
{
    auto system = std::make_unique<SystemAnalyser>();
    system->runCommand("clear");
}

bool loginSystem();
bool registerSystem();

int main()
{
    commandClear();

    int loginAccess{0};
    int registerAccess{0};
    
    do 
    {
        int num{};
        //std::cout << typeid(system).name() << '\n';
        std::cout << "Welcome to my c++ website.\n\n";
        std::cout << "Press\n1 -> Login.\n2 -> Register\n";

        std::cin >> num;
        sleep(1000);

        switch(num)
        {
            case 1:
                loginAccess = loginSystem();
                if (loginAccess == 1)
                    registerAccess = 1;
                break;

            case 2:
                registerAccess = registerSystem();
                if (registerAccess == 1)
                    loginAccess = 1;
                break;

            default:
                break;
        }
    }while((loginAccess == 0) && (registerAccess == 0));


    return 0;
}

bool loginSystem()
{
    commandClear();
    std::string username{};
    std::string userpassword{};
    
    bool access{0};
    do
    {
        std::cout << "Pls Enter the following: \n\n";
        std::cout << "Username: \n";
        std::getline(std::cin >> std::ws, username);
        std::cout << "Password: \n";
        std::getline(std::cin >> std::ws, userpassword);

        Login user{username, userpassword};
        if (user.isPresent())
        {
            return 1; //Give the access to login.
        }
        else
        {
            std::cout << "Sorry, But this username already exists. Try another.";
            sleep(2000);
            commandClear();
            
        }
    }while(true);
    
    return 0;
}

bool registerSystem()
{
    commandClear();
    std::string username{};
    std::string userpassword{};
    
    bool access{0};
    do
    {
        std::cout << "Pls Enter the following: \n\n";
        std::cout << "Username: \n";
        std::getline(std::cin >> std::ws, username);
        std::cout << "Password: \n";
        std::getline(std::cin >> std::ws, userpassword);

        Login user{username, userpassword};
        if (user.isPresent())
        {
            sleep(2000);
            std::cout << "Sorry, But this username already exists. Try another.";
            commandClear();
        }
        else
        {
            return 1;; //Give the access to login.
            break;
        }
    }while(true);
    return 0;
}