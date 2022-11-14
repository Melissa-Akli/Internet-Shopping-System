#include "Shop.h"

using namespace std;


Shop::Shop()
{
    //ctor
}

Shop::~Shop()
{
    //dtor
}


// add a new user
void Shop::add_user(string name)
{
    // BECAUSE FIND RETURNS AN ITERATOR TO THE value if it exist if not it'll return an eterator to the end
   while(users_map.find(name)!=users_map.end())
   {
    cout<<" This user_name already exist , please try again ! "<<endl;
     cout<<"Name : "<<endl;
     getline(cin>>ws, name );

     // checking name's validity
             while(!valid_username(name))
             {
               cout<<"Invalid user name please try again !"<<endl;
               cout<<"Name: ";
               getline(cin>>ws, name );
             }

      }

       users_map[name]=User{name};

}


// add an existing user
void Shop::add_user (User user)
{
    if(users_map.find(user.get_name())==users_map.end())
       {
           users_map.insert({user.get_name(), user});
       }
}


 void Shop::delete_user(string key)
 {

    users_map.erase(key);

 }




void Shop::add_category( string type)
 {

     vector<Category>::iterator it;

     // couldn't use the function find because here we're searching for the name of the category only not the category
     //itself so i had to use a loop

     for(it=categories.begin();it!=categories.end();it++)
     {
         if((it->Category_name)==type)
            break;
     }


     if(it != categories.end())
     {
         cout<<"This Category does already exist!"<<endl;
     }
     else{
        Category categorie(type);
        categories.push_back(categorie);
     }
 }




 void Shop::remove_category(string name)
 {


      auto position=categories.begin();


  for( ;position!=categories.end(); position++)
     {

         if(position->Category_name==name)
            break;

     }


     if(position != categories.end())
     {
         categories.erase(position);
         cout<<"The category "<<name<<" has been deleted"<<endl;
     }

 }




 void Shop::add_product(Category type, const Product& produit)
 {
    //vector<Category>::iterator it;
     for(auto it:categories)
     {
         if((it.Category_name)==type.Category_name)
         {
            it.insertproduct(produit);
         }
         else{

            add_category(type.Category_name);

         }
     }

 }


 void Shop::add_product(Product produit)
 {
    for(auto it: categories)
    {


     if(it.storage_house.find(produit.getProduct_ID())!=it.storage_house.end())
       {
           it.storage_house.insert({produit.getProduct_ID(), produit});
       }

    }

 }






 bool Shop::check_product(string id)
 {
   /* vector<Category>::iterator it;*/
     for(auto it:categories)
     {
       if(it.storage_house.find(id)!=it.storage_house.end())
       {
          return true;
       }
     }

 }


void Shop::add_request(order& order1)
    {
        commande.push(order1);
    }



    order Shop::remove_request() // the online shop will serve the customer : check if it exists then check if memeber , increase total purchase return the total price
    {
        order top= commande.top();
         commande.pop();

        return top;
    }


void Shop::bill(order myorder ,double& price)
 {
        myorder.show_order();
    double total_price =0;

    for(auto it :myorder.ordered_item)
    {
        total_price+=(it.p.getUnitprice())*(it.quantity);
    }

    cout <<"Order price = "<<total_price<<" DA"<<endl;
    cout<<"Delivery fees : "<<" 400 DA "<<endl;
    cout<<"Total price : "<<total_price+400<<endl;

    price = total_price+400;

}

bool Shop::check_if_payed(int answer ,order myorder, double total_price  )
{
    if(answer==1)
    {
        if (myorder.customer.check_CreditCard_validity())
        {
            users_map[myorder.customer.get_name()].update_membership(total_price);
            for(auto it: myorder.ordered_item){

                for(auto itr:categories)
                {
                   auto t=itr.storage_house.find( it.p.getProduct_ID() );

                    if(t !=itr.storage_house.end())
                  {
                        (t->second).reduce_quantity(it.quantity);

                  }
                }

            }

        }
      return true;
    }

    return false;
}


void Shop:: delivery( order x){

cout<< " your order " <<endl;
x.show_order() ;
cout<<" Has been accomplished successfully , to be delivered to  " <<x.customer.get_address().home_number<<" - "<<x.customer.get_address().street<<" - "<<x.customer.get_address().region<<endl;
cout<<" in these 3 coming days "<<endl;

}




void Shop::display_categories(void)
{
    for(auto it:categories)
    {
        cout<<it.Category_name;
    }
}



void Shop::remove_product(string produit_ID)
 {

    for(auto it:categories)
     {
       if(it.storage_house.find(produit_ID)!=it.storage_house.end())
       {
         it.storage_house.erase(produit_ID);
       }
       else{

        cout<<"it doesn't even exist "<<endl;
       }
     }

 }






 void Shop::display_products(Category type)
{
    for(auto it:type.storage_house)

    {
       it.second.ProductDescription();

    }

}









