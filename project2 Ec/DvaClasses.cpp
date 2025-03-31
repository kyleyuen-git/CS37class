#include "DvaClasses.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

// ------------------ BATTLE CLASS IMPLEMENTATION ------------------

// constructor
Battle::Battle(int botsCount, float bossPower, int* botsPower) {
    this->botsCount = botsCount;
    this->bossPower = bossPower;
    // for (int i=0; i<botsCount; i++) {
    //     this->botsPower[i] = botsPower[i];
    // }
    copy_n(botsPower, botsCount, this->botsPower);
    }

float Battle::matrix_power() {
    float totalDamage = 0.0f;

    // Sum up all bot powers
    for (int i = 0; i < this->botsCount; i++) {
        totalDamage += this->botsPower[i];  // each is an int
    }

    // Add in the boss power
    totalDamage += this->bossPower;
    return totalDamage;  // return the float total
}


// ------------------ MECH CLASS IMPLEMENTATION ------------------

// 1) Mech constructor
Mech::Mech() {
    this->defenseMatrix = 100.0;
    this->microMissiles = 10;
}

// 2) micro_missile function
//CANNOT USE "this->" because using b.botsPower[i] and b.bossPower, which belong to the Battle object, not the current Mech object
float Mech::micro_missile(const Battle& b) {
    // sum up 3 * each bot power, plus 5 * boss power
    float total = 0.0f;
    for (int i = 0; i < b.botsCount; i++) {
        total += 3.0f * b.botsPower[i];
    }
    total += 5.0f * b.bossPower;
    return total;
}

// 3) load function
void Mech::load(float matrixPowerRequired, float missilePowerRequired) {
    // if we need more defense
    if (this->defenseMatrix < matrixPowerRequired) {
        this->defenseMatrix = matrixPowerRequired;
    }

    // compute how many missiles needed
    int neededMissiles = (int)ceil(missilePowerRequired / 30.0f);
    if (this->microMissiles < neededMissiles) {
        this->microMissiles = neededMissiles;
    }
}

// 4) gettter functions
double Mech::get_defenseMatrix() const {
    return this->defenseMatrix;
}

int Mech::get_missiles() const {
    return this->microMissiles;
}