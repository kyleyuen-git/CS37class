#include "Minion.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    //1. Read file
    string minionsFileName = "minions.txt";
    ifstream minionsFile(minionsFileName);

    //Check file
    if (minionsFile.fail()) {
        cout << "File failed to open." << endl;
        return 0;
    }

    //Initialize minion with name, height, eyes, and bananasOwned.
    string name;
    float height;
    int eyes;
    int bananas;

    minionsFile >> name >> height >> eyes >> bananas;
    const Minion minion1(name, height, eyes, bananas);

    minionsFile >> name >> height >> eyes >> bananas;
    Minion minion2(name, height, eyes, bananas);

    minionsFile >> name >> height >> eyes >> bananas;
    Minion minion3(name, height, eyes, bananas);

    //2. Compare height
    //Find the taller minion
    if (minion1 > minion2) {
        cout << minion1.getName() << " is taller than " << minion2.getName();
    } 
    if (minion2 < minion3) {
        cout << minion3.getName() << " is taller than " << minion2.getName();
    }
    cout << endl << endl;

    //3. Get bananas
    cout << minion2;
    cout << minion2.getName() << " getting bananas.\n";
    cout << "The minion now has " << (++(++minion2)).getBananas() << " banana(s).\n" << endl;

    //overloaded insertion operator to print out the info for Minion3
    //Followed by a statement indicating minion3 is also getting bananas
    //Minion3 will then get one banana with post increment
    cout << minion3;
    cout << minion3.getName() << " getting bananas.\n";
    cout << "Before getting bananas, the minion had " << minion3++.getBananas() << " banana(s).\n";
    cout << "After getting bananas, the minion has " << minion3.getBananas() << " banana(s).\n" << endl;

    //4. Get minion count
    Minion::printMinionCount();
}