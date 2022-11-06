#include "Shop.h"

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

void Shop::add_user(User user)
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











