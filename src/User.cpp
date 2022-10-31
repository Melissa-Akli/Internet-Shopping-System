#include "User.h"




//constructor
User:: User(string username , string region , string street, int home_number,string cardnumber , int d , int m , int y )
{
    User_name=username;

    Home_address.region=region;
    Home_address.street=street;
    Home_address.home_number=home_number;

    CreditCard.number=cardnumber;
    CreditCard.ExpiryDate.day=d;
    CreditCard.ExpiryDate.month=m;
    CreditCard.ExpiryDate.year=y;
}


User::User()
{
    cout<<" Please Enter Your Information : "<<endl;

     cout<<"Name: ";
     getline(cin>>ws, User_name );

     cout<<"Address : "<<endl;//--------------------------------------------------------------------------------

     cout<<"Region : ";
     getline(cin>>ws, Home_address.region);

     cout<<"Street : ";
     getline(cin>>ws, Home_address.street);

      cout<<"Home Number : ";
     cin>> Home_address.home_number;


      cout<<"Credit Card : "<<endl;//-------------------------------------------------------------------

      cout<<"Number : ";
      getline(cin>>ws,CreditCard.number );

      cout<<"ExpiryDate  : "<<endl;
      // code to get the expiry date check validity and check if it's expired or not


}





User::~User()
{
    //dtor
}
