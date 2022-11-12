#include "Product.h"
#include <string>
#include <iostream>
#include <ctype.h>


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
    if( ID.length()<=12)
    {
        for(int i=0;i<identifier.length();i++)
        {
          if(!isdigit(identifier[i]))
            {
                cout<<"The ID is composed only of numbers "<<endl;
                 break;
            }
        }
    }

       if( ID.length()<=12)
       {


        if(existentID(identifier)==false)
            {ID=identifier;}
            else { cout<<" The identifier you inserted already exists"<<endl;}   //i should here check also if it's a set of digits only or no
    }
    else{cout<<"The number of digits cannot exceed 191!"<<endl;}


}




void Product::add_quantity(long int more )
{
   if(more>=0)
   {
       available_quantity+=more;
   }
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



string Product::getProduct_name(void)const
{
    return name;
}




void Product::ProductDescription(void)const
{
   cout<<" Product Name: "<<name<<endl;
   cout<<" Product ID: "<<ID<<endl;
   cout<<" Product Unit Price: "<<unitprice<<endl;
   cout<<" Product Quantity: "<<available_quantity<<endl;
   cout<<endl;


}

//void Product::enter_info_product(void){} ???????????




bool Product::operator==( Product  pro)const
{
    if(name==pro.name && ID==pro.ID && unitprice==pro.unitprice )
        return true;
}


bool Product::operator!=( Product  produit)const
{
    return !(*this==produit);
}



Product Product::operator=(const Product& produit)
{
         name=produit.name;
         ID=produit.ID;
         unitprice=produit.unitprice;
         available_quantity=produit.available_quantity;


         return (*this);
}

