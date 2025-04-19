#ifndef MINION_H
#define MINION_H

#include <iostream>
#include <string>
using namespace std;

class Minion{
    private:
        string name;
        float height;
        int eyes;
        int bananasOwned;
        static int minionCount;

    public:
        Minion(string n, float h, int e, int b);

        //getters
        int getBananas() const;
        string getName() const;

        // Static function
        static void printMinionCount();

        
};

#endif