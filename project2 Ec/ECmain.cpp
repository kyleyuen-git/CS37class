#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

#include "DvaClasses.h"
int main() {

    //Open file
    ifstream combatFile("combat.txt");
    if (combatFile.fail()) {
        cout << "File fail to open." << endl;
        return 0;
    }

    //Read battle info from file
    int botsCount;
    float bossPower;
    combatFile >> botsCount;
    int* botsPower = new int[botsCount];
    for (int i=0; i<botsCount; i++) {
        combatFile >> botsPower[i];
    }
    combatFile >> bossPower;

    //Initialize battle and dva
    Battle dvaBattle(botsCount, bossPower, botsPower);
    Mech dva;

    //Calculate power needed
    float matrixPowerRequired = dvaBattle.matrix_power();
    float missilePowerRequired = dva.micro_missile(dvaBattle);

    //Load D.Va
    dva.load(matrixPowerRequired, missilePowerRequired);

    //Write combat report to file
    ofstream report("report.txt");
    if (report.fail()) {
        cout << "Fail to open file.";
        return 0;
    }
    report << "D.Va's Combat Report" << endl;
    report << "Combat with " << botsCount << " enemy bots and one enemy boss with power " << bossPower << ".\n";
    report << "Loaded mech with " << dva.get_missiles() << " micro missiles and the defense matrix with power " << dva.get_defenseMatrix() << ".\n";
    report << "Ready for combat!";
    report.close();
    
    delete[] botsPower;
    return 0;
}
