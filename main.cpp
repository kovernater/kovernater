#include <iostream>
#include "class.h"

int main()
{
    Shop My_shop(3);
    Shop My_shop2(3);


    My_shop.set_value_of_product(5, 0);
    My_shop.set_value_of_product(3, 1);
    My_shop.set_value_of_product(7, 2);
   // My_shop.print_value();

    My_shop2.set_value_of_product(1, 0);
    My_shop2.set_value_of_product(4, 1);
    My_shop2.set_value_of_product(11, 2);
   // My_shop2.print_value();

    //(My_shop += My_shop2);
    

    Shop My_shop3(My_shop);
    My_shop3 = My_shop + My_shop2;
    My_shop3.print_value();
    My_shop.is_enough_money(20);

    My_shop.~Shop();
    My_shop2.~Shop();
    My_shop3.~Shop(); 

    return 0;
}