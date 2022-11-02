
#include<iostream>
#include<Order.h>
#include "functions.h"
using namespace std;

//____________________________________________________CLASS USER_______________________________________________________


#ifndef USER_H
#define USER_H


class User
{

    public:

        User(string ,string , string, string ,int  ,string , int , int , int );
        User();
        ~User();

        string get_name()const;
        address get_address()const;
        date get_ExpiryDate()const;
        string get_cardID()const;


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
