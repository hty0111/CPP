//
// Created by hty on 2021/5/30.
//

/*创建一个结构存储披萨公司的名字、披萨的直径和重量，用动态指针实现输入*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct pizza_info
    {
        string name;
        double diameter;
        double weight;
    };

    pizza_info * pt = new pizza_info;

    cout << "Input name, diameter and weight:\n";
    cin >> pt->name;
    cin >> pt->diameter;
    cin >> pt->weight;
    cout << pt->name << endl;
    cout << pt->diameter << endl;
    cout << pt->weight << endl;

    delete pt;
}