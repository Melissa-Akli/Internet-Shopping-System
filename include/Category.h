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
        bool operator == ( Category cat2)
        {
            if(Category_name==cat2.Category_name && storage_house==cat2.storage_house )
                return true ;

            return false;
        }

        string Category_name;
        unordered_map <string ,Product> storage_house;





        void insertproduct(Product);




        //doesn't have private data

};

#endif // CATEGORY_H
