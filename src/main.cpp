#include<iostream>
using namespace std;
#include "functions.h"
#include"User.h"
#include "Shop.h"

#include <fstream>

// inclue chrono to compute time c

Shop myshop;  // global object
void add_to_file_map_user()
{
    string name;
    double member;
    Card Credit;
    address Home_add;
    string pass;



    ofstream os;
    os.open("user_data.txt", ios::out);     // it will delete everything in the file and add all objects from scratch

    for(pair<string,User>it: myshop.users_map)
    {
        name=(it.second.get_name());
        member=(it.second.get_membership_count());
        Credit.number=(it.second.get_card()).number;
        Credit.ExpiryDate=(it.second.get_card()).ExpiryDate;
        Home_add=(it.second.get_address());
        pass=(it.second.get_password());


        /*os<<name<<","<<member<<","<<Credit.number<<",";
        os<< Credit.ExpiryDate.day<<","<< Credit.ExpiryDate.month<<","<< Credit.ExpiryDate.year<<",";
        os<<Home_add.region<<","<<Home_add.street<<","<<Home_add.home_number<<",";
        os<<pass<<endl;    // don't forget endl otherwise it will write everything in one file*/

        os<<name<<endl;
        os<<member<<endl;
        os<<Credit.number<<endl;
        os<< Credit.ExpiryDate.day<<endl;
        os<< Credit.ExpiryDate.month<<endl;
        os<< Credit.ExpiryDate.year<<endl;
        os<<Home_add.region<<endl;
        os<<Home_add.street<<endl;
        os<<Home_add.home_number<<endl;
        os<<pass<<endl;
    }
}





void add_to_file_categories(void)
{
    string name;



    ofstream os;
    os.open("categories.txt",ios::app);


    for(auto it:myshop.categories)
    {
        name=it.Category_name;

        os<<name<<endl;
    }

}



void add_to_file_storagehouse(void)
{
   string productname;
   string categorie;
   string productID;
   double price;
   long int quantity;

   ofstream os;
   os.open("products.txt",ios::app);

  for(auto position:myshop.categories)
  {


  for(pair<string,Product>it: position.storage_house)
    {
        productname=(it.second.getProduct_name());
        categorie=(it.second.category_name);
        productID=(it.second.getProduct_ID());
        price=(it.second.getUnitprice());
        quantity=(it.second.getAvailable_quantity());



        os<<productname<<endl;
        os<<categorie<<endl;
        os<<productID<<endl;
        os<<price<<endl;
        os<<quantity<<endl;
    }

  }




}

void read_from_file_user()
{

   ifstream read;
   read.open("user_data.txt");
   if(!read.is_open()) cout<<"File failed to open!"<<endl;

  if(read.peek()==EOF)cout<<"Empty file"<<endl;
  else
  {


    string name;
    double member;
    Card Credit;
    address Home_add;
    string pass;

    string line;

    while(!read.eof())
    {


        getline(read,name );
        getline(read,line );

        member=atof(line.c_str());
        getline(read,Credit.number);

        getline(read,line );
        Credit.ExpiryDate.day=(int)atof(line.c_str());

        getline(read,line );
        Credit.ExpiryDate.month=(int)atof(line.c_str());

        getline(read,line );
        Credit.ExpiryDate.year=(int)atof(line.c_str());

        getline(read,Home_add.region );
        getline(read,Home_add.street );

        getline(read,line );
        Home_add.home_number=(int)atof(line.c_str());

        getline(read,pass );



    User user( name,pass, Home_add.region ,Home_add.street, Home_add.home_number,Credit.number , Credit.ExpiryDate.day,Credit.ExpiryDate.month,Credit.ExpiryDate.year );
        user.update_membership(member);

       myshop.add_user(user);





}

  }



}







void read_from_file_category()
{

   ifstream read;
   read.open("categories.txt");
   if(!read.is_open()) cout<<"File failed to open!"<<endl;

  if(read.peek()==EOF)cout<<"Empty file"<<endl;
  else
  {


    string name;


    while(!read.eof())
    {


        getline(read,name );






       myshop.add_category(name);





}

  }



}




void read_from_file_product()
{

   ifstream read;
   read.open("products.txt");
   if(!read.is_open()) cout<<"File failed to open!"<<endl;

  if(read.peek()==EOF)cout<<"Empty file"<<endl;
  else
  {


    string name;
    string categorie;
    string ID;
    double price;
    long int quantity;

    string segment;


    while(!read.eof())
    {


        getline(read,name );
        getline(read,categorie );
        getline(read,ID);
        getline(read,segment);

        price=atof(segment.c_str());

        getline(read,segment);
        quantity=(long int)atof(segment.c_str());






       Product produit(name,categorie,ID,price,quantity);
       myshop.add_product(produit);





}

  }



}








//------------------------------------Functions --------------------------------------------------------------------------------

void add_to_order(int n, Product t,order& ORDER)
{
   if(myshop.check_product(t.ID))
    ORDER.add_item(n,t);

}


User* create_an_account(){

string name;

      cout<<"Enter Your Information : "<<endl;
      cout<<"Name: ";
      getline(cin>>ws, name );


        // checking name's validity
             while(!valid_username(name))
             {
               cout<<"Invalid user name, try again !"<<endl;
               cout<<"Name: ";
               getline(cin>>ws, name );
             }


    myshop.add_user(name);
    auto t=&(myshop.users_map.find(name)->second);

 return t;

}


void display_services(){


   cout<<" How can I help you ?"<<endl;
   cout<<" 1- See profile . " <<endl;
   cout<<" 2- Modify profile . " <<endl;
   cout<<" 3- Explore our products ." <<endl;
   cout<<" 4- Add to cart . " <<endl;
   cout<<" 5- Exit . " <<endl;


}

void update_profile(Shop myshop, User& user)
{
    int a ;

    cout<<" what do you want to modify "<<endl;
    cout <<" 1- Username  "<<endl;
    cout <<" 2- Home address "<<endl;
    cout <<" 3- CreditCard "<<endl;
    cout <<" 4- password "<<endl;

    cin>>a;

   switch(a)
   {

    case 1:
{
    user.update_name();
    break;
}

    case 2:
{
    user.update_address();
    break;
}

    case 3:
{
    user.update_creditCard();
    break;
}

    case 4:
{
    user.get_password();
    break;
}

    default:
        exit(1);
   }

}




void do_service(int  choice , User* Myuser  )
{

User user=*Myuser;

  switch (choice) {

case 1 :  // viewing the profile
    {
        user.display_profile();
        break;
    }

case 2 : // modifying the profile
    {
        update_profile(myshop ,user);
        break;
    }

case 3 : // exploring the products
   {

    cout<<" the categories "<<endl;
    myshop.display_categories();


    cout<<" please enter the name of the category "<<endl;
    string category_name;
    cin>>category_name;

    myshop.display_products(category_name);
    break;

   }


case 4: // adding to cart
 {

 cout<< " your shopping cart "<<endl;

// show the categories
 order Commande ;
 char x;
 string ID, Category;
 int num;

 do{

      cout<< " Enter the category  " ;
      cin>> Category;
     // show the product

     cout<< " The products : " <<endl;
myshop.display_products(Category);

cout<<" enter the informations of the product  that you want to buy "<<endl;

      cout<< " the ID " ;
      cin>> ID;

      cout<< " the quantity" ;
      cin>>num;

Product t;

if(myshop.check_product(ID)!=true)
{
    cout<<"We are sorry, the product you are searching for is not available §"<<endl;
}


else{

 for(auto it:myshop.categories)

     {
       if(it==Category)
       {
           t=it.storage_house.find(ID)->second;
       }
     }
 }

add_to_order(num,t,Commande);


 cout<< " want to add another product ?    (y/n)" <<endl;
 cin>>x;

 } while (x== 'y') ;
  // check if order is not null

  myshop.add_request(Commande);
   break;


 }

default : exit(1);

}

}


//----------------------------MAIN-----------------------------------------------------------------------------------------------

int main()
{




read_from_file();
for(pair<string,User>it: myshop.users_map)
{
    it.second.display_profile();
}

create_an_account();
create_an_account();

Category cat("Food");
Product produit("bimo","Food","123456789",230.00,123);
//create_an_account();

cout<<" Thank you for your visit "<<endl;


add_to_file_map_user();
add_to_file_categories();
add_to_file_storagehouse();


return 0;
}
