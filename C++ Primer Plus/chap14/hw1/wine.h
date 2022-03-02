//
// Created by hty on 2021/8/30.
//

#ifndef CPP_WINE_H
#define CPP_WINE_H

#include <iostream>
#include <valarray>
#include <cstring>
#include <utility>
using namespace std;

class Wine {
private:
    typedef valarray<int> ArrayInt;
    typedef pair<ArrayInt, ArrayInt> PairArray;
    int yearNum;    //年份的数量
    PairArray pa; //分别保存酿造年份和该年的生产瓶数
    string name;    //酒的名称
public:
    Wine() : name(""), yearNum(0), pa(0, 0) {}
    Wine(const char* n, int y) : name(n), yearNum(y) {}
    Wine(const char* n, int y, const int yr[], const int bot[]);
    void getBottles();  //提示用户输入信息
    int sum2();         //返回pair中第二个储存瓶数的总和
    string & label() { return name; }
    void show();        //显示名称，年份和对应的瓶数
};


#endif //CPP_WINE_H
