//
// Created by hty on 2021/8/10.
//

#include <iostream>
#include <cstring>
using namespace std;

template <class T>
T max_n(T ar[], int n);     //返回数组中的最大值
template <> string max_n (string ar[], int n);   //返回最长的字符串

int main()
{
    int Length = 3;
    int str1[Length] = {1, 2, 3};
    double str2[Length] = {1.1, 2.2, 3.3};
    string str3[Length] = {"aa", "bbb", "ccc"};
    //c++中字符串常量的类型为const char*，而左值为char*，因此需要强制类型转换，这里用string代替
    int l1 = max_n(str1, Length);
    double l2 = max_n(str2, Length);
    string l3 = max_n(str3, Length);
    cout << l1 << " " << l2 << " " << l3 << endl;

    return 0;
}

template <class T>
T max_n(T ar[], int n)
{
    T temp = ar[0];
    for (int i = 1; i < n; i++)
    {
        if (temp < ar[i])   temp = ar[i];
    }
    return temp;
}

template <> string max_n<string> (string ar[], int n)
{
    int temp = ar[0].size(), index;
    for (int i = 1; i < n; i++)
    {
        if (ar[i].size() > temp)
        {
            temp = ar[i].size();
            index = i;
        }
    }
    return ar[index];
}