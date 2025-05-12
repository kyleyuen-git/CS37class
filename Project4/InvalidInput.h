#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H

#include <string>
#include <iostream>
using namespace std;  

using namespace std; 

class InvalidInput
{
    const string message;     // constant data member
    public:
        InvalidInput(const string& input) : message("Invalid input \"" + input + "\".\n") { }
        
        void reason() const {
            cout << message <<endl;
        }
};



#endif  // INVALIDINPUT_H