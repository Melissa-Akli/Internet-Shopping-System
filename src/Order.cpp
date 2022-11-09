#include "order.h"
#include<iostream>
#include <algorithm>
#include <iomanip>
#include "Shop.h"

using namespace std;
/*using std::list;
using std::cout;
using std::endl;*/


order::order(User user)
{

    customer=user;

}
order::order()
{

}



order:: ~order()
{
    ordered_item.clear();
}



void order::add_item(int n, Product t) // n: the number of item for product t

{    if(Myshop.check_product(t.ID) && t.available_quantity>=n ){   // checking if the product exist with acceptable ammont before adding it to the order
    item p(n,t);
    ordered_item.push_front(p);
}
}



void order::remove_item(int n, Product &t)
{
    item p(n,t);
    ordered_item.remove(p);

}




void order:: show_order(){

    int i=1;

    cout<<setw(4)<<" item "<<setw(5)<<" name "<<setw(5)<<"quantity"<<endl;

for(auto itr=ordered_item.begin();itr!=ordered_item.end();itr++){

    cout<<setw(4)<< i<<setw(5)<< (*itr).p.name<<setw(5)<<(*itr).quantity<<endl;
}

}




bool order::check_item(item t)// we will check the unordered maps if it contains the element
{
   return (find( ordered_item.begin(),ordered_item.end(),t)!=ordered_item.end());

}


bool order::operator == (  order  order1 )
{
    return order1.customer.checkMembership() && (*this).customer.checkMembership();
}

bool order::operator != (   order  order1 )
{
    return ! (*this==order1);
}


bool order::operator <  (   order  order1 )
{
    return !((*this).customer.checkMembership()) && order1.customer.checkMembership();
}

bool order::operator >  (   order  order1 )
{
    return (*this).customer.checkMembership() && !(order1.customer.checkMembership());
}




