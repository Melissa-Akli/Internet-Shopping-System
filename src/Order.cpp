#include "order.h"
#include<iostream>



using std::list;
using std::cout;
using std::endl;


order::order(User user)
{
    ordered_item=NULL;
    customer=user;

}


order:: ~order()
{
    ordered_item.clear();
}



void order::add_item(int n, Product t) // n: the number of item for product t  

{    if(check_product(t) && t.available_quantity>=n ){   // checking if the product exist with acceptable ammont before adding it to the order
    item p(n,t);
    ordered_item.push_front(p);
}
}



void order::remove_item(int n, Product &t)
{
    item p(n,t);
    ordered_item.remove(p);
    // decrease the available quantity of product       "  t.available_quantity-=p.quantity;  "
}




void order:: show_order(){// not the final output i will make it better using the tools that we studied last year
    int i=1;
for(auto itr=ordered_item.begin();itr!=ordered_item.end();itr++){

    cout<< " item "<<i<<" : "<< (*itr).Product.name<<"         quantity"<<(*itr).quantity<<endl;
}

}




bool check_item(item t)// we will check the unordered maps if it contains the element
{
   return !(ordered_item.find(t)==NULL) 
    
}

