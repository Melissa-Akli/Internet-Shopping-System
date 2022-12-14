#include "User.h"


//constructor

User::User(string username,string pass, string region , string street, int home_num,string cardnumber , int d , int m , int y )
:Home_address(region,street,home_num), CreditCard(d,m,y,cardnumber)
{
    membership=0;
   User_name=(valid_username(username))? username:" ";
   password=(!Invalid_password(pass))? pass: " ";

} // end of parameterized constructor



User::User(string name )
{
     membership=0;
     User_name=name;
     update_address();
     update_creditCard();
     update_password();

}   // end of default constructor


User::User()
{
     User_name=" ";
     membership=0;
     password=" ";
     // other informations already initialized in their constructors
}   // end of default constructor



User::~User()
{
     // what to do ??
}


bool User::checkMembership()const
{
    if(membership>=100000)
    {
        return true;
    }

    return false;
}



void User:: update_address()
{
    cout<<"Enter the address : "<<endl;

     cout<<"Region : ";
     getline(cin>>ws, Home_address.region);

     // cheking address's validity

     while(!Is_valid_name(Home_address.region))
     {
         cout<<"Invalid Region name please try again !"<<endl;
         cout<<"Region :";
         getline(cin>>ws, Home_address.region );
     }


     cout<<"Street : ";
     getline(cin>>ws, Home_address.street);

     // cheking address's validity

     while(!Is_valid_name(Home_address.street))
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
       cout<<"Enter  credit Cards' ID  Number : ";
      getline(cin>>ws,CreditCard.number );

      while(!isvalid_Number(CreditCard.number)||CreditCard.number.size()!=16)
      {
          cout<<"Invalid ID , try again ! "<<endl;
          cout<<"ID Number : ";
          getline(cin>>ws,CreditCard.number );
      }


      cout<<"Enter ExpiryDate  : "<<endl;

      // there is two ways here , read the expiry date as a string and then separate it
      // or cin one by one ??????????????????

      cout<<"Day :";
      cin>>CreditCard.ExpiryDate.day;

      while(CreditCard.ExpiryDate.day<1 || CreditCard.ExpiryDate.day>31)
      {
          cout<<"Invalid date ! please try again "<<endl;
          cout<<"Day :";
          cin>>CreditCard.ExpiryDate.day;

      }


      cout<<"Month :";
      cin>>CreditCard.ExpiryDate.month;

      while(CreditCard.ExpiryDate.month<1 || CreditCard.ExpiryDate.month>12)
      {
          cout<<"Invalid date ! please try again "<<endl;
          cout<<"Month :";
          cin>>CreditCard.ExpiryDate.month;

      }

      cout<<"Year :";
      cin>>CreditCard.ExpiryDate.year;

      //Credit cards expire every three to five years

      while(CreditCard.ExpiryDate.year<2022 )
      {
          cout<<"Invalid date ! please try again "<<endl;
          cout<<"Year :";
          cin>>CreditCard.ExpiryDate.year;

      }

}



void User::display_profile()
{
  cout<<"Name : "<<User_name<<endl;
  cout<<"Address : ";
  cout<<Home_address.home_number<<" ";
  cout<<Home_address.street<<" ";
  cout<<Home_address.region<<endl;


  cout<<"Credit Card ID : "<<CreditCard.number<<endl;
  cout<<"Expiry date : "<<CreditCard.ExpiryDate.day;
  cout<<" / "<<CreditCard.ExpiryDate.month;
  cout<<" / "<<CreditCard.ExpiryDate.year<<endl;

   if(checkMembership())
   {
       cout<<"Membership : member "<<endl;
   }
    else
    {
        "Membership : Not a member yet !";
    }


}

void User::update_name()
{

     cout<<"Name: ";
     getline(cin>>ws, User_name );

     // checking name's validity

     while(!valid_username(User_name))
     {
         cout<<"Invalid user name please try again !"<<endl;
         cout<<"Name: ";
         getline(cin>>ws, User_name );
     }

}


void User::update_password()
{
    cout<<"Enter password : ";
    getline(cin>>ws, password);

    while(Invalid_password(password))
    {
        cout<<"Invalid password ! try again : ";
        getline(cin>>ws, password);
    }
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

string User::get_password()const
{
    return password;
}

Card User::get_card()const
{
    return CreditCard;
}

 double User::get_membership_count()const
 {
     return membership;
 }


User& User::operator = (const User& user2)
{
    if(this!= &user2)
    {

        User_name=user2.User_name;
        membership=user2.membership;
        CreditCard=user2.CreditCard;
        Home_address=user2.Home_address;
        password=user2.password;

    }

    return *this;
}



void User::update_membership(double price )
{
    membership+=price;
}


bool User::check_CreditCard_validity ()
{
    time_t t=time(0);

    tm* now =localtime(&t);
    date today(now->tm_mday, now->tm_mon+1 ,now->tm_year+1900);

    if(CreditCard.ExpiryDate==today)
    {
        return true ;
    }
    return false ;
}

