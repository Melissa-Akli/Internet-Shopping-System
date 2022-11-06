#ifndef COMPARE_ORDER_H
#define COMPARE_ORDER_H

#include "order.h"



class compare_order// to become comparable
    {
        public:

       bool operator ()( order order1, order order2){

       return ((order1.customer.checkMembership())&& !(order2.customer.checkMembership() ) );

       }

    };

#endif // COMPARE_ORDER_H
