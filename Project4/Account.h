#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>

using namespace std;

class Account
{
    private:
        string username;
        // "Regular" (default), "VIP", or "Owner"
        string status;            

    public:
        Account(const string& user, const string& stat = "Regular");
        ~Account();

        // getter: read‑only, so mark const
        const string& getStatus() const;
};

#endif
