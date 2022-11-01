#ifndef ORDER_H
#define ORDER_H

#include<iostream>
#include <list>
#include "Product.h"


using std::list;


class order
    {

public:

        struct item
        {
            Product p;
            int quantity;// number  of item from same product

            item(){
            quantity=0;
            }

            item(int x, Product y):p(y){
            quantity=x>0?x:0;
            }

        };



        order();
        ~order();
        //list<item> get_order()const; // return the list of item
        void add_item(int n, Product t);
        void remove_item(int n, Product t);
        bool check_item(item);// if it is possible using check_product function and we have to check the quantity
        void show_order();

private:

    list<item> ordered_item;
    // we will use a list to receive the item that the customer wants to buy




    };

#endif // ORDER_H
