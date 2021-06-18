#include "signInUp.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//Constructor
LoginInUp::LoginInUp(std::string name, std::string password)
{
    m_userName = name;
    m_userPassword = password;

    std::fstream fin;
    fin.open("loginCredentials.csv", std::ios::in);

    int rollnum, roll2, count = 0;
    std::cout << "Enter the roll number "
         << "of the student to display details: ";
    std::cin >> rollnum;
  
    // Read the Data from the file
    // as String Vector
    std::vector<std::string> row;
    std::string line, word, temp;
  
    while (fin >> temp) {
  
        row.clear();
  
        // read an entire row and
        // store it in a string variable 'line'
        std::getline(fin, line);
  
        // used for breaking words
        std::stringstream s(line);
  
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (std::getline(s, word, ', ')) {
  
            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }
  
        // convert string to integer for comparision
        roll2 = stoi(row[0]);
  
        // Compare the roll number
        if (roll2 == rollnum) {
  
            // Print the found data
            count = 1;
            std::cout << "Details of Roll " << row[0] << " : \n";
            std::cout << "Name: " << row[1] << "\n";
            std::cout << "Maths: " << row[2] << "\n";
            std::cout << "Physics: " << row[3] << "\n";
            std::cout << "Chemistry: " << row[4] << "\n";
            std::cout << "Biology: " << row[5] << "\n";
            break;
        }
    }
    if (count == 0)
        std::cout << "Record not found\n";
}
//Checking is the username is already present or not
bool LoginInUp::isPresent(std::string name, std::string password)
{

}

// //Checking if the username is present or not
// bool LoginInUp::isPresent(std::string name)
// {

// }

//Adding new credentials in logincredentails.csv file
void LoginInUp::add(std::string name, std::string password)
{

}

//Getting age
int LoginInUp::age()
{

}

//Getting Mobile Number
int LoginInUp::mobileNumber()
{

}