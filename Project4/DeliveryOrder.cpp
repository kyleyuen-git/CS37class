#include "DeliveryOrder.h"
#include <iostream>            
#include <iomanip> 

int DeliveryOrder::orderCount = 0;
// 9 % sales tax
const float DeliveryOrder::taxRate = 0.09f;
// $2 per mile
const float DeliveryOrder::deliveryRate = 2.0f;

//initialization list slide 834
DeliveryOrder::DeliveryOrder(const string& n,const string& d,const string& p,float m)
: name(n), date(d), phone(p), miles(m), orderBalance(0.0f){
    ++orderCount;
}

//The destructor will output "DeliveryOrder destroyed.\n".
DeliveryOrder::~DeliveryOrder()
{
    cout << "DeliveryOrder destroyed.\n";
}

//function receipt that will be overriden
void DeliveryOrder::receipt() const
{
    cout << "Order Detail:\n"
         << "\tName: "  << name  << "\n"
         << "\tDate: "  << date  << "\n"
         << "\tPhone: " << phone << "\n"
         << "\tOrder Balance: $"
         << fixed << setprecision(2)
         << orderBalance << endl;
}

float DeliveryOrder::getTotalBalance() const
{
    return orderBalance * (1 + taxRate) + miles * deliveryRate;
}

int DeliveryOrder::getOrderCount()
{
    return orderCount;
}

//no function definition for virtual float VIPdiscount() const because it is virtual 