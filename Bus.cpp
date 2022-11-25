//
//  Bus.cpp
//  BusManagement_v3
//
//  Created by Yeow Pann on 14/11/22.
//
#pragma once
#include <iostream>
using namespace std;

class Bus{
    
private:
    
    int _busNumber;
    string _driverName;
    string _departureTime;
    string _arrivalTime;
    string _from;
    string _to;
    int count = 0;
    
public:
    
    Bus():_busNumber(0),_driverName("Unknow"),_departureTime("Unknow"), _arrivalTime("Unknow"),_from("Unknow"),_to("Unknow"){}
    Bus (int _busNumber, string _driverName, string _departureTime, string _arrivalTime, string _from, string _to): _busNumber(_busNumber),_driverName(_driverName),_departureTime(_departureTime),_arrivalTime(_arrivalTime),_from(_from),_to(_to){}
    ~Bus (){}
    
    void setBusNumber(int _busNumber){
        if(_busNumber < 0){
            
            throw "\n\t\t\t\tINVALID INPUT\n";
           
            
        }
        else{
            this->_busNumber = _busNumber;
        }
        
    }
    int getBusNumber(){
        return _busNumber;
    }
    
    void setDriverName(string _driverName){
        this-> _driverName = _driverName ;
        
    }
    
    string getDriverName(){
        return _driverName;
    }
    void setDepartureTime(string _departureTime){
        this-> _departureTime = _departureTime;
    }
    string getDepartureTime(){
        return _departureTime;
    }
    void setArrivalTime(string _arrivalTime){
        this-> _arrivalTime = _arrivalTime;
    }
    string getArrivalTime(){
        return _arrivalTime;
    }
    void setTo(string _to){
        this-> _to = _to;
    }
    string getTo(){
        return _to;
    }
    void setFrom(string _from){
        this-> _from = _from;
    }
    string getFrom(){
        return _from;
    }
    virtual void outputbeforeedit(){
        
        cout << "\n\n.......Diplay Result Before Modify......\n";
        
        for (int i=50;i>0;i--)

        cout<<'-';

        cout <<"\nBus ID : "<< _busNumber<<endl;
        cout <<"\nDriver's Name : "<< _driverName<<endl;
        cout <<"\nDeparture Time : "<< _departureTime<<endl;
        cout <<"\nArrival Time : "<<_arrivalTime<<endl;;
        cout <<"\nFrom Station : "<<_from<<endl;
        cout <<"\nTo Station : "<<_to<<endl;
        for (int i=50;i>0;i--)
        cout<<'-';
    }
    
    virtual void inputBus()
    {
        
        cout << "\n\t\t--------------- FILL BUS INFORMATION ---------------\n";
        
        cout << "\nInput Bus Number: ";
        
        cin >> _busNumber;

        cout << "\nInput Driver's Name: ";
        
        cin >> _driverName;
        
        cout << "\nInput Departure Time: ";
        
        cin >> _departureTime;
        
        cout << "\nInput Arrive Time: ";
        
        cin >> _arrivalTime;
        
        cout << "\nFrom: \t\t\t";
        
        cin >> _from;
        
        cout << "\nTo: \t\t\t";
        
        cin >> _to ;
    }
    
    virtual void outputBus(){
        
        cout << "\n\n\t\t\t.......Bus Details......\n";
        
        cout<<"\nBUS NO: \t"<<_busNumber<<"\n";
        for (int i=60;i>0;i--)

        cout<<'-';

        cout <<"\nDRIVER: \t"<<_driverName<<"  \tDEPARTURE TIME: "

        <<_departureTime<<"\t\tARRIVAL TIME: \t"<<_arrivalTime

        <<"\nFROM: \t\t"<<_from<<"\t\tTO: \t\t"<<

        _to<<"\n";
        for (int i=60;i>0;i--)

        cout<<'-';
        
        cout << endl << endl;
       
    }
    
    
};



