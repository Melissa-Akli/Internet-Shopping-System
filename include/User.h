
#include<iostream>
using namespace std;

#ifndef USER_H
#define USER_H


class User
{
    public:
        User(string , string ,string , int , int , int );
        User();
        ~User();
        bool checkMembership();
        void getInfos();
        void SendRequest();
        void DeleteItem();
        void AddItem();



    private://________________________________________________________________

        string name;
        string address;
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
