//
// Created by hty on 2021/8/20.
//

#include "port.h"
using namespace std;

int main()
{
    Port p1("Gallo", "tawny", 20);
    VintagePort p2("brand", "kind", 20, "nickname", 10);
    p2.show();
    VintagePort p3 = {p1, "The Noble", 10};
    p3.show();
}
