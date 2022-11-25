//
//  UserDAO.cpp
//  BusManagement_v3
//
//  Created by Yeow Pann on 24/11/22.
//

#include <iostream>
#include "User.cpp"
using namespace std;

class UserDao{
    
public:
    
    virtual void addUser(User* user) = 0;
    
    virtual void viewUser() = 0;

    virtual int findUersByName(string username) = 0;
       
    virtual int findUserById(int id) = 0;
       
    virtual void editUserbyId(int id) = 0;
        
    virtual void editUserbyName(string username) = 0;
 
    virtual void deleteUserbyId(int id) = 0;

    virtual User* authenticateUser(string username, string password) = 0;
};
