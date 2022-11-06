#include "Category.h"


Category::Category()
{

}

Category::~Category()
{
    //dtor
}



Category::Category(string type)
{
    Category_name=type;
}



void Category::insertproduct(Product produit)
{
  if(storage_house.find(produit.getProduct_ID())==storage_house.end())
       {
           storage_house.insert({produit.getProduct_ID(), produit});
       }
    else{
          storage_house.find(produit.getProduct_ID())->second.add_quantity(produit.available_quantity);      // I don't know if it's feasible 
    }
}
