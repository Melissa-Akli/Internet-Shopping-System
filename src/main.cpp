#include<iostream>
using namespace std;
#include "functions.h"
#include<User.h>
#include<Shop.h>
#include <fstream>



void add_to_file (Shop myshop)
{
        ofstream file_write_obj;
       file_write_obj.open("mydata.txt");
       // by using ios::append it will just add the new user in the end of the file without erasing everything


     for(pair<string,User>it: myshop.users_map)
     {

         file_write_obj.write((char*)&it.second, sizeof(it.second));
     }


        file_write_obj.close();
}




void read_from_file( Shop myshop )
{
    ifstream file_read_obj;
    file_read_obj.open("mydata.txt", ios::in);

    while (!file_read_obj.eof())
    {
       User obj;
       file_read_obj.read((char*)&obj, sizeof(obj));
       myshop.add_user(obj);
    }

    file_read_obj.close();


}

//https://www.geeksforgeeks.org/readwrite-class-objects-fromto-file-c/





int main()
{





    Shop myshop;
    read_from_file( myshop );

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



    add_to_file(myshop);

return 0;
}
