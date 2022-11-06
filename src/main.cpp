#include<iostream>
using namespace std;
#include "functions.h"
#include<User.h>
#include<Shop.h>
#include <fstream>



void add_to_file_map(const unordered_map<string , User>& mymap)
{
    string name;
    double member;
    Card Credit;
    address Home_add;
    string pass;



    ofstream os;
    os.open("mydata.txt");     // it will delete everything in the file and add all objects from scratch

    for(pair<string,User>it: mymap)
    {
        name=(it.second.get_name());
        member=(it.second.get_membership_count());
        Credit.number=(it.second.get_card()).number;
        Credit.ExpiryDate=(it.second.get_card()).ExpiryDate;
        Home_add=(it.second.get_address());
        pass=(it.second.get_password());


        os<<name<<","<<member<<","<<Credit.number<<",";
        os<< Credit.ExpiryDate.day<<","<< Credit.ExpiryDate.month<<","<< Credit.ExpiryDate.year<<",";
        os<<Home_add.region<<","<<Home_add.street<<","<<Home_add.home_number<<",";
        os<<pass<<endl;    // don't forget endl otherwise it will write everything in one file
    }
}



void add_to_file_user(const User & user)
{
    string name = user.get_name();
    double member = user.get_membership_count();
    Card Credit = user.get_card();
    address Home_add = user.get_address();
    string pass = user.get_password();

    ofstream os;
    os.open("mydata.txt",ios::app);   // by using ios::append it will just add the new user in the end of the file without erasing everything

        os<<name<<","<<member<<","<<Credit.number<<",";
        os<< Credit.ExpiryDate.day<<","<< Credit.ExpiryDate.month<<","<< Credit.ExpiryDate.year<<",";
        os<<Home_add.region<<","<<Home_add.street<<","<<Home_add.home_number<<",";
        os<<pass<<endl;

        os.close();
}

    /*
void read_from_file(unordred_map<string,User>& mymap )
{
    ifstream is;
    is.open("mydata.txt");

    User user;
    string data;

    while(getline())


    is.close();


}
*/ // check functions read and write in fstream
//https://www.geeksforgeeks.org/readwrite-class-objects-fromto-file-c/





int main()
{





    Shop myshop;
    add_to_file_map(myshop.users_map);

    int a;
    string name;
    string pass;

    cout<<" -------------------------- INTERNET SHOPPING SYSTEM -------------------------------"<<endl;

    cout<<"\nAre You : "<<endl;
    cout <<"1- Costumer "<<"\t"<<"2- Admin"<<endl;
    cout<<" Enter 1 or 2 : ";
    cin>>a;

        if(a!=1 || a!=2)
        {
           while(a!=1 && a!=2)
            {
                cout<<"Invalid answer ! please try again "<<endl;
                cout<<" Enter 1 or 2 : ";
                cin>>a;
            }
        }



// case it's a user ___________________________________________________________________________________________

    if(a==1)
    {
        cout<<"1-Log_in "<<"\t"<<"2-Register"<<endl;
        cout<<" Enter 1 or 2 : ";
        cin>>a;

        if(a!=1 || a!=2)
        {
           while(a!=1 && a!=2)
            {
                cout<<"Invalid answer ! please try again "<<endl;
                cout<<" Enter 1 or 2 : ";
                cin>>a;
            }
          }

    // Case LOG_IN -----------------------------------------------------------------------------------------------

         if(a==1)
        {

             cout<<"Enter Name : ";
             getline(cin>>ws,name);

             auto it=myshop.users_map.find(name);

             if(it!=myshop.users_map.end())
             {
                 cout<<"Enter password : ";
                 getline(cin>>ws,pass);

                     while(it->second.get_password()!=pass)
                     {
                         cout<<"Invalid password , try again !"<<endl;
                         getline(cin>>ws,pass);
                     }

                 display_services();
                 cin>>a;
                 // switch cases ....
             }

             else
             {
                 cout<<"User Name doesn't exist , try again ! "<<endl;
                 // here we have two choices enter user_name again or register ?????????????
             }

        }


    // Case REGISTER -------------------------------------------------------------------------------------------------

        else
        { // add this new_user to the files or list of existing users

             cout<<" Please Enter Your Information : "<<endl;
             cout<<"Name: ";
             getline(cin>>ws, name );


        // checking name's validity
             while(!valid_username(name))
             {
               cout<<"Invalid user name please try again !"<<endl;
               cout<<"Name: ";
               getline(cin>>ws, name );
             }


          myshop.add_user(name);
          add_to_file_map( myshop.users_map);

          //  User& user_data=myshop.users_map[name]; if we wanna display profile or access functions

           display_services();
           cin>>a;
          // do_service(a);



        }


    } //end if user




// case of a shop______________________________________________________________________________________________________

    else
    {
            // check if shop exist or not
            // display services for a shop ......
            // add category delete product ....

    } // end else shop


return 0;
}
