//
// Created by hty on 2021/8/12.
//

#include "sales.h"
#include <iostream>

Sales::Sales()
{
    for (int i = 0; i < QUARTERS; i++)
    {
        sales[i] = 0;
    }
    average_ = max_ = min_ = 0;
}

Sales::Sales(double ar[], int n)
{
    if (n > QUARTERS)
        n = QUARTERS;
    int i;
    max_ = min_ = ar[0];
    double sum = 0;
    for (i = 0; i < n; i++)
    {
        sales[i] = ar[i];
        if (ar[i] < min_)
            min_ = ar[i];
        if (ar[i] > max_)
            max_ = ar[i];
        sum += ar[i];
    }
    average_ = sum / n;
    for ( ; i < QUARTERS; i++)
    {
        sales[i] = 0;
    }
}

void Sales::showSales()
{
    std::cout << "sales: ";
    for (int i = 0; i < QUARTERS; i++)
    {
        std::cout << sales[i] << " ";
    }
    std::cout << "\nmax: " << max_ << "\nmin: " << min_ << "\naverage: " << average_ << "\n";
}
