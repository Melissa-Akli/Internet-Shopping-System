#include<list>


#ifndef ORDER_H
#define ORDER_H

class Order
{
    public:
        Order();                       // NEED WORK
        virtual ~Order();             // NEED WORK
        void DeleteItem();                 // NEED WORK
        void AddItem();                      // NEED WORK
        void Display_PurshaseList();        // NEED WORK




    private:
        bool membership;
      // because if the user choose to send an order we gotta create the order i  the main
      // the we compare it in the main using time and membership

   // list <Item> PurshaseList;   // define item structure and make order friend of other classes

};

#endif // ORDER_H
