#include<iostream>
using namespace std;
#include "functions.h"
#include"User.h"
#include<Shop.h>
#include <fstream>

// inclue chrono to compute time c



void add_to_file (Shop myshop)
{
        ofstream file_write_obj;
       file_write_obj.open("user_data.txt", ios::out);


     for(pair<string,User>it: myshop.users_map)
     {

         file_write_obj.write((char*)&it.second, sizeof(it.second));

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




void read_from_file( Shop myshop )
{
    ifstream file_read_obj;
    file_read_obj.open("mydata.txt", ios::in);

    while (!file_read_obj.eof())
    {
       User obj;
       file_read_obj.read((char*)&obj, sizeof(obj));
       myshop.add_user(obj);
    }

    file_read_obj.close();



    ifstream file_read_product;
    file_read_product.open("Product_Data.txt", ios::in);

    while (!file_read_product.eof())
    {
       Product produit;
       file_read_product.read((char*)&produit, sizeof(produit));
       myshop.add_product(produit.getProduct_ID());
    }

    file_read_product.close();


}







int main()
{





    Shop myshop;
    read_from_file( myshop );

    int a;
    string name;
    string pass;

    cout<<" -------------------------- INTERNET SHOPPING SYSTEM -------------------------------"<<endl;

    cout<<"\nAre You : "<<endl;
    cout <<"1- Buyer "<<"\t"<<"2-Seller "<<<<"\t"<<"3- responsable "<<endl;

    cin>>a;


           while( a!=1 && a!=2 && a!=3 )
            {
                cout<<"Invalid answer ! please try again ( Enter 1 or 2 ) "<<endl;
                cin>>a;
            }




switch (a){


case 1:   // user case

 cout<< " Hello user "
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

    string name, pw;
    cout<< "  ----------------------- Welcome to our online shop ----------------------- "
    cout << " Please  fill the following information "<<endl;

             cout<<" Name : ";
             getline(cin>>ws,name);

             auto it = myshop.users_map.find(name);

             if(it!=myshop.users_map.end())
             {
                 cout<<" Enter password : ";
                 getline(cin>>ws,pass);

                while(it->second.get_password()!=pass)
                     {
                         cout<<"Invalid password , try again !"<<endl;
                         getline(cin>>ws,pass);
                     }

             }
             else {
                cout<< " this username does not exist , would you like to create an account (y/n)  "
                char x;
                cin>>x;
                if( x == 'y') create_an_account();
                else break;
    }

do {
      display_services();
      int replay;
      cin>>replay;
      do_service(replay);
      cout<< " return to the services   y/n " <<endl;
      char x;
      cin>>x;

}while(x=='y')

break;


case 2 :  // register
    cout<< "  ----------------------- Welcome to our online shop ----------------------- "
     User customer;
  create_an_account(customer);
cout<< " Hello " <<customer.name;

  do {
      display_services();
      int replay;
      do_service(replay);
      cout<< " return to the services   y/n " <<endl;
      char x;
      cin>>x;

}while(x=='y')

}






case 2:      // seller case
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
   cout<<" ____________________the existing categories____________________ "<<endl;
   int i=0;
   for( auto it : myshop.categories)
    {
     cout<<i<<"- "<<it.Category_name << endl;
     i++;
   }

case 2 :
    cout<< " ____________________Adding a   new product____________________ " <<endl;
    cout<< "the available categories"
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
   cout<< " The guantity : ";
   cin>> quantity;

   Product produit( Name , id , price , quantity );
   myshop.add_product(category,produit);



case 3 :
    cout<< " ____________________Removing a product____________________ " <<endl;
    cout<< " Enter the name of the product :  ";
    string product;
    cin>>product;
     myshop.remove_product(product);
     // you wonder if he does npt know the name of the product what can he do !!! logically he knows the name since he is the seller


case 4:
    exit(1);

default :
    cout<<"Invalid answer ! please try again "<<endl;
    cin>>answer;
}

} while (answer)





case 3: // a responsable  of the online  shop

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

   cout<<" ____________________the existing categories____________________ "<<endl;
   int i=0;
   for( auto it : myshop.categories)
    {
     cout<<i<<"- "<<it.Category_name << endl;
     i++;
   }

case 2 :
    cout<< " ____________________Adding a new category____________________ " <<endl;
     cout<< " Name " ;
     string category;
     cin>>category;
     myshop.add_category(category) ;


case 3 :
    cout<< " ____________________Removing a category____________________ " <<endl;
    cout<< " Enter the name of the category :  ";
    string category;
    cin>>category;
     myshop.remove_category(category) ;


case 4 :
exit(1);


default :
    cout<<"Invalid answer ! please try again "<<endl;
}


 }
while ( answer != 3);

}




order removed_from_queue;
double price=0;

removed_from_queue=Myshop.remove_request();

myshop.bill(removed_from_queue , price );

cout<<" Confirm purchase "<<endl;
int confirmation;
cin>>confirmation;

if(myshop.check_if_payed(confirmation,removed_from_queue,price))
    {
    myshop.delivery();

}

cout<<" Thank you for your visit "<<endl;


    add_to_file(myshop);

return 0;
}
