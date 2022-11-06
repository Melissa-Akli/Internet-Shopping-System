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

      vector<Category>::iterator position;


  for(position=categories.begin();position!=categories.end();position++)
     {
         if(position->Category_name==name)
            break;
     }


     if(position != categories.end())
     {
         categories.erase(position);
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



    void Shop::remove_request() // the online shop will serve the customer : check if it exists then check if memeber , increase total purchase return the total price
    {
        /*if(!check_request(order1))
        {
        cout<<" order not found"<<endl;
        return NULL;
        }
    else {*/
         commande.pop();


    }












