#include<iostream>
using namespace std;
#include "functions.h"
#include"User.h"
#include "Shop.h"

#include <fstream>

// inclue chrono to compute time c

Shop myshop;  // global object

void add_to_file ()
{
       ofstream file_write_obj;
       file_write_obj.open("user_data.txt", ios::out);


     for(pair<string,User>it: myshop.users_map)
     {

         file_write_obj.write((char*)&it.second, sizeof(it.second));

     }

        file_write_obj.close();


    file_write_obj.open("Categorie_data.txt",ios::out);

     for(int i=0; i<myshop.categories.size(); i++)
     {
        file_write_obj.write((char*)&(myshop.categories[i].Category_name), sizeof(myshop.categories[i].Category_name));
     }

    file_write_obj.close();


    file_write_obj.open("Product_data.txt",ios::out);


          for(auto position: myshop.categories)
          {
              for(pair<string,Product>iter:position.storage_house )
              {

                  file_write_obj.write((char*)&iter.second, sizeof(iter.second));

              }
          }


          file_write_obj.close();

}




void read_from_file( )
{
    ifstream file_read_obj;

    // to add users to users_file
    file_read_obj.open("user_data.txt", ios::in);

    while (!file_read_obj.eof())
    {
       User obj;
       file_read_obj.read((char*)&obj, sizeof(obj));
       myshop.add_user(obj);
    }

    file_read_obj.close();


      // to add categories to category_file
    file_read_obj.open("Categorie_data.txt",ios::in);

         while (!file_read_obj.eof())
         {
               string cat_name;
               file_read_obj.read((char*)&(cat_name), sizeof(cat_name));
               myshop.add_category(cat_name);
         }

    file_read_obj.close();


     // to add products to product_file
    ifstream file_read_product;
    file_read_product.open("Product_Data.txt", ios::in);

    while (!file_read_product.eof())
    {
       Product produit;
       file_read_product.read((char*)&produit, sizeof(produit));
       myshop.add_product(produit);
    }

    file_read_product.close();

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
   cout<<" 4- Add to basket . " <<endl;
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


case 4: // adding to basket
 {

 cout<< " your basket "<<endl;
// show the categories
 order Commande ;
 char x;
 string ID, Category;
 int num;

 do{

      cout<<" enter the informations of the product  that you want to buy "<<endl;
      cout<< " Category " ;
      cin>> Category;
     // show the product

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



    //read_from_file();

    int a;

    cout<<" -------------------------- INTERNET SHOPPING SYSTEM -------------------------------"<<endl;

    cout<<"\nAre You : "<<endl;
    cout <<"1- Buyer "<<"\t"<<"2-Seller "<<"\t"<<"3- responsable "<<endl;

    cin>>a;


           while( a!=1 && a!=2 && a!=3 )
            {
                cout<<"Invalid answer ! please try again ( Enter 1 or 2 ) "<<endl;
                cin>>a;
            }




switch (a){


case 1:   // user case
{

 cout<< " Hello user "<<endl;
 cout<<"1- Sign in "<<"\t"<<"2- Sign up"<<endl;

        int b;
        cin>>b;

           while(b!=1 && b!=2)
            {
                cout<<"Invalid answer ! please try again ( Enter 1 or 2 )  "<<endl;
                cin>>b;
            }



  switch (b)
{

case 1 :   // log in

  {
        string name, pw ;
         bool account_changed=false;

    cout<< "  ----------------------- Welcome to our online shop ----------------------- "<<endl;
    cout << " Please  fill the following information "<<endl;

             cout<<" Name : ";
             getline(cin>>ws,name);

             auto it = myshop.users_map.find(name);
             User* customer =&(it->second);

             while(it==myshop.users_map.end())
             {

                cout<< " This user name doesn't exist "<<endl;
                cout<<"1- Create an account \t  2- Try again"<<endl;


                int reponse;
                cin>>reponse;

                  while(reponse!=1 && reponse!=2 ){

                        cout<< " invalid answer , please try again . ";
                         cin>>reponse;
                  }


                if( reponse == 1)
                {
                    customer=create_an_account();
                    cout<<"Account created successfully ! " <<endl;
                    account_changed=true;
                    break;
                }


                else
                {

                  cout<<" Name : ";
                  getline(cin>>ws,name);

                  it = myshop.users_map.find(name);
                  customer =&(it->second);

                }


              } // if user-name already exist



             if(!account_changed)
             {
                cout<<" Enter password : ";
                getline(cin>>ws,pw);


                while(it->second.get_password()!=pw)
                     {
                         cout<<"Invalid password , try again !"<<endl;
                         getline(cin>>ws,pw);
                     }
             }


int reply;
char x;

do {
      display_services();

      cin>>reply;
      do_service(reply,customer);
      cout<< " return to the services   y/n " <<endl;
      cin>>x;

}while(x=='y');


break;

  } // case 1



case 2 :  // register
{

cout<< "  ----------------------- Welcome to our online shop ----------------------- "<<endl;

  User* customer=create_an_account();
  cout<< " Hello " <<customer->get_name();

 char x;
 int replay;

  do {
      display_services();
      do_service(replay,customer);

      cout<< " return to the services   y/n " <<endl;
      cin>>x;

}while(x=='y');

break;

}


}

if()//??????????????????????????????????????????
{

order removed_from_queue;
double price=0;
removed_from_queue=myshop.remove_request();
myshop.bill(removed_from_queue , price );


cout<<" Confirm purchase : "<<endl;
int confirmation;
cin>>confirmation;

if(myshop.check_if_payed(confirmation,removed_from_queue,price))
    {
        myshop.delivery(removed_from_queue);
    }
}




break;

} // end of case user --------------------------------------------------------------------------------------------


case 2:  // seller case
 {

  int answer;

do {
   cout<<" Welcome to seller services ,how can I help you ?"<<endl;
   cout<<" 1- Display  the existing categories . " <<endl;
   cout<<" 2- Add a new product ." <<endl;
   cout<<" 3- Remove a product . " <<endl;
   cout<<" 4- Exit . " <<endl;
   cin>>answer;


        switch(answer){

case 1 :
{
   cout<<" ____________________the existing categories____________________ "<<endl;
   int i=0;
   for( auto it : myshop.categories)

    {
     cout<<i<<"- "<<it.Category_name << endl;
     i++;

    }

    break;
}

case 2 :
{
    cout<< " ____________________Adding a   new product____________________ " <<endl;

    cout<< "the available categories :"<<endl;

    int i=0;
   for( auto it : myshop.categories)
    {
     cout<<i<<"- "<<it.Category_name << endl;
     i++;
   }
   cout<<" enter the category of your product "<<endl;
   string category;
   cin>> category;


   // if the product exist and he want to increamenet the quantity ???? but i think it's better to add it as a case in the function add_product because the seller won't know it the product exists or no

   string Name , id;
    double price;
    long int  quantity;

   cout<< "  Please enter the description of your product " <<endl;

   cout<< " Name : ";
   cin>> Name;
   cout<< " ID : ";
   cin>> id;
   cout<< "  The unit price : ";
   cin>> price;
   cout<< " The quantity : ";
   cin>> quantity;

   Product produit( Name ,category, id , price , quantity );
   myshop.add_product(category,produit);
   break;

}


case 3 :
{
    cout<< " ____________________Removing a product____________________ " <<endl;
    cout<< " Enter the name of the product :  ";
    string product;
    cin>>product;
     myshop.remove_product(product);
     // you wonder if he does npt know the name of the product what can he do !!! logically he knows the name since he is the seller
     //otherwise we can display the products that he already added and separate files ......

     // we assume that the seller removing his own products
     // otherwise we'll be obliged to separate the list of products of each seller and check for each operation
     break;
}


case 4:
    exit(1);

default :
    cout<<"Invalid answer ! please try again "<<endl;
    cin>>answer;

}

} while (answer);

break;

 }

case 3: // a responsable  of the online  shop
{

 int answer;
 do{
   cout<<" Welcome to responsable services ,how can I help you ? "<<endl;
   cout<<" 1- Display  the existing categories . " <<endl;
   cout<<" 2- Add a new category . " <<endl;
   cout<<" 3- Remove a category . " <<endl;
   cout<<" 4- Exit . " <<endl;
   cin>>answer;

   switch(answer){

case 1 :
{
   cout<<" ____________________the existing categories____________________ "<<endl;
   int i=0;

   for( auto it : myshop.categories)
    {
     cout<<i<<"- "<<it.Category_name << endl;
     i++;
    }

   break;
}


case 2 :
{
    cout<< " ____________________Adding a new category____________________ " <<endl;
     cout<< " Name " ;
     string category;
     cin>>category;
     myshop.add_category(category) ;
     break;
}


case 3 :
{
    cout<< " ____________________Removing a category____________________ " <<endl;
    cout<< " Enter the name of the category :  ";
    string category;
    cin>>category;
     myshop.remove_category(category) ;
     break;

}

case 4 :
exit(1);


default :
    cout<<"Invalid answer ! please try again "<<endl;
}


 }
while ( answer != 4);

break;

}


}






cout<<" Thank you for your visit "<<endl;


    add_to_file();

return 0;
}
