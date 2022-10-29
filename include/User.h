
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
        void getInfos();
        void SendRequest();
        void DeleteItem();
        void AddItem();
        void Display_PurshaseList();





    private://________________________________________________________________

        string name;

         struct address
        {
            string region;
            string street;
            int home_number;
        } ;

        address Home_address;


        list <Product> PurshaseList;

        static double membership;

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
        };

        //object card
        Card CreditCard;

};

#endif // USER_H
