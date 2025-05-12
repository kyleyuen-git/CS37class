#include "FoodOrder.h"
#include <iomanip>

//Constructor
FoodOrder::FoodOrder(const string& n, const string& d, const string& p, float m, const string& restaurant)
    : DeliveryOrder(n, d, p, m), restaurantName(restaurant), foodCount(0){
        
    }

//destructor
FoodOrder::~FoodOrder()
{
    cout << "FoodOrder destroyed.\n";
}

//override receipt()
void FoodOrder::receipt() const
{
    DeliveryOrder::receipt();
    cout << "\tFood Count: " << foodCount << endl;
}

//override VIPdiscount()
float FoodOrder::VIPdiscount() const
{
    if (orderBalance > 50.0f) return 0.8f;
    if (orderBalance > 30.0f) return 0.9f;
    if (orderBalance > 20.0f) return 0.95f;
    return 1.0f;
}


/* ───────────────────────────────────────────────
   5.  addFood()
       • Look up main‑dish price
       • +$5 if soup, +$6×sides
       • Update orderBalance & foodCount
       • Throw InvalidInput if meal not on menu
   ─────────────────────────────────────────────── */

void FoodOrder::addFood(const string& meal, int sides, bool soup)
{
    float price = 0.0f;

    if(meal == "Thick Cauliflower Steaks")
        price = 15.0f;
    else if (meal == "Rack of Lamb")
        price = 38.0f;
    else if (meal == "Organic Scottish Salmon")
        price = 23.0f;
    else if (meal == "Grilled Lobster Risotto")
        price = 46.0f;
    else
        throw InvalidInput(meal);

    if(soup == true)
        price += 5.0f;
    else 
        price += 0.0f;

    price += 6.0f * sides;

    //orderBalance from protected in DeliveryOrder.h
    orderBalance += price; 
    ++foodCount;
}
