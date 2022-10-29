
#include<iostream>
#include<list>
using namespace std;



#ifndef CATEGORY_H
#define CATEGORY_H


class Category
{
    public:
        Category();
        ~Category();




    private:
        string name;

        struct Product
        {
            string name;
            string ID;
            int unitprice;
            int quantity;
        };

        list<Product> Storage;

};

#endif // CATEGORY_H
