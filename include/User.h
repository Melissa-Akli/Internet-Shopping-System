
#include<iostream>
#include<string>
#include<Order.h>
using namespace std;




    // utility function to help check the validity of a name

        bool Is_valid(const string & name)
        {
            for(char c: name)
            {
                if(!isalpha(c)&& c!=' ')   //check here for whitespace function
                {
                    return false;
                }
            }

            return true;
        }

      // utility function to help check the validity of numbers

        bool isvalid_Number(const string & number)
        {
            for(char c: number)
            {
                if(!isdigit(c)) return false;
            }

            return true;
        }


         bool Invalid_password(string pass)
         {
             if(isdigit(pass[0])) return true;

             for(char c: pass)
             {
                 if(c==' ') return true ;
             }

             return false;
         }


#ifndef USER_H
#define USER_H

// shop friend of user ????? to access addrequest function....
class User
{


// a structure date
  struct date
  {
     int day;
     int month;
     int year;

     date():day(1),month(1),year(2022){}

     date(int d, int m, int y)
     {
         day=(d>0 && d<=31) ? d:1;
         month=(m>0 && m<=12)? m:1;
         year=(y>2022)? y:2022;
     }

  }; // end of date


// a structure address
  struct address
  {
      string region;
      string street;
      int home_number;

      address(): region(""),street(""),home_number(0){}

      address(string r, string s, int h)
      {
          region=(Is_valid(r))?r :"";
          street=(Is_valid(s))? s:"";
          home_number=(h>0 )? h : 0;

      }

  };// end of address


// a structure card
        struct Card
        {
           date ExpiryDate;
           string number;

           Card():number("");
           Card( date d , string n):ExpiryDate(d.day,d.month, d.year), number(n){};


        }; // end of card



    public:

        User(string , string, string ,int  ,string , int , int , int );
        User();
        ~User();

        string get_name()const;
        address get_address()const;
        date get_ExpiryDate()const;
        string get_cardID()const;

        void set_name(string );
        void set_password(string);

        bool checkMembership();
        void update_name();
        void update_password();
        void update_address();
        void update_creditCard();

        void display_profile();
        void display_last_purchase();



    private:

        string User_name;
        double membership;
       // vector<order> historic

        Card CreditCard;
        address Home_address;
        string password;











};

#endif // USER_H
