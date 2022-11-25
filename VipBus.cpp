//
//  VipBus.cpp
//  BusManagement_v3
//
//  Created by Yeow Pann on 15/11/22.
//
#pragma once
#include<iostream>
#include "Bus.cpp"
using namespace std;

class VipBus : public Bus
{
    private :
    
    int vipseat;
public:
    VipBus():Bus(),vipseat(0){}
    VipBus(int busNumber, string driverName, string departureTime, string arrivalTime, string to, string from, int vipseat):
    Bus (busNumber,driverName,departureTime,arrivalTime,to,from),vipseat(vipseat){};
    
    void setvipSeat(int vipseat){
        this-> vipseat = vipseat;
    }
    int getvipSeat(){
        return vipseat;
        
    }
    
    void inputBus()
    {
        Bus::inputBus();
        cout <<"\nInput Amount of Seat VIP Bus : ";
        cin >> vipseat;
        
    }
    void outputBus(){
        Bus::outputBus();
        cout <<"Amount of VIP Bus Seat: "<< vipseat<< endl;
    }
};

