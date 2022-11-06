


#ifndef SHOP_H
#define SHOP_H

#include<iostream>
#include"Category.h"
#include"User.h"
#include<unordered_map>
#include <queue>
#include "compare_order.h"





using namespace std;




class Shop
{
    friend class order;
    public:


    unordered_map <string ,User> users_map;
    vector<Category> categories;
    priority_queue<order,vector<order>,compare_order > commande; // periority queue  of different requests first in





        Shop();
        ~Shop();


        void add_user(User);
        void add_user(string); // add user to filess
        void delete_user(string); // before dleting the object user we gotta delete it from the hashtable and file


        void add_product(Category, const Product &);
        void add_product(string );    //add product to files
        void remove_product(string);
        void add_category( string );   //function that adds a category to the storage house

        void remove_category(string );
        bool check_product(string);

        void add_request(order& order1);// customer will contact the shop and send them the order
        void remove_request(); // the online shop will serve the customer : check if it exists then check if memeber

};


#endif // SHOP_H



