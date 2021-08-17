//
// Created by hty on 2021/8/12.
//

#include "sales.h"

int main()
{
    double sales[] = {1, 2, 3, 4, 5};
    int n = 3;
    Sales htySales;
    Sales zxaSales(sales, n);
    htySales.showSales();
    zxaSales.showSales();

    return 0;
}