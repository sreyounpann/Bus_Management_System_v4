//
//  Login.cpp
//  BusManagement_v3
//
//  Created by Yeow Pann on 16/11/22.
//

#pragma once
#include "RunApp.cpp"
#include "User.cpp"
#include "UserManager.cpp"

using namespace std;

int main()
{
    RunApp app;
    User* user;
    UserManager userManager;
    string username;
    string password;
    int adminpass;
    string adminusername;
    int choice1;
    string userusername;
    int userpass;
    int adminPassword = 123;
    string adminUsername = "admin";
    int userPassWord = 1234;
    string userUsername = "user";
    int i =0;
    do{
                cout << "\n\t\t\t\t----------------------------------------\n";
                cout << "\t\t\t\t            LOGIN TO BUS SYSTEM        ";
                cout << "\n\t\t\t\t----------------------------------------\n";
                cout << "\n\t\t\t\t[-] Login as??\n\n";
                cout << "\t\t\t\t[+] 1.ADMIN\n";
                cout << "\n\t\t\t\t[+] 2.USER\n";
                cout << "\n\t\t\t\t--> Who are you?...";
                cin >> choice1;
    switch (choice1) {
        case 1:{
     
            do{
                cout << "\n\t\t\t\t----------------------------------------\n";
                cout << "\t\t\t\t               ADMIN LOGIN       ";
                cout << "\n\t\t\t\t----------------------------------------\n";
                cout << "\n\t\t\t\t  NOTE: YOU HAVE ONLY " << 5 - i << " TIMES TO LOGIN\n\n";
                cout << "\t\t\t\t [-]INPUT USERNAME : ";
                cin >> adminusername;
                cout << endl;
                cout << "\t\t\t\t [-]INPUT PASSWORD : ";
                cin >> adminpass;
                if(adminUsername == adminusername && adminPassword == adminpass){
                    
            
                user=userManager.authenticateUser(username, password);
                app.run1();
                }
                else
                    {
                    cout<<"\n\t\t\t\t\t\t>> You Are No An Admin <<\n";
                    i++;
         
                    }
            }while(i>0 && i<5);
            return 0;
                

        }break;
            
        case 2:{
            do{
      
                cout << "\n\t\t\t\t----------------------------------------\n";
                cout << "\t\t\t\t               USER LOGIN       ";
                cout << "\n\t\t\t\t----------------------------------------\n";
                cout << "\n\t\t\t\t  NOTE: YOU HAVE ONLY " << 5 - i << " TIMES TO LOGIN\n\n";
                cout << "\t\t\t\t [-]INPUT USERNAME : ";
                cin >> userusername;
                cout << endl;
                cout << "\t\t\t\t [-]INPUT PASSWORD : ";
                cin >> userpass;
                
                if(userUsername == userusername && userPassWord == userpass)
                {
                        user=userManager.authenticateUser(username, password);
                        app.run2();
                }
                else
                    {
                    cout<<"\n\t\t\t\t\t\t>> You Are No An User <<\n";
                    i++;
               
                    }
            }while(i>0 && i<5);
            return 0;
        }break;
                
    }

    }while (choice1!=-1);
    
}
