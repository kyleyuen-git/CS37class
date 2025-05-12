#include "BobaOrder.h"
#include <iomanip> 

//constructor
BobaOrder::BobaOrder(const string& n, const string& d, const string& p, float m, const string& shop)
: DeliveryOrder(n, d, p, m), shopName(shop), drinksCount(0){
}

//destructor
BobaOrder::~BobaOrder()
{
    cout << "BobaOrder destroyed.\n";
}

//overriding receipt function
void BobaOrder::receipt() const
{
    //Have your code stay DRY in the receipt() function of the DeliveryOrder class
    DeliveryOrder::receipt();
    cout << "\tDrinks Count: " << drinksCount << endl;
}

//overridng VIPdiscount() - const because it doesn't modify order, it just returns a multiplier
float BobaOrder::VIPdiscount() const
{
    if (drinksCount > 10) return 0.8f;
    if (drinksCount > 5)  return 0.9f;
    if (drinksCount > 2)  return 0.95f;
    return 1.0f;
}

//addDrink()
void BobaOrder::addDrink(const string& drink,
    bool addBoba,
    int  count)
{
    float pricePerDrink = 0.0f;

    if (drink == "Green Tea Latte")         pricePerDrink = 5.8f;
    else if (drink == "Brown Sugar Boba Milk")  pricePerDrink = 7.8f;
    else if (drink == "Brown Sugar Pearl Milk") pricePerDrink = 9.8f;
    else
    //If the drink name doesn't match any of the available drinks, throw the InvalidInput exception.
    throw InvalidInput(drink);

    if (addBoba) pricePerDrink += 1.0f;

    float subtotal = pricePerDrink * count;

    //orderBalance was a protected member from base
    orderBalance += subtotal;
    drinksCount  += count;
}