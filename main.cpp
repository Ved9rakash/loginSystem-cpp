/*  AUTHOR - Ved9rakash
    Version - 1.0.1

    Login Program : 
    A cpp login program, which checks 
    the user data in "loginCredentials.csv" file.
    Currently 2 basic operation-
    1 - Login
    2 - Register (New User)
*/

#include "signInUp.hpp"

//To call linux system commands.
#include "SystemAnalyser.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <chrono>
#include <thread>
#include <stdlib.h>


void commandClear()
{
    //Using linux command to make screen clear(Like new window is popping up)
    auto system = std::make_unique<SystemAnalyser>();
    system->runCommand("clear");
}


int getChoice()
{   
    //Getting the user choice.
    commandClear();
    std::cout << "Welcome to my c++ Login/Register page\n\n";
    std::cout << "Press: \n1 -> Login\n2 -> Register\n3 -> Exit.\n";
    int choice{0};
    std::cin >> choice;
    return choice;
}


int main()
{
    //User credentials.
    std::string username{};
    std::string password{};
    std::string number{};
    int age{};
    std::string gender{};

    //Checking if credentials are present or not.
    bool loginid = true;

    switch (getChoice())
    {
        case 1:
        //Login Case
            while (loginid)
            {
                commandClear();
                std::cout << "Login\nEnter 'quit' to exit.\n\n";
                std::cout << "Username\n"; std::getline(std::cin >> std::ws, username);
                if (username == "quit")
                    std::exit(0);
                std::cout << "Password\n"; std::getline(std::cin >> std::ws, password);
                //Checking if username is present in database
                if (LoginInUp::isPresent(username) && LoginInUp::passwordCheck(password))
                {
                    std::cout << "XXXXXXthis printing?";
                    //If YES, then check the password if it matches.
                    if (LoginInUp::passwordCheck(password))
                    {   
                        std::cout << "is this printing?\n";
                        loginid = false;
                        break;
                    }
                    else
                        std::cout << "Wrong Password.";
                }
                else
                {
                    std::cout << "Entered wrong credentials" << std::flush;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    commandClear();
                }
            }
            break;
        
        case 2:
        //Register Case
            while(loginid)
            {
                commandClear();
                std::cout << "Register\nEnter 'quit' to exit\n\n";
                std::cout << "Username\n"; std::getline(std::cin >> std::ws, username);
                if (username == "quit")
                    std::exit(0);
                std::cout << "Password\n"; std::getline(std::cin >> std::ws, password);

                //Checking if username is present in database
                if (LoginInUp::isPresent(username))
                {
                    //if YES, then try again.
                    std::cout << "Username already exists, try different name." << std::flush;
                    sleep(1000);
                    commandClear();
                }
                else
                {
                    //Add it in file
                    std::cout << "Enter Mobile number: ";   std::getline(std::cin >> std::ws, number);
                    std::cout << "Enter age: ";             std::cin >> age;
                    std::cout << "Enter gender: ";          std::getline(std::cin >> std::ws, gender);

                    LoginInUp::add(username, password, number, age, gender);

                    loginid = false;
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
    //commandClear();
    std::cout << "Welcome.\n\n";
    std::cout << "Mobile Number - " << login.mobileNumber();
    std::cout << "\nAge           - " << login.age() << '\n';
    std::cout << "Enter 'q' to exit.";
    char choice;
    std::cin >> choice;
    if (choice == 'q')
        std::exit(0);
    return 0;
}