#include "Product.h"
#include <string>
#include <iostream>


using std::cout;
using std::endl;
using std::cin;
using std::string;



Product::Product()
:name(""),ID(0000),unitprice(0.0),available_quantity(0)
{
    //the default constructor
}


Product::Product(string prod,string identifier,double price,long int quantity )
{
    name=prod;
    setProduct_ID(identifier);
    setUnit_price(price);
    setAvailable_quantity(quantity);

}




Product::~Product()
{
     //the destructor
}



void Product::setAvailable_quantity(long int num)
{
   available_quantity=(num>=0)?num:0;
}


void Product::setUnit_price(double price)
{
    unitprice=(price>0)?price:0;
}


void Product::setProduct_ID(string identifier)
{
    if( ID.length()<=191)
    {
        if(existentID(identifier)==false)
            {ID=identifier;}
            else { cout<<" The identifier you inserted already exists"<<endl;}   //i should here check also if it's a set of digits only
    }
    else{cout<<"The number of digits cannot exceed 191!"<<endl;}


}



long int Product::getAvailable_quantity(void)const
{
    return available_quantity;
}



double Product::getUnitprice(void)const
{
  return unitprice;
}


string Product::getProduct_ID(void)const
{
    return ID;
}





void Product::ProductDescription(void)const
{
   cout<<" Product Name: "<<name<<endl;
   cout<<" Product ID: "<<ID<<endl;
   cout<<" Product Unit Price: "<<unitprice<<endl;
   cout<<" Product Quantity: "<<available_quantity<<endl;
   cout<<endl;


}

