#include "order.h"



using std::cout;
using std::endl;

order::order()
{

}
order:: ~order()
{
    ordered_item.clear();
}


/*list<item> order::get_order()const
{

    return ordered_item;
} // return the list of item*/


void order::add_item(int n, Product t) // n: the number of item for product t
{
    item p(n,t);
    ordered_item.push_front(p);

}



void order::remove_item(int n, Product t)
{
    item p(n,t);
    ordered_item.remove(p);
}


// not the final output i will make it better using the tools that we studied last year
void order:: show_order()
{
    int i=1;

   for(auto itr=ordered_item.begin() ; itr!=ordered_item.end() ; itr++)
    {
        cout<< "Item "<<i<<" : "<< (*itr).p.name<<"\t Quantity"<<(*itr).quantity<<endl;
    }

}
/*bool check_item(item t)// we will check the unordered maps if it contains the element
{
    // if it exists in the map then i'll return a copy of it  and let it be x
    if(x.name==t.product.name && x.available_quantity<=t.quantity) return true;
    return false;

}*/
