//
//  BusDAO.cpp
//  BusManagement_v3
//
//  Created by Yeow Pann on 23/11/22.
//

#include <iostream>
#include "Bus.cpp"
using namespace std;

class BusDao{
    
public:

    virtual void addBus(Bus* bus) = 0;
    virtual void displayAllBus() = 0;
    virtual int searchBusById(int busNumber) = 0;
    virtual int searchBusByName(string driverName) = 0;
    virtual void modifyBusByID(int busNum) = 0;
    
    virtual void modifyBusByName(string driverName) = 0;
    virtual void deletebusId(int busNumber)= 0;
    virtual void deletebusName(string driverName) = 0;
    virtual Bus* getBusById(int busNumber) = 0;
    virtual Bus* getBusbyName(string driverName) = 0;
};
