
#include<iostream>
#include<list>
using namespace std;


#include<Product.h>

#ifndef CATEGORY_H
#define CATEGORY_H


class Category
{
    public:
        Category();
        ~Category();






    private:
        string Category_name;
        list<Product> Storage;

};

#endif // CATEGORY_H
