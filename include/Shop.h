
#include<iostream>
#include<Category.h>

using namespace std;



#ifndef SHOP_H
#define SHOP_H


class Shop
{
    public:
        Shop();
        ~Shop();

        void add_user(); // it add the user to both file and hashtable
        void delete_user(); // before dleting the object user we gotta delete it from the hashtable and file
/*
        void AddCatogory(string );
        void deleteCategory();

        void AddRequest(); // by membership and time ...

        // add order or add request need to have the time now and bool membership as parameters
        // we have to add the time because when we go to add this order we check first time and them membership in the main


        bool CheckRequest(); // before serving the customer



    void remove_request(); // the online shop will serve the customer : check if it exists then check if memeber , increase total purchase
    int delivery(); // will use the remove_request function  , calculate distance and return price
    int bill();// price of delivery +purchase+ , increase total purchase
    bool pay_bill();// check if the bill is successfully payed
*/

    private:
        //queue <Order>Request;
        // HashTable to register user
        list<Category> MyShop;
};

#endif // SHOP_H
