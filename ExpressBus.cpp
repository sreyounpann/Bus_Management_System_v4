//
//  ExpressBus.cpp
//  BusManagement_v3
//
//  Created by Yeow Pann on 15/11/22.
//

#pragma once
#include<iostream>
#include "Bus.cpp"
using namespace std;

class ExpressBus : public Bus
{
    private :
    
    int exseat;
public:
    ExpressBus():Bus(),exseat(0){}
    ExpressBus(int busNumber, string driverName, string departureTime, string arrivalTime, string to, string from, int exseat):
    Bus (busNumber,driverName,departureTime,arrivalTime,to,from),exseat(exseat){};
    
    void setExseat(int exseat){
        this-> exseat = exseat;
    }
    int getExseat(){
        return exseat;
        
    }
    
    void inputBus()
    {
        Bus::inputBus();
        cout <<"\nInput Amount of Seat Express Bus : ";
        cin >> exseat;
        
    }
    void outputBus(){
        Bus::outputBus();
        cout <<"Amount of Express Bus Seat : "<< exseat<< endl;
    }
};


