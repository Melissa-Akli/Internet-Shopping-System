
#include<iostream>
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


};

#endif // USER_H
