#ifndef ORDER_H
#define ORDER_H

#include<iostream>
#include <list>
#include "Product.h"
#include "User.h"


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

            bool operator ==(item  item2){
            return p==item2.p;

            }
            
 

        };
    
        list<item> ordered_item;// we will use a list to receive the item that the customer wants to buy
        User customer;



        order(User);
        ~order();
        
        void add_item(int n, Product t);  // check the product if it is available before adding it into the order
        void remove_item(int n, Product t);
        bool check_item(item);
        void show_order();
    };
    class compare_order// to become comparable
    { 
        public:
        
       bool operator ()(const order& order1,const order& order2){
       
       return ((order1.customer.checkMembership()&& !order2.customer.checkMembership() ) ;

       }
  
    };

#endif // ORDER_H
