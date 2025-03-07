#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

// This struct stores user info: username, country, age, and accountBalance
struct userAccount{
    std::string username;
    std::string country;
    int age;
    double accountBalance;
};

int main() {
    //userAccount tracks 30 user inputs into arrays
    userAccount accounts[30];
    int userCount = 0;
    double BalanceMax = 0;
    double BalanceSum = 0;
    int Haiti = 0;
    bool under21 = false;

    std::cout << "Please enter information to database in the format of <username> <country> <age> <accountBalance>, separated each user by a newline:\n";

    //updates userCount into a number that the for loop can use as an upper bound to loop through only accounts that are within the 30 entries limit and have an actual input instead of just being garbage
    while (userCount < 30 && (std::cin >> accounts[userCount].username
                             >> accounts[userCount].country
                             >> accounts[userCount].age
                             >> accounts[userCount].accountBalance))
    {
        userCount++;
    }
    
    for(int i = 0; i<userCount; i++)
    {
        //updates max balance
        double BalanceCurrent = accounts[i].accountBalance;
        if(BalanceCurrent>BalanceMax){
            BalanceMax = BalanceCurrent;
        }
        // Keep track of sum of balances
        BalanceSum += BalanceCurrent;
        // Count how many come from Haiti
        if(accounts[i].country == "Haiti"){
            Haiti++;
        }
        // Check if anyone is under 21
        if(accounts[i].age<21){
            under21 = true;
        }
    }
    // Output the results
    std::cout<<"Q: What is the highest account balance among all users?"<<"\n";
    std::cout<<"A: $"<<std::fixed<<std::setprecision(1)<<BalanceMax<<"\n\n";
    std::cout<<"Q: What's the sum of account balance of all users?"<<"\n";
    std::cout<<"A: $"<<std::fixed<<std::setprecision(2)<<BalanceSum<<"\n\n";
    std::cout<<"Q: How many users come from Haiti?"<<"\n";
    std::cout<<"A: "<<Haiti<<"\n\n";
    std::cout<<"Q: Do we have any user younger than 21?"<<"\n";
    std::cout << "A: " << (under21 ? "Yes" : "No") << std::endl;
    return 0;
}
