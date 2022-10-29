
#include<iostream>
#include<Category.h>
#include<list>
using namespace std;



#ifndef SHOP_H
#define SHOP_H


class Shop
{
    public:
        Shop();
        ~Shop();
        string CheckRequest();



    private:
        list<Category> MyShop;
};

#endif // SHOP_H
