//
// Created by hty on 2021/8/31.
//

#include <iostream>
#include <vector>
#include <memory>       //智能指针
#include <algorithm>    //STL函数
#include <iterator>
using namespace std;

void show(const double & vd) { cout << vd << " "; }

int main()
{
    string::npos;   //字符串的最大长度
    unique_ptr<string> ps1(new string("HTY"));      //所有权概念，对于特定的对象，只有一个智能指针可以拥有它
    shared_ptr<string> ps2(new string("ZXA"));      //在最后一个指针过期时，才会调用delete
    cout << *ps1 << ", " << *ps2 << endl;

    vector<double>::iterator pd;    //声明一个迭代器，即广义指针
    vector<double> scores = {79, 80};    //
    scores.push_back(81);    //将元素放到末尾
    scores.erase(scores.begin()+2, scores.end());     //删除区间[a, b)
    for (pd = scores.begin(); pd != scores.end(); pd++)
        cout << *pd << " ";
    cout << endl;

    for_each(scores.begin(), scores.end(), show);   //对范围内的每个对象执行操作
    cout << endl;
    for_each(scores.rbegin(), scores.rend(), show); //反向迭代器的类型为reverse_iterator
    cout << endl;
    random_shuffle(scores.begin(), scores.end());   //随机打乱顺序
    sort(scores.begin(), scores.end());             //排序

    for (auto x : scores)   show(x);    //使用指定变量依次访问容器的每个元素
    cout << endl;

    copy(scores.begin(), scores.end(), ostream_iterator<char, char>(cout, " "));
    cout << endl;   //以字符类型输出
}
