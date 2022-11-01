
#include<iostream>
#include<string>
#include<stack>
#include<Order.h>
using namespace std;

// a structure date
  struct date
  {
     int day;
     int month;
     int year;
  };


// a structure address
  struct address
  {
      string region;
      string street;
      int home_number;
  };




#ifndef USER_H
#define USER_H

// shop friend of user ????? to access addrequest function....
class User
{
    public:
        User(string , string, string ,int  ,string , int , int , int );
        User();
        ~User();

        string get_name()const;
        address get_address()const;
        date get_ExpiryDate()const;
        string get_cardID()const;

        bool checkMembership();
        void update_address();
        void update_creditCard();

        void display_profile();
        void display_last_purchase();    // NEED WORK

        //using stack we can just see the last order
        // how to display an order

        void SendRequest();  // in user class or order class




    private:

        string User_name;
        double membership;
        stack<order> histric;// but we just can see the last order top

        address Home_address;

        // a structure card
        struct Card
        {
           date ExpiryDate;
           string number;

        }CreditCard;    //object card


        //string password????
        // should we add an email or user phone_number ?????
        //We need need to call the user before delivering the order

        // verifiying using algerian phone number's form !
       // string phone_number;






    // utility function to help check the validity of a name

        bool Is_valid(const string & name)
        {
            for(char c: User_name)
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

};

#endif // USER_H
