
#include<iostream>
#include<Category.h>
#include<list>
#include<queue>
using namespace std;



#ifndef SHOP_H
#define SHOP_H


class Shop
{
    public:
        Shop();
        ~Shop();
        void AddRequest(); // by membership and time ...
        string CheckRequest();



    private:
        queue <Order>Request;
        list<Category> MyShop;
};

#endif // SHOP_H
