//
//  Admin.cpp
//  BusManagement_v3
//
//  Created by Yeow Pann on 16/11/22.
//

#pragma once
#include <iostream>
#include "User.cpp"
using namespace std;

class Admin : public User{
    
private:
    
    string adminsex;
    
public:
    Admin ():User(),adminsex("Unknow"){};
    Admin (int id,string username, string password, string adminsex):
    User (id,username,password),adminsex(adminsex){};
    
    void setadminsex(string adminsex){
        this->adminsex = adminsex;
    }
    string getadminsex(){
        return adminsex;
        
    }
    
    void inputUser(){
        User::inputUser();
        cout <<"\n\t\t\t\tINPUT SEX[F/M]: ";
        cin >> adminsex;
    }
    void outputUser(){
        User::outputUser();
        cout<<"\n\t\t\t\t\tSEX: "<<adminsex<<endl;
        
        cout << "\n\t\t\t\t----------------------------------------\n";
    }
};



