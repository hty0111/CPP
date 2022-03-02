//
// Created by hty on 2021/9/3.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;

//从range中选择number个数字，返回一个int矢量
vector<int> lotto(int range, int number);
void show(int n) { cout << n << " "; }

int main()
{
    srand((int)time(0));
    int range, number;
    cout << "Enter range: ";
    cin >> range;
    cout << "Enter number: ";
    cin >> number;
    vector<int> result = lotto(range, number);
    for_each(result.begin(), result.end(), show);
    cout << endl;
}

vector<int> lotto(int range, int number)
{
    vector<int> temp;
    for (int i = 0; i < range; i++)
        temp.push_back(i);
    random_shuffle(temp.begin(), temp.end());
//    vector<int>::iterator last;
//    last = (temp.begin(), temp.begin() + number);
//    temp.erase(last, temp.end());//取前六位数字
    temp.resize(number);
    return temp;
}