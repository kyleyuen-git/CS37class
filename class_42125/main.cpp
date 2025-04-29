#include <iostream>
#include <string>
using namespace std;

void multiply(int &number){
    number=number*300;
}

int main(){
    int x = 10;
    int* Student = &x;
    cout<<*Student<<" "<<Student<<"\n";

    multiply(x);
    cout<<x;

}