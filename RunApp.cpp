//
//  RunApp.cpp
//  BusManagement_v3
//
//  Created by Yeow Pann on 15/11/22.
//



#include <iostream>
#include "Bus.cpp"
#include "VipBus.cpp"
#include "ExpressBus.cpp"
#include "User.cpp"
#include "UserManager.cpp"
#include "BusOffice.cpp"
#include "Admin.cpp"
#include "Normal.cpp"

using namespace std;

class RunApp{
    
public:
    void run1() {
        
        char ch;
        char choice;
        string name;
        int op1=0;
        int op2 =0;
        int id;
        int op = 0;
       
        char deleteopt;
        UserManager userManager;
        User user;
        Admin* admin = nullptr;
        Normal* normal = nullptr;
    
        int num;
        
        enum UserType { NORMAL = 2, ADMIN = 1 };
        enum usermenuType {
            NEW_USER = '1', VIEW_USER = '2', EDIT_USER = '3', DELETE_USER= '4',
            SEARCH_USER = '5', EXIT = '0'
        };
        enum editType {EDITID_USER = 1, EDITNAME_USER = 2};
        enum deleteType {DELETENAME_USER = 2, DELETEID_USER = 1};
        enum searchType {SEARCHID_USER = 1, SEARCHNAME_USER = 2};

        
        do
        {
           
                    cout << "\n\t\t\t\t----------------------------------------\n";
                    cout << "\t\t\t\t             ADMIN DASHBOARD       ";
                    cout << "\n\t\t\t\t----------------------------------------\n";
                    cout << "\n\n\t\t\t\t[+] 1. ADD NEW USER";
                    cout << "\n\n\t\t\t\t[+] 2. VIEW ALL USERS";
                    cout << "\n\n\t\t\t\t[+] 3. EDIT A USER";
                    cout << "\n\n\t\t\t\t[+] 4. DELETE A USER";
                    cout << "\n\n\t\t\t\t[+] 0. EXIT";
                    cout << "\n\n\t\t\t\tSelect Your Option (0-4) ";
                    cin >> ch;
                  //  system("cls");
            switch (ch)
            {
                case usermenuType::NEW_USER:{
                    do{
                            cout <<"\n\t\t\t------------- TYPE OF ACCOUNT -------------\n\n";
                            cout <<"\n\t\t\t\t1. ADMIN ACCOUNT" << endl;
                            cout <<"\n\t\t\t\t2. NORMAL ACCOUNT"<< endl;
                            cout <<"\n\t\t\t\tChoose your choice : ";
                            cin>> op;
                        
                    switch (op) {
                            
                        case UserType::ADMIN:{
                                    admin = new Admin;
                                    admin->inputUser();
                                    userManager.addUser(admin);
                            
                        }break;
                        case UserType::NORMAL:{
                                    normal = new Normal;
                                    normal->inputUser();
                                    userManager.addUser(normal);
                        }break;
                            
                        default:{
                                    cout << "\n\t\t\t\t>>> Invalid Input<<<" << endl;
                        }break;
                    }
                                    cout << "\n\t\t\t\tDo you want to continue(y/n)";
                                    cin >> choice;
                    }while(choice!='n');
            }break;
                   // system("cls");
                case usermenuType::VIEW_USER:{
                                userManager.viewUser();
                }break;


                case usermenuType::EDIT_USER:
                    
                                    do{
                                                cout <<"\n\t\t\t\t---------- TYPE OF EDITING----------\n\n";
                                                cout <<"\n\t\t\t\t[+] 1. EDIT USER BY ID" << endl;
                                                cout <<"\n\t\t\t\t[+] 2. EDIT USER BY NAME"<< endl;
                                                cout <<"\n\t\t\t\tChoose your choice : ";
                                                cin >> op1;
                        switch (op1) {
                                
                            case editType::EDITID_USER:{
                                        cout <<"\n\t\t\t\tINPUT USER ID TO EDIT: ";
                                        cin >> id;
                                        userManager.editUserbyId(id);
                            }break;
                            case editType::EDITNAME_USER:{
                                        string name;
                                        cout <<"\n\t\t\t\t\tINPUT USER NAME TO EDIT: ";
                                        cin >> name;
                                        userManager.editUserbyName(name);
                            }break;
                        
                            default:{
                                        cout << "\n\t\t\t\t>>> Invalid Input<<<" << endl;
                            }break;
                    }
                                        cout << "\n\t\t\t\n\nDo you want to continue(y/n)";
                                        cin >> choice;
                    
                                    }while(choice != 'n');
        
        break;

            
        case usermenuType::DELETE_USER:{
            
                                do{
                
                
                                        cout <<"\n\t\t\t\t\t----------- TYPE OF DELETE -----------\n\n";
                                        cout <<"\n\t\t\t\t[+] 1. DELETE USER BY ID" << endl;
                                        cout <<"\n\t\t\t\t[+] 2. DELETE USER BY NAME"<< endl;
                                        cout <<"\n\t\t\t\tChoose your choice : ";
                                        cin >> op2;
                                    switch (op2) {
                    case deleteType::DELETEID_USER:{
                        
                                        cout << "\n\t\t\t\tINPUT USER ID TO DELETE: ";
                                        cin >> num;
                            
                                        cout << "\n\n\t\t\t\tAre you sure you want to delete (y/n)?";
                                        cin >> deleteopt;
                        switch (deleteopt) {
                                case 'y':
        
                           
                                        userManager.deleteUserbyId(num);
        
                                break;
                            case 'n':
                                break;
            
                            }
                        
                    break;
                        
                    case deleteType::DELETENAME_USER:
                        
                                            cout << "\n\t\t\t\tINPUT USER NAME TO DELETE: ";
                                            cin >> name;
                                            userManager.findUersByName(name);
                                            cout << "\n\n\t\t\t\tAre you sure you want to delete (y/n)?";
                                            cin >> deleteopt;
                        switch (deleteopt) {
                            case 'y':
                    
                                userManager.deleteUserbyName(name);
                              
                                break;
                            case 'n':
                                break;
                                
                        }
                                        
                    }break;
                        
                            default:{
                                          cout << "\n\t\t\t\t>>> Invalid Input<<<" << endl;
                            }break;
                }
                                            cout << "\n\t\t\t\t\tDo you want to continue(y/n)";
                                            cin >> choice;
                                }while(choice != 'n');
                }break;
                    
                case usermenuType::EXIT:
                                                cout << "\n\n\t\t\t\t\t>> Thanks for using our system <<";
                    //exit(0);
                    break;
                default:{
                            cout << "\n\t\t\t\t>>> Invalid Input<<<" << endl;
                        }break;
            }
            cin.ignore();
            cin.get();
        } while (ch != '0');
    }
    
    

    
    void run2()
    {
        int op = 0;
  
        char choice;
        char ch;
        char deleteopt;
        int op2 = 0;
        int op1 = 0;
        int op3 = 0;
        int num = 0;
        BusOffice busoffice;
        int id;
        string name;
        VipBus* vipbus = nullptr;
        ExpressBus* expressbus = nullptr;
  
        enum busType { VIP_BUS = 1, EXPRESS_BUS = 2 };
        enum menuType {
            NEW_BUS = '1', VIEW_BUS = '2', EDIT_BUS = '3', DELETE_BUS = '4',
            SEARCH_BUS = '5', EXIT = '0'
        };
        enum editType {EDITID = 1, EDITNAME = 2};
        enum deleteType {DELETE_NAME = 2, DELETE_ID = 1};
        enum searchType {SEARCH_ID = 1, SEARCH_NAME = 2};

                            do{

                                                    system("cls");
                                                    cout<<"\n\n";
                                                    cout << "\n\t\t\t\t----------------------------------------\n";
                                                    cout << "\t\t\t\t             USER DASHBOARD       ";
                                                    cout << "\n\t\t\t\t----------------------------------------\n";
                                                    cout << "\n\t\t\t\t[-] 1 ADD NEW BUS INFO\n\t\t\t";
                                                    cout << "\n\t\t\t\t[-] 2 VIEW BUS INFO\n\t\t\t";
                                                    cout << "\n\t\t\t\t[-] 3 MODIFY BUS INFO\n\t\t\t";
                                                    cout << "\n\t\t\t\t[-] 4 DELETE BUS INFO\n\t\t\t";
                                                    cout << "\n\t\t\t\t[-] 5 SEARCH BUS\n\t\t\t";
                                                    cout << "\n\t\t\t\t[-] 0 EXIT\n\t\t\t";
                                                    cout << "\n\t\t\t\tENTER CHOICE:-> ";
                                                            cin >> ch;
            
            
            switch (ch) {
                case menuType::NEW_BUS:
                    do
                    {
                                                            cout <<"\n\t\t\t\t---------- TYPE OF BUS ----------\n\n";
                                                            cout <<"\n\t\t\t\t[+] 1. VIP BUS" << endl;
                                                            cout <<"\n\t\t\t\t[+] 2. EXPRESS BUS"<< endl;
                                                            cout <<"\n\t\t\t\tChoose your choice : ";
                                                            cin >> op;
                        switch (op) {
                                
                            case busType::VIP_BUS:
                                
                                vipbus = new VipBus();
                                vipbus->inputBus();
                                busoffice.addBus(vipbus);
                                cout << "\n\nData Successfully ADDED....\n";
                                
                                break;
                            case busType::EXPRESS_BUS:
                                
                                expressbus = new ExpressBus();
                                expressbus->inputBus();
                                busoffice.addBus(expressbus);
                                break;

                            default:
                                cout << "\n\t\t\t\t>>> Invalid Input<<<" << endl;
                                break;
    
                        }
                        cout << "\n\t\t\t\t\tDo you want to continue(y/n)";
                        cin >> choice;
                        
                    }while(choice != 'n');
                    
                break;
    
                    
                case menuType::VIEW_BUS:
                    
                    busoffice.displayAllBus();
                    break;
                    
                    
                case menuType::EDIT_BUS:
                    do
                    {
                   
                        cout <<"\n\t\t\t\t---------- TYPE OF EDITING----------\n\n";
                        cout <<"\n\t\t\t\t[+] 1. EDIT BUS BY ID" << endl;
                        cout <<"\n\t\t\t\t[+] 2. EDIT BUS BY DRIVER's NAME"<< endl;
                        cout <<"\n\t\t\t\tChoose your choice : ";
                        cin >> op1;
                        
                        switch (op1) {
                                
                             
                                
                            case editType::EDITID:
                                    cout <<"\n\t\t\t\tINPUT BUS ID TO EDIT: ";
                                                     cin >> id;
                                                     busoffice.modifyBusByID(id);
                                break;
                            case editType::EDITNAME:{
                                   // string name;
                                cout <<"\n\t\t\t\tINPUT BUS DRIVER's NAME TO EDIT: ";
                                cin >> name;
                                busoffice.modifyBusByName(name);
                            }break;
                
                            default:{
                                cout << "\n\t\t\t\t>>> Invalid Input<<<" << endl;
                            }break;
                                    
                                }
                    
                            cout << "\n\t\t\t\n\nDo you want to continue(y/n)";
                            cin >> choice;
                    }while(choice != 'n');

                    break;
                        
                    
                case menuType::DELETE_BUS:{
                    do
                    {
                   
                        cout <<"\n\t\t\t\t---------- TYPE OF DELETE----------\n\n";
                        cout <<"\n\t\t\t\t[+] 1. DELETE BUS BY ID" << endl;
                        cout <<"\n\t\t\t\t[+] 2. DELETE BUS BY DRIVER's NAME"<< endl;
                        cout <<"\n\t\t\t\tChoose your choice : ";
                        cin >> op2;
                        switch (op2) {
                            case deleteType::DELETE_ID:{
                                
                                cout <<"\n\t\t\tInput Bus By ID to Delete: ";
                                cin >> num;
                                busoffice.searchBusById(num);
                               // busoffice.displayAllBus();
                                cout << "\n\t\t\t\tAre you sure you want to delete (y/n)?";
                                cin >> deleteopt;
                switch (deleteopt) {
                        case 'y':
    
                              //  cout << "\n\t\t\t\t>>> Your Bus no "<<num <<" has been deleted <<<\n";
                        busoffice.deletebusId(num);
                        
                            break;
                    case 'n':
                        
                        break;
    
                    }
                             
                            }break;
                            case deleteType::DELETE_NAME:{
                                
                                cout <<"\n\t\t\tInput Bus By Driver's Name to Delete: ";
                                cin >> name;
                                busoffice.searchBusByName(name);
                                cout << "\n\t\t\t\tAre you sure you want to delete (y/n)?";
                                cin >> deleteopt;
                                switch (deleteopt) {
                                        case 'y':
                    
                                        busoffice.deletebusName(name);
                                        
                                            break;
                                    case 'n':
                                        
                                        break;
                    
                                    }
                               
                            }break;
                                
                            default:{
                                cout << "\n\t\t\t\t>>> Invalid Input<<<" << endl;
                            }break;
                        }
                        cout << "\n\t\t\t\n\nDo you want to continue(y/n)";
                        cin >> choice;
                }while(choice != 'n');
                    
                }break;
                    
                        
                    
                case menuType::SEARCH_BUS:{
                    do
                    {
                   
                        cout <<"\n\t\t\t\t---------- TYPE OF SEARCH ----------\n\n";
                        cout <<"\n\t\t\t\t[+] 1. SEARCH BUS BY ID" << endl;
                        cout <<"\n\t\t\t\t[+] 2. SEARCH BUS BY DRIVER's NAME"<< endl;
                        cout <<"\n\t\t\t\tChoose your choice : ";
                        cin >> op3;
                        switch (op3) {
                            case searchType::SEARCH_ID:{
                                                    cout <<"\n\t\t\t\tSearch Bus By ID: ";
                                                    cin >> num;
                                
                          
                                busoffice.findBusById(num);
                                         

                            }break;
                            case searchType::SEARCH_NAME:{
                          
                                                    cout <<"\n\t\t\t\tSearch Bus By Driver's Name: ";
                                                    cin >> name;
                                busoffice.findBusByName(name);
                                                 
                            }break;
             
                            default:{
                                cout << "\n\t\t\t\t>>> Invalid Input<<<" << endl;
                            }break;
                        }
                                cout << "\n\t\t\t\n\nDo you want to continue(y/n)";
                                cin >> choice;
                     
                    }while(choice != 'n');
                }break;

                case menuType::EXIT:{
                    cout << "\n\n\t\t\t\t\t>> Thanks for using our system <<";
                }break;

                default:{
                    cout << "\a";
                }break;
            }

               cin.ignore();
               cin.get();

        }while (ch!= '0');
    
    }
};


