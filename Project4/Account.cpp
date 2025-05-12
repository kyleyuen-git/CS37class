#include "Account.h"

// Constructor
Account::Account(const string& user, const string& stat)
    : username(user), status(stat) { }

// Destructor
Account::~Account()
{
    cout << "Account removed.\n";
}

// Getter does not modify object, so const
const string& Account::getStatus() const
{
    return status;
}
