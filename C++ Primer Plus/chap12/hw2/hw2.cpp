//
// Created by hty on 2021/8/17.
//

#include "string0.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    String zxa, hty("hty"), mhy("mhy");
    zxa = "zxa";
    hty = zxa + hty;
    cout << zxa << endl << hty << endl << mhy << endl;
    cout << hty.howMany() << endl;
}