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
     cout <<Home_address.region;


     while(!Is_valid(Home_address.region))
     {
         cout<<"Invalid Region name please try again !"<<endl;
         cout<<"Region :";
         getline(cin>>ws, Home_address.region ); // is valid returns true even it's false !!!!!!!!!!!! why
     }


     cout<<"Street : ";
     getline(cin>>ws, Home_address.street);

     // cheking address's validity

     while(!Is_valid(Home_address.street))   // is valid returns true even it's false !!!!!!!!!!!! why
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

      while(!isvalid_Number(CreditCard.number))
      {
          cout<<"Invalid number , please try again !"<<endl;
          cout<<"Number : ";
          getline(cin>>ws,CreditCard.number );
      }


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

      //Credit cards expire every three to five years

      while(CreditCard.ExpiryDate.year<2022 || CreditCard.ExpiryDate.year >2070) //???
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


bool User::checkMembership()
{
    if(membership>=100000) return true;
    return false;
}



void User:: update_address()
{
    cout<<"Enter the new address : "<<endl;

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


}


void User::update_creditCard()
{
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

      //Credit cards expire every three to five years

      while(CreditCard.ExpiryDate.year<2022 && CreditCard.ExpiryDate.year >2070) //???
      {
          cout<<"Invalid date ! please enter it again "<<endl;
          cout<<"Year :";
          cin>>CreditCard.ExpiryDate.year;

      }

}



void User::display_profile()
{
  cout<<"Name : "<<User_name<<endl;
  cout<<"Address :"<<endl;
  cout<<"Region : "<<Home_address.region;
  cout<<"\t Street : "<<Home_address.street;
  cout<<"\t Home Number : "<<Home_address.home_number<<endl;

  cout<<"Credit Card ID : "<<CreditCard.number;
  cout<<"\t Expiry date : "<<CreditCard.ExpiryDate.day;
  cout<<" / "<<CreditCard.ExpiryDate.month;
  cout<<" / "<<CreditCard.ExpiryDate.year<<endl;
   if(checkMembership()) cout<<"Membership : member "<<endl;
    else "Membership : Not a member yet !";
}


// getters

string User::get_name()const
{
    return User_name;
}


address User::get_address()const
{
   return Home_address;
}


date User::get_ExpiryDate()const
{
    return CreditCard.ExpiryDate;
}

string User::get_cardID()const
{
    return CreditCard.number;
}





