
#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <string>
#include "Product.h"
#include <unordered_map>


using namespace std;


class Category
{
    public:


        Category();
        ~Category();
        Category(string);

        string Category_name;
        unordered_map <string ,Product> storage_house;





        void insertproduct(Product);




        //doesn't have private data

};

#endif // CATEGORY_H

