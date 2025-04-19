#include "Minion.h"
#include <iostream>
using namespace std;

// Initialize static member
int Minion::minionCount = 0;

// Constructor
Minion::Minion(string n, float h, int e, int b) {
    name = n;
    height = h;
    eyes = e;
    bananasOwned = b;
    minionCount++;  // increase count every time a Minion is created
}

// Returns number of bananas
int Minion::getBananas() const {
    return bananasOwned;
}

// Returns name
string Minion::getName() const{
    return name;
}

// Prints the number of Minion objects created
void Minion::printMinionCount() {
    cout << minionCount << " minions created." << endl;
  }

// Compares height (>)
bool Minion::operator>(const Minion& other) const {
    return this->height>other.height;
}

// Compares height (<)
bool Minion::operator<(const Minion& other) const{
    return this->height<other.height;
}

//pre-increment: ++x
Minion& Minion::operator++(){
    this->bananasOwned++;
    return *this;
}

//post-increment: x++
//uses int as dummy paramenter
Minion Minion::operator++(int){
    Minion temp = *this;
    this->bananasOwned++;
    return temp;
}

ostream& operator<<(ostream& out, const Minion& m) {
    out << "The minion " << m.name
        << " is " << m.height << " inches tall, has "
        << m.eyes << " eye(s), and owns "
        << m.bananasOwned << " banana(s).\n";
    return out;
}
