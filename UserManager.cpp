//
//  UserManager.cpp
//  BusManagement_v3
//
//  Created by Yeow Pann on 15/11/22.
//


#pragma once
#include <iostream>
#include "User.cpp"
#include "UserDAO.cpp"
using namespace std;

class UserManager: public  UserDao{
private:
    User* users[10];
    int count = 0;
    string username ;
    string password ;
    
    int loginAttempt = 0;
    const int Count = 5;
public:

    void addUser(User* user) {
        users [count] = new User();
        users[count] = user;
        count++;
    }

    void viewUser() {
        
        for(int i = 0; i < count; i++){
            users[i]->outputUser();
        }
    }


    
    void searchById(int id){
        int found = findUserById(id);
        if((found = -1)){
                            cout <<"\n\t\t\t\t>>> SEARCHING BUS ID NOT FOUND <<<"<< endl;
                    }
                    else {
            
                            users[found]->outputUser();
            
                        }
    }
    
    void searchByUserName(string userName){
        
        int found = findUersByName(userName);
        if((found = -1)){
                            cout <<"\n\t\t\t\t>>> SEARCHING BUS ID NOT FOUND <<<"<< endl;
                    }
                    else {
            
                            users[found]->outputUser();
                        }
    }
    
    int findUserById(int id){
        for(int i = 0; i < count ; i++){
            if (users[i]->getId()==id) {
                users[i]->outputUser();
                return i;
            }
          
        }
        return -1;
        
    }
    int findUersByName(string username) {
        for (int i = 0; i < count; i++) {
            if (users[i]->getUsername() == username) {
                users[i]->outputUser();
                return i;
            }
        }
        return -1;
    }
    void editUserbyId(int id){
        
        int found = findUserById(id);
       
        if(found != -1){
            cout << "\n\t\t\t\tINPUT NEW USER ID: ";
            cin >> id;
            users[found]->setId(id);
            users[found]-> outputUserbeforeedit();
            
            cout << "\n\t\t\t\t\t >>> This User ID has Been Edited <<< "<< endl;
            
        }
        else {
            cout <<"\n\n\t\t\t\t>>> User No "<<id<<" NOT FOUND <<<"<< endl;
        }
    }

    
    void editUserbyName(string username) {
 

        int found = findUersByName(username);

        if (found != -1) {
           
            cout << "\n\t\t\t\tINSERT  NEW USERNAME: ";
            cin >> username;
            users[found]->setUsername(username);
            users[found]-> outputUserbeforeedit();
            
            cout<<"\n\n\t\t\t\t\t >>> This User Name has been Edited <<<" <<endl;

        }
        else {
                        cout <<"\n\t\t\t\t>>> User Name's "<<username<<" NOT FOUND <<<"<< endl;
        }
    }

    
    void deleteUserbyName(string name) {

        int found = findUersByName(name);
        if (found != -1) {
         
            for (int i = 0; i < count; i++) {
                users[i] = users[i + 1];
            }
            count--;
           cout << "\n\n\t\t\t\t>>> This UserName " <<name<<" has been deleted <<<";
            
        }
        else {
            cout <<"\n\t\t\t\t>>> User's "<<name<<" NOT FOUND <<<"<< endl;
        }
    }
    
    

    void deleteUserbyId(int id){
        int found = findUserById(id);
  
        if (found != -1){
         
            for(int i = 0; i < count; i++){
                users[i] = users[i+1];
            }
            count--;
            cout << "\n\n\t\t\t\t>>> this users has been delete <<<\n";
            
        }
        else {
                       cout <<"\n\t\t\t\t>>> USER NO "<<id<<" NOT FOUND <<<"<< endl;
        }
        
    }

    User* authenticateUser(string username, string password) {
        User* user=nullptr;
        for (int i = 0; i < count; i++) {
            if (users[i]->getUsername() == username && users[i]->getPassword() == password) {
                return users[i];
            }
        }
        return user;
    }
};
