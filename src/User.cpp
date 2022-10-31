#include "User.h"


//constructor
// to test data in main

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

} // end of parameterized constructor



User::User()
{
    cout<<" Please Enter Your Information : "<<endl;

     //user name -------------------------------------------------------------------------

     cout<<"Name: ";
     getline(cin>>ws, User_name );

     // checking name's validity

     while(!Is_valid(User_name))
     {
         cout<<"Invalid user name please try again !"<<endl;
         cout<<"Name: ";
         getline(cin>>ws, User_name );
     }
      // user to upper and tolower  here to make the name correct
      // think about the case if two costumers have the same name



     // user address -------------------------------------------------------------------------


     cout<<"Address : "<<endl;
     cout<<"Region : ";
     getline(cin>>ws, Home_address.region);

     // cheking address's validity

     while(!Is_valid(Home_address.region))
     {
         cout<<"Invalid Region name please try again !"<<endl;
         cout<<"Region :";
         getline(cin>>ws, Home_address.region );
     }


     cout<<"Street : ";
     getline(cin>>ws, Home_address.street);

     // cheking address's validity

     while(!Is_valid(Home_address.street))
     {
         cout<<"Invalid Region name please try again !"<<endl;
         cout<<"Street : ";
         getline(cin>>ws, Home_address.street);
     }


      cout<<"Home Number : ";
     cin>> Home_address.home_number;


      cout<<"Credit Card : "<<endl;//-------------------------------------------------------------------

      cout<<"Number : ";
      getline(cin>>ws,CreditCard.number );


      cout<<"ExpiryDate  : "<<endl;

      // there is two ways here , read the expiry date as a string and then separate it
      // or cin one by one ??????????????????

      cout<<"Day :";
      cin>>CreditCard.ExpiryDate.day;

      while(CreditCard.ExpiryDate.day<1 && CreditCard.ExpiryDate.day>31)
      {
          cout<<"Invalid date ! please enter it again "<<endl;
          cout<<"Day :";
          cin>>CreditCard.ExpiryDate.day;

      }


      cout<<"Month :";
      cin>>CreditCard.ExpiryDate.month;

      while(CreditCard.ExpiryDate.month<1 && CreditCard.ExpiryDate.month>12)
      {
          cout<<"Invalid date ! please enter it again "<<endl;
          cout<<"Month :";
          cin>>CreditCard.ExpiryDate.month;

      }

      cout<<"Year :";
      cin>>CreditCard.ExpiryDate.year;

      //Credit cards expire every three to five years !

      while(CreditCard.ExpiryDate.year<2022 && CreditCard.ExpiryDate.year >2027)
      {
          cout<<"Invalid date ! please enter it again "<<endl;
          cout<<"Year :";
          cin>>CreditCard.ExpiryDate.year;

      }


}   // end of default constructor




// NEED WORK !!!!!!!!!!!!!!!!
User::~User()
{
    //dtor
}


bool checkMembership();
        void update_address();  // NEED WORK
        void update_creditCard();    // NEED WORK
        void SendRequest();           // NEED WORK





