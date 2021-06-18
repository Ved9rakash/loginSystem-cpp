#include "signInUp.hpp"
#include "SystemAnalyser.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <fstream>

void sleep(int milliseconds)
{
    //sleeping the program to make it more realistic
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}


void commandClear()
{
    //Using linux command to make screen clear(Like new window is popping up)
    auto system = std::make_unique<SystemAnalyser>();
    system->runCommand("clear");
}

int getChoice()
{
    std::cout << "Welcome to my c++ Login/Register page\n\n";
    std::cout << "Press: \n1 -> Login\n2 -> Register\n3 -> Exit.\n";
    int choice{0};
    std::cin >> choice;
    return  choice;
}

int main()
{
    std::string username{};
    std::string password{};

    commandClear();
    bool loginid = false;
    switch (getChoice())
    {
        case 1:
            while (!loginid)
            {
                std::cout << "Login\n\n";
                std::cout << "Username\n"; std::getline(std::cin >> std::ws, username);
                std::cout << "Password\n"; std::getline(std::cin >> std::ws, password);
                if (LoginInUp::isPresent(username, password))
                {
                    loginid = true;
                }
                else
                {
                    std::cout << "Entered wrong credentials";
                    sleep(1000);
                    commandClear();
                }
            }
            break;
        
        case 2:
            while(!loginid)
            {
                std::cout << "Register\n\n";
                std::cout << "Username\n"; std::getline(std::cin >> std::ws, username);
                std::cout << "Password\n"; std::getline(std::cin >> std::ws, password);
                if (!LoginInUp::isPresent(username, password))
                {
                    loginid = true;
                }
                else
                {
                    std::cout << "Username already exists, try different name.";
                    sleep(1000);
                    commandClear();
                }
            }
            


            break;

        case 3:
            std::cout << "Exiting the window.";
            commandClear();
            std::exit(0);
            break;
        
        default:
            std::cerr << "Random Value/Charater entered. Exiting.";
            sleep(2000);
            std::exit(1);
    }

    LoginInUp login{username, password};
    std::cout << "Welcome.\n\n";
    std::cout << "Mobile Number - " << login.mobileNumber();
    std::cout << "Age           - " << login.age();

    return 0;
}