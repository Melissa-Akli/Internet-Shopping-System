
#include<iostream>
#include<Order.h>
#include "functions.h"
using namespace std;


// checkmembership doesn't work check whyyy ???????????????
//____________________________________________________CLASS USER_______________________________________________________


#ifndef USER_H
#define USER_H


class User
{

    public:

        User(string ,string , string, string ,int  ,string , int , int , int );
        User(string);
        User();
        ~User();

        string get_name()const;
        address get_address()const;
        Card get_card()const;
        date get_ExpiryDate()const;
        string get_cardID()const;    // do we need them or just need to return card since we have the structure in seperate file
        string get_password()const;
        double get_membership_count()const;


        bool checkMembership();
        void update_name();
        void update_password();
        void update_address();
        void update_creditCard();

        void display_profile();

        User& operator = (const User&);




    private:

        string User_name;
        double membership;
        Card CreditCard;
        address Home_address;
        string password;



};

#endif // USER_H
