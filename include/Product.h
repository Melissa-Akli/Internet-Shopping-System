#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using std::string;

class order;
class Product
{
    public:


        friend class order;

        Product();    //the default constructor
        Product(string,string,double,long int);   //the parameterized constructor
        ~Product();   //the destructor


        void setAvailable_quantity(long int);   // to unable the shop to insert and update the available quantity
        void setUnit_price(double);   //so that the shop can change the unit price of a product easily
        void setProduct_ID(string);



        long int getAvailable_quantity(void)const;
        double getUnitprice(void)const;
        string getProduct_ID(void)const;


        bool operator== (  Product & ) const;


        void ProductDescription(void)const;      //to print the information about the product



    private:
         string name;
         string ID;
         double unitprice;
         long int  available_quantity;  //I used a long int because it may be a colossal number
         bool existentID(string)const
         {
           //no implementation for the moment


         };     // I used here a utility function to check if the ID exists before or not

};

#endif // PRODUCT_H
