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
        // Constructor: Initializes name, height, eyes, and bananas; increments minionCount
        Minion(string n, float h, int e, int b);

        //getters
        int getBananas() const;
        string getName() const;

        // Static function
        static void printMinionCount();

        // Overloads the > operator to compare minion height
        bool operator>(const Minion& other) const;
        // Overloads the < operator to compare minion height
        bool operator<(const Minion& other) const;

        // Pre-increment: Adds 1 banana and returns updated object
        Minion& operator++();
        // Post-increment: Returns copy of object before adding 1 banana
        Minion operator++(int);
        
        // Friend function to overload the << operator for output
        friend ostream& operator<<(ostream& out, const Minion& m);

};


#endif