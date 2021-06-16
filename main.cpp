#include "signInUp.hpp"
#include "SystemAnalyser.hpp"

#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>
#include <chrono>
#include <thread>

void sleep()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
}

int main()
{
    auto system = std::make_unique<SystemAnalyser>();
    system->runCommand("clear");
    int num{};
    std::cout << "Welcome to my c++ website.\n\n";
    
    sleep();

    do
    {
        std::cout << "Enter the number";
        std::cin >> num;
        std::cout << "\nThis will be deleted."; 
        system->runCommand("ls");
    }while(num != 10);

    return 0;
}