//
// Created by hty on 2021/8/12.
//

#ifndef C_PRIMER_PLUS_SALES_H
#define C_PRIMER_PLUS_SALES_H


class Sales {
private:
    enum {QUARTERS = 4};
    double sales[QUARTERS];
    double average_;
    double max_;
    double min_;
public:
    Sales();
    Sales(double ar[], int n);
    void showSales();
};


#endif //C_PRIMER_PLUS_SALES_H
