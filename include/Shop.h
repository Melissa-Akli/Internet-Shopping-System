
#include<iostream>
#include<Category.h>
#include<User.h>
#include<Order.h>
#include<unordered_map>
using namespace std;



#ifndef SHOP_H
#define SHOP_H


class Shop
{
    public:
        Shop();
        ~Shop();

        unordered_map <string ,User> users_map;
        void add_user(User);
        void add_user(string); // add user to filess
        void delete_user(string); // before dleting the object user we gotta delete it from the hashtable and file
    
    
    
    
       vector<Category> categories;

        void add_product(Category, const Product &);
        void add_product(string );    //add product to files
        void remove_product(string);
        void add_category( string );   //function that adds a category to the storage house
        
       
        void remove_category(string );

        bool check_product(string);

    
    
    
    
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
};

#endif // SHOP_H
