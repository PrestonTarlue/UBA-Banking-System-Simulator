
#include <iostream>
#include <map>
#include <string>
#include <fstream>

std::map<std::string, double> accounts;

void SaveData() {
    std::ofstream outfile("accounts.txt", std::ios::trunc); 
    if (outfile.is_open()) {
        for (auto const& [name, balance] : accounts) {
            outfile << name << ":" << balance << std::endl;
        }
        outfile.close();
    } else {
        std::cout << "Error: Could not save data to file." << std::endl;
    }
}

void AddMoney()
{

    std::string name;
    std::cout << "Enter Your Name: ";
    std::getline(std::cin, name);
    if (accounts.find(name) != accounts.end())
    {
        double amount;
        std::cout << "Enter The Amount you Want to Deposit: ";
        std::cin >> amount;
        std::cin.ignore();
        accounts[name] += amount;
        SaveData();
        std::cout << "Deposit Successful! Your New Balance is: " << accounts[name] << std::endl;
        std::cout << "   Thanks for Trusting the Bank" << std::endl;
    }
    else
    {
        std::cout << " Sorry " << name << " Is not In the System try Reaching out to the Bank  " << std::endl; 
    }
};

void withdrawMoney()
{
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    if (accounts.find(name) != accounts.end())
    {
        double amount;
        std::cout << " Enter the amount you want to withdraw :";
        std::cin >> amount;
        std::cin.ignore();
        if (accounts[name] >= amount)
        {
            accounts[name] -= amount;
            SaveData();
            std::cout << "Withdrawal Successful! your New Balance is: " << accounts[name] << '\n'<< std::endl;
            std::cout << "   Thanks for Trusting the Bank" << std::endl;
        }
        else
        {
                std::cout << "Error Openning File, Please Call The Support Team (+231 000 000 000)" << std::endl;
        }

    } 
}


void CheckBalance()
{
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    if (accounts.find(name) != accounts.end())
    {
        std::cout << "Your Balance is: " << accounts[name] << std::endl;
    }
    else
    {
        std::cout << " sorry " << name << " is not in the System try Reaching out to the Bank " << std::endl;
    }
}


int main()
{
    accounts["John Doe"] = 0.0;
    accounts["James smith"] = 0.0;
    while (true)
    {
    std::cout << " Welcome to UBA Banking System " << std::endl;
    std::cout << " 1. Add Money" << std::endl;
    std::cout << " 2. Withdraw Money " << std::endl;
    std::cout << " 3. Check Balance" << std::endl;
    std::cout << " 4. Exit" << std::endl;
    std::cout << std::endl;
    std::cout << " Please Select an Options ";
    int option;
    std::cin >> option;
    std::cin.ignore();
    switch (option)
    {
        case 1:
        AddMoney();
        break;
        case 2:
        withdrawMoney();
        break;
        case 3:
        CheckBalance();
        break;
        case 4:
        std::cout << " Thanks for Working With UBA Bank " << std::endl;
        exit(0);
        break;
        default:
        std::cout << " Invalid Option, Please Enter a Valid Option " << std::endl;
    }
    }
    
    return 0;

}