#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//function prototypes
float matrix_power(double botDamage[], int botCount, double bossDamage);
// Template function prototype
template <typename T>
T single_missile_power(T power);


int main(){
    //initialize all variables
    int botCount = 0;
    //botDamage[5] refers to the amount of elements in the array, not the max index
    double botDamage[5];
    double bossDamage = 0.0;
    int missleNum = 0;
    double defenseMatrix = 0.0;
    //declare as float even though single_missile_power can take an int or float. typecast later
    float missilePowerRequired = 0;

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
    for(int i = 0; i<=4; i++){
        combatFile>>botDamage[i];
    }
    combatFile>>bossDamage;
    combatFile>>missleNum;
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

    //prints out all the information collected from the file and stored in the variables
    cout<<"Bot count: "<<botCount<<"\n";
    cout<<"Bot damages: ";
    for(int i = 0; i<=4; i++){
        cout<<botDamage[i]<<" ";
    }
    cout<<"\n";
    cout<<"Boss damage: "<<bossDamage<<"\n";
    cout<<"Missle number: "<<missleNum<<"\n";
    cout<<"Defense Matrix: "<<defenseMatrix<<"\n";

    cout<<"Matrix Power Required: "<<matrixPowerRequired<<"\n";
    cout<<"Missile Power Required: "<<missilePowerRequired<<"\n";
    

}

float matrix_power(double botDamage[], int botCount, double bossDamage){
    float totalDamage = 0.0;
    for (int i = 0; i<botCount; i++){
        //type conversion from double to float
        totalDamage += (float)botDamage[i];
    }
    totalDamage += (float)bossDamage;
    return totalDamage;
}

template <typename T>
T single_missile_power(T power){
    if (power <= 15){
        return power*3;
    }
    else{
        return power*5;
    }
}