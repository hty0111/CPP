//
// Created by hty on 2021/8/12.
//

#include "list.h"
#include <iostream>

int main()
{
    List intList;
    Item item1 = 2;
    Item item2 = 3;
    Item item3 = 4;
    intList.insert(item1, 1);
    intList.insert(item3, 2);
    intList.insert(item2, 1);
    intList.delete_one(1);
    intList.delete_one(1);
    intList.delete_one(1);
    intList.show();

    return 0;
}