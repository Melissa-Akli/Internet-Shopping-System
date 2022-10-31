#include<iostream>
using namespace std;

#include<User.h>
#include<Shop.h>


int main()
{
    int a;

    cout<<" -------------------------- INTERNET SHOPPING SYSTEM -------------------------------"<<endl;

    cout<<"\nAre You : "<<endl;
    cout <<"1- Costumer "<<"\t"<<"2- Shop Owner"<<endl;
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

// case it's a user
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

         if(a==1)
        {
             // check  old user if it exist
             // check if password valid
        }


        else
        {
            User NewUser; // add this new_user to the files or list of existing users
        }




    } //end if user -----------------------------------------------------------------------------------------------




// case of a shop

    else
    {
            // check if shop exist or not

    } // end else shop --------------------------------------------------------------------------------



return 0;
}
