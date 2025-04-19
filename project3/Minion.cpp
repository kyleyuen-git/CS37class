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

int Minion::getBananas() const {
    return bananasOwned;
}

string Minion::getName() const{
    return name;
}

void Minion::printMinionCount() {
    cout << minionCount << " minions created." << endl;
  }

bool Minion::operator>(const Minion& other) const {
    return this->height>other.height;
}

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
