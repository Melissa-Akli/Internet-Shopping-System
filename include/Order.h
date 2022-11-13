
#ifndef ORDER_H
#define ORDER_H


#include<iostream>
#include <list>
#include "Product.h"
#include "User.h"
#include "Shop.h"


using std::list;



class order
    {   friend class shop;

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
            
             item operator = (const item & it)
            {
                quantity= it.quentity;
                p=it.p;
            }

            bool operator ==(item  item2){
            return p==item2.p;

            }



        };

        list<item> ordered_item;// we will use a list to receive the item that the customer wants to buy
        User customer;



        order(User);
        order();
        ~order();
     
     order operator =(const order& ORDER)
        {
           ordered_item.copy(ORDER.ordered_item.begin(),ORDER.ordered_item.end(),ordered_item.begin());

              customer=ORDER.customer;
        }
     

        void add_item(int n, Product t);  // check the product if it is available before adding it into the order
        void remove_item(int n, Product& t);
        bool check_item(item);
        void show_order();


        // operator to make order comparable ... used in priority queue

        bool operator == (   order  order1 );
        bool operator != (   order  order1 );
        bool operator <  (   order  order1 );
        bool operator >  (   order  order1 );




    };




#endif // ORDER_H
