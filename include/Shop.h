


#ifndef SHOP_H
#define SHOP_H

#include<iostream>
#include"Category.h"
#include"User.h"
#include "Product.h"
#include<unordered_map>
#include <queue>
#include "Order.h"






using namespace std;




class Shop
{
    friend class order;
    public:




    unordered_map <string ,User> users_map;
    vector<Category> categories;
    queue<order>member_commande; // periority queue  of different requests first in
    queue<order>non_member_commande;





        Shop();
        ~Shop();


        void add_user(User);
        void add_user(string); // add user to filess
        void delete_user(string); // before dleting the object user we gotta delete it from the hashtable and file


        void add_product(const Product &);

        void remove_product(string);
        void add_category( string );   //function that adds a category to the storage house

        void remove_category(string );
        bool check_product(string);
        void display_categories(void);
        void display_products(string);

        void add_request(order& order1);// customer will contact the shop and send them the order
        order remove_request(); // the online shop will serve the customer : check if it exists then check if memeber


       void  bill(order myorder ,double& price);
        bool check_if_payed(char answer ,order myorder, double total_price  );
        void delivery(order x);


};


#endif // SHOP_H


