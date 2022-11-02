#include <iostream>

using namespace std;
/*
-usinf the principle of c++11 (big five)
-usefull comment
- better to add to each classe operator =,==,!=  we will need it latter
- nitice: we have to focus on the main points first the we can add additional fonctionalities
*/

class shop
{

      // hash table to store users
    priority_queue<order> commande; // periority queue  of different requests first in
     //unordered map to store products
public:
    shop();// constructor =0  no need to add details
    //users
    void add_user();// to insert a user inside the hash table
    void remove_user();// to remove a user
    bool check_if_user();// if he has an account    searching in the hash table

    // products
    void add_product();// check if it exist we increase the availabe-quentity otherwise we create a new product
    void decrease_quantity();// delete product
    void remove_product();// if availabe-quentity>1 we decrease availabe-quentity  else availabe-quentity???
    bool check_product(); // check if the product is available or not

    // request
    void add_request(); // customer will contact the shop  , we will get his info
    int remove_request(); // the online shop will serve the customer : check if it exists then check if memeber , increase total purchase return the total price
    bool check_request(); // before serving the customer


    // later implementation
    int delivery(); // will use the remove_request function  , calculate distance and return price
    int bill();// price of delivery +purchase+ , increase total purchase
    void showbill();// print the list of ordered items and the price
    bool pay_bill();// check if the bill is successfully payed   ??? how




};














