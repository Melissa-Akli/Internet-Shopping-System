#include<iostream>
using namespace std;

#ifndef PRODUCT_H
#define PRODUCT_H


class Product
{
    public:
        Product();
         ~Product();


    private:
         string name;
         string ID;
         int unitprice;
         int quantity;

};

#endif // PRODUCT_H
