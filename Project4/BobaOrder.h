#ifndef BOBAORDER_H
#define BOBAORDER_H

#include "DeliveryOrder.h"   // base class
#include "InvalidInput.h"
#include <string>
#include <iostream>

using namespace std;

class BobaOrder : public DeliveryOrder{

    private:
        string shopName;
        int drinksCount = 0;
    
    public:
        // Constructor: forwards common params to DeliveryOrder, plus shop name
        BobaOrder(const string& n, const string& d, const string& p, float m, const string& shop);

        // Destructor prints "BobaOrder destroyed.\n"
        virtual ~BobaOrder();

        //Overrides from DeliveryOrder
        virtual void receipt() const;
        virtual float VIPdiscount() const;

        //BobaOrder also has a new function addDrink()
        void addDrink(const string& drink, bool addBoba = true, int count = 1);
};

#endif