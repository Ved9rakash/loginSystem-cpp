/*  AUTHOR - Ved9rakash
    Version - 1.0.1

    Login Program : 
    A unix based cpp login program, which checks 
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



void sleep(int milliseconds)
{
    //sleeping the program for x milliseconds to make it more realistic
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
    bool loginid = false;

    switch (getChoice())
    {
        case 1:
        //Login Case
            while (!loginid)
            {
                std::cout << "Login\n\n";
                std::cout << "Username\n"; std::getline(std::cin >> std::ws, username);
                std::cout << "Password\n"; std::getline(std::cin >> std::ws, password);

                //Checking if username is present in database
                if (LoginInUp::isPresent(username))
                {
                    //If YES, then check the password if it matches.
                    if (LoginInUp::passwordCheck(password))
                        loginid = true;
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
            while(!loginid)
            {
                std::cout << "Register\n\n";
                std::cout << "Username\n"; std::getline(std::cin >> std::ws, username);
                std::cout << "Password\n"; std::getline(std::cin >> std::ws, password);

                //Checking if username is present in database
                if (LoginInUp::isPresent(username))
                {
                    //if YES, then try again.
                    std::cout << "Username already exists, try different name.";
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
                    loginid = true;
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
    commandClear();
    std::cout << "Welcome.\n\n";
    std::cout << "Mobile Number - " << login.mobileNumber();
    std::cout << "\nAge           - " << login.age() << '\n';

    return 0;
}