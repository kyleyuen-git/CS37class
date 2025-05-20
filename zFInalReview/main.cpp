#include "p1.h"
#include <iostream>
#include <fstream>
#include <iomanip>

inline int add(int *x, int y, int z=10){
    // return *x + y + z;
    *x = *x + y + z;
    return *x;
}

void subtract(const int* x){
    // *x-=10;
    // return *x;
    cout<<*x;
}

int main(){
    const int y = 50;
    const int* x = &y;
    subtract(x);
    // cout<<subtract(x);
}