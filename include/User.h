
#include<iostream>
#include<string>
using namespace std;

#ifndef USER_H
#define USER_H

// shop friend of user ????? to access addrequest function....
class User
{
    public:
        User(string , string, string ,int  ,string , int , int , int );
        User();
        ~User();
        bool checkMembership();
        void update_address();  // NEED WORK
        void update_creditCard();    // NEED WORK
        void SendRequest();           // NEED WORK




    private:

        string User_name;
        //string password????
        // should we add an email or user phone_number ?????
        //We need need to call the user before delivering the order

        // verifiying using algerian phone number's form !
       // string phone_number;

        // a structure address
         struct address
        {
            string region;
            string street;
            int home_number;
        } Home_address;


        double membership;

        // a structure date
        struct date
        {
            int day;
            int month;
            int year;
        };


        // a structure card
        struct Card
        {
           date ExpiryDate;
           string number;

        }CreditCard;

        //object card


        // utility function to help check the validity of a name
        bool Is_valid(string name)
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

};

#endif // USER_H
