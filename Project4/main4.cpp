#include <iostream>
#include <iomanip>
#include "InvalidInput.h"
#include "DeliveryOrder.h"
#include "BobaOrder.h"
#include "FoodOrder.h"
#include "Account.h"

using namespace std;

//prototype for non-member function applyDiscount
float applyDiscount(DeliveryOrder* orderPtr, const Account& acct);


int main() {
    cout << fixed << setprecision(2);

    /* 1.  Accounts (declared first so destructors run last) */
    const Account stuartAcc("Stuart", "Owner");
    Account       kevinAcc ("Kevin",  "VIP");
    Account       bobAcc   ("Bob");                 // default "Regular"

    /* Pointer for polymorphism */
    DeliveryOrder* orderPtr = nullptr;

    /* ----------------------------------------------------- */
    /* Kevin’s Boba order */
    cout << "Kevin is placing order.\n";

    BobaOrder kevinOrder("Kevin", "04/20/2024", "123-456-0000",
                         10.4f, "M Tea");

    try {
        kevinOrder.addDrink("Green Tea Latte");              // default boba,1
        kevinOrder.addDrink("Brown Sugar Pearl Milk", false);
        kevinOrder.addDrink("Brown Sugar Boba Milk", false, 2);
        kevinOrder.addDrink("Iron Goddess");                 // will throw
    }
    catch (const InvalidInput& e) {
        e.reason();                                          // prints line
        cout << "\nNot serving requested drinks. Drink order ignored.\n\n";
    }

    kevinOrder.receipt();
    cout << "Balance: $" << kevinOrder.getTotalBalance() << "\n";

    orderPtr = &kevinOrder;
    cout << "Discounted Balance: $" << applyDiscount(orderPtr, kevinAcc)
         << "\n\n\n";

    /* ----------------------------------------------------- */
    /* Stuart’s Food order */
    cout << "Stuart is placing order.\n";

    FoodOrder stuartOrder("Stuart", "04/20/2024", "123-456-1111",
                          25.5f, "Tavern Green");

    try {
        stuartOrder.addFood("Thick Cauliflower Steaks", 1, true);
        stuartOrder.addFood("Organic Scottish Salmon");
        stuartOrder.addFood("Rack of Lamb", 0, true);
    }
    catch (const InvalidInput& e) {
        e.reason();
        cout << "\nNot serving requested food. Food order ignored.\n\n";
    }

    stuartOrder.receipt();
    cout << "Balance: $" << stuartOrder.getTotalBalance() << "\n";

    orderPtr = &stuartOrder;
    cout << "Discounted Balance: $" << applyDiscount(orderPtr, stuartAcc)
         << "\n\n\n";

    /* ----------------------------------------------------- */
    /* Bob re‑uses Stuart’s order */
    cout << "Bob decided to log in to his account and see whether he can "
            "afford ordering the same order as Stuart.\n";

    stuartOrder.receipt();
    cout << "Balance: $" << stuartOrder.getTotalBalance() << "\n";

    orderPtr = &stuartOrder;
    cout << "Discounted Balance: $" << applyDiscount(orderPtr, bobAcc)
         << "\n";

    cout << "Bob upset, cancelling order :(\n\n";

    /* Final tally */
    cout << "Total order placed: "
         << DeliveryOrder::getOrderCount() << "\n\n";
    return 0;
}

float applyDiscount(DeliveryOrder* orderPtr, const Account& acct)
{
    // 1.  Get the un‑discounted total (tax + delivery already included)
    float total = orderPtr->getTotalBalance();

    // 2.  Branch on account status
    const string& status = acct.getStatus();

    if (status == "Owner") {
        // 90 % off which means pay  10 %
        return total * 0.1f;
    }
    else if (status == "VIP") {
        /* dynamic binding:
           orderPtr->VIPdiscount() finds the *overridden* version in
           BobaOrder or FoodOrder thanks to the virtual keyword. */
        return total * orderPtr->VIPdiscount();
    }
    else { // "Regular" or anything else
        return total;// pay full price
    }
}
