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