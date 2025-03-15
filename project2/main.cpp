#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

//function prototypes
float matrix_power(double botDamage[], int botCount, double bossDamage);
// Template function prototype
template <typename T>
T single_missile_power(T power);
void load_dva(double &defenseMatrix, float matrixPowerRequired);
void load_dva(int &missileNum, float missilePowerRequired);

int main(){
    //initialize all variables
    int botCount = 0;
    //botDamage[5] refers to the amount of elements in the array, not the max index
    double botDamage[5];
    double bossDamage = 0.0;
    int missileNum = 0;
    double defenseMatrix = 0.0;
    //declare as float even though single_missile_power can take an int or float. typecast later
    float missilePowerRequired = 0.0;

    //creating and opening file
    ifstream combatFile;
    combatFile.open("combat.txt");
    //check if file opened.
    if (combatFile.fail()){
        cout<<"The file failed to open\n";
        return 0;
    }

    //assign all values in combat.txt to variable values
    //first value detected from combatFile is assigned to botCount and so forth
    combatFile>>botCount;
    //for loop loops through botDamage array from index 0 to 4 which is equivalent to element 1 to 5
    for(int i = 0; i<botCount; i++){
        combatFile>>botDamage[i];
    }
    combatFile>>bossDamage;
    combatFile>>missileNum;
    combatFile>>defenseMatrix;
   
    //close the file when done
    combatFile.close();

    //create and assign matrixPowerRequired to the matrix_power function call
    //when calling a function you don't need the [] for the array parameter
    //matrixPowerRequired initialization needs to be AFTER assigning/reading data from file
    float matrixPowerRequired = matrix_power(botDamage, botCount, bossDamage);

    //calculating missilePowerRequired
    for (int i = 0; i<botCount; i++){
        missilePowerRequired += single_missile_power(botDamage[i]);
    }
    missilePowerRequired += single_missile_power(bossDamage);

    //calls the overloaded load_dva functions to update defenseMatrix and missileNum before printing them out.
    load_dva(defenseMatrix, matrixPowerRequired);
    load_dva(missileNum, missilePowerRequired);
    
    //creates new file of variable name report
    ofstream report;
    //opens variable report as a file named report.txt
    report.open("report.txt");
    //checks if opening report.txt failed. if it did, print "report failed to open" and return 0
    if (report.fail()){
        cout<<"report failed to open";
        return 0;
    }
    //prints out the report
    report<<"D.Va's Combat Report\nCombat with "<<botCount<<" enemy bots and one enemy boss with power "<<bossDamage<<".\nLoaded mech with "<<missileNum<<" micro missiles and the defense matrix with power "<<defenseMatrix<<".\nReady for combat!";
    //closes report.txt
    report.close();
}

//matrix_power adds up the total amount of damage received 
float matrix_power(double botDamage[], int botCount, double bossDamage){
    float totalDamage = 0.0;
    for (int i = 0; i<botCount; i++){
        //type conversion from double to float
        totalDamage += (float)botDamage[i];
    }
    totalDamage += (float)bossDamage;
    return totalDamage;
}

//single_missile_power returns the power of D.Va's micro missile system
template <typename T>
T single_missile_power(T power){
    if (power <= 15){
        return power*3;
    }
    else{
        return power*5;
    }
}

//load_dva updates the defenseMatrix to matrixPowerRequired if it is less than matrixPowerRequired
void load_dva(double &defenseMatrix, float matrixPowerRequired){
    if(defenseMatrix<matrixPowerRequired){
        defenseMatrix = matrixPowerRequired;
    }
}

//load_dva updates the missileNum if it is less than missilePowerRequired/30.0
void load_dva(int &missileNum, float missilePowerRequired){
    int neededMissiles = ceil(missilePowerRequired/30.0);
    if(missileNum<neededMissiles){
        missileNum = neededMissiles;
    }
}