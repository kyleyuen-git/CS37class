#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// ABSTRACT base class
class DeliveryOrder{ 
    private:
        string name, date, phone;
        float miles;

        //class‑scope (shared)
        static int orderCount;      
        static const float taxRate;   
        static const float deliveryRate;

    // derived classes may UPDATE this
    protected:
        float orderBalance;

    public: 
        //constructor
        DeliveryOrder(const string& n, const string& d, const string& p, float m);

        //The virtual destructor will output "DeliveryOrder destroyed.\n".
        virtual ~DeliveryOrder();

        //virtual because it will be overriden by the BobaOrder class
        virtual void receipt() const;
        float getTotalBalance() const;
        static int getOrderCount();

        //pure virtual to force all derived classes to override float VIPdiscount() 
        //makes the Delivery Class an abstract class because it has at least one pure virtual function 
        virtual float VIPdiscount() const = 0;

};

#endif