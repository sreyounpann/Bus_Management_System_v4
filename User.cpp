//
//  User.cpp
//  BusManagement_v3
//
//  Created by Yeow Pann on 15/11/22.
//

#pragma once
#include <iostream>
using namespace std;

class User {
private:
    string username ;
    string password ;
    int id;

public:
    User() :id(0),username("Unknown"), password("Unknown"){}
    User(int id, string username, string password) :id(id),username(username), password(password){}
    ~User() {

    }
    void setUsername(string username) {
        this->username = username;
    }
    string getUsername() {
        return username;
    }
    void setPassword(string password) {
        this->password = password;
    }
    string getPassword() {
        return password;
    }
    void setId(int id) {
        if(id<0){
            throw "INVALID INPUT\n";
        }
        else{
        this->id = id;
       }
    }
    int getId() {
        return id;
    }
    virtual void inputUser() {
        try{
            cout << "\n\t\t\t\t--------------- FILL USER INFORMATION ---------------\n";
            
        cout << "\n\t\t\t\tINSERT ID : ";
        cin >> id;
            
        setId(id);
        }catch(char* s)
        {
            cout<<s;
        }
        cout << "\n\t\t\t\tINSERT USERNAME : ";
        cin >> username;
        
        cout << "\n\t\t\t\tINSERT PASSWORD : ";
        cin >> password;

       
    }
    virtual void outputUser() {
        
        cout << "\n\n\t\t\t\t\t.......USER DETAILS......\n";

        cout << "\n\t\t\t\t----------------------------------------\n";
        cout << "\n\t\t\t\t\tUSER ID: "<<getId()<< endl;
        
        cout << "\n\t\t\t\t\tUSERNAME: \t"<<getUsername()<<endl;
        

    }
    virtual void outputUserbeforeedit() {
        
        cout << "\n\n\t\t\t\t .......USER AFTER MODIFY DETAILS......\n";

        cout << "\n\t\t\t\t----------------------------------------\n";
        cout << "\n\t\t\t\t\tUSER ID: "<<getId()<< endl;
        
        cout << "\n\t\t\t\t\tUSERNAME: \t"<<getUsername()<<endl;
        cout << "\n\t\t\t\t----------------------------------------\n";
    }
    

};


