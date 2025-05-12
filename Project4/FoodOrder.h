#ifndef FOODORDER_H
#define FOODORDER_H

#include "DeliveryOrder.h"
#include "InvalidInput.h"
#include <string>
#include <iostream>

using namespace std;

class FoodOrder: public DeliveryOrder{
    //how do you know to set these two members as private?
    //keep everything private unless derived classes truly need it
    private:
        string restaurantName;
        int foodCount = 0;
    
    public:
    //constructor
    FoodOrder(const string& n, const string& d, const string& p, float m, const string& restaurant);

    //destructor
    //why is this virtual?
    //Any time you delete an object through a base‑class pointer, 
    //you need the base destructor to be virtual so the derived destructor runs first.
    virtual ~FoodOrder();

    //overrides
    virtual void  receipt() const;
    virtual float VIPdiscount() const;  

    //FoodOrder also has a new function addFood() 
    void addFood(const string& meal, int  sides = 0, bool soup  = false);
};

#endif 