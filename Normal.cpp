//
//  Normal.cpp
//  BusManagement_v3
//
//  Created by Yeow Pann on 16/11/22.
//

#pragma once
#include <iostream>
#include "User.cpp"
using namespace std;

class Normal : public User{
    
private:
    
    string normalsex;
    
public:
    Normal ():User(),normalsex("Unknow"){};
    Normal (int id,string username, string password, string normalsex):
    User (id,username,password),normalsex(normalsex){};
    
    void setuserSex(string normalsex){
        this->normalsex = normalsex;
    }
    string getuserSex(){
        return normalsex;
        
    }
    
    void inputUser(){
        User::inputUser();
        cout <<"\n\t\t\t\tINPUT SEX[F/M]: ";
        cin >> normalsex;
    }
    void outputUser(){
        User::outputUser();
        cout<<"\t\t\t\t\tUSER SEX: "<<normalsex<< endl;
        
        cout << "\n\t\t\t\t----------------------------------------\n";
    }
};

