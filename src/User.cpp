#include "User.h"
static User::membership=0;



//constructor
User:: User(string username , string region , string street, int home_number,string cardnumber , int d , int m , int y )
{
    name=username;

    address.region=region;
    address.street=street;
    address.home_number=home_number;

    CreditCard.number=cardnumber;
    CreditCard.ExpiryDate.day=d;
    CreditCard.ExpiryDate.month=m;
    CreditCard.ExpiryDate.year=y;
}


User::User()
{
    getInfos();
}

 void getInfos()
 {
     cout<<" Please Enter Your Information : "<<endl;

     cout<<"Name: ";
     getline(cin>>ws,name);

     cout<<"Address : "<<endl;//--------------------------------------------------------------------------------

     cout<<"Region : ";
     getline(cin>>ws, address.region);

     cout<<"Street : ";
     getline(cin>>ws, address.street);

      cout<<"Home Number : ";
     getline(cin>>ws, address.home_number);


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
