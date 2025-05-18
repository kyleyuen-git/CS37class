#include "p1.h"
#include <iostream>

int main(){
    YoutubeChannel Kyle;
    cout<<"how many subs does Kyle have? ";
    cin>>Kyle.subscribers;
    cin.ignore();
    cout<<"what is the name of Kyle's channel? ";

    getline(cin, Kyle.channelName);
    // Kyle.channelName = "Kyle's World";

    Kyle.info();
}