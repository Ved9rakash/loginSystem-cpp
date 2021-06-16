//#include "register.hpp"
//#include "login.hpp"
#include "SystemAnalyser.hpp"

#include <iostream>
#include <string>
#include <memory>

int main()
{
    int num{};
    std::cout << "Welcome to my c++ website.\n\n";
    auto system = std::make_unique<SystemAnalyser>();
    
    do
    {
        std::cout << "Enter the number";
        std::cin >> num;
        std::cout << "\nThis will be deleted."; 
        system->runCommand("clear");
    }while(num != 10);

    return 0;
}