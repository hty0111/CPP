//
// Created by hty on 2021/9/3.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int reduce(long ar[], int n)
{
    sort(ar, ar + n);
    long * temp = unique(ar, ar + n);
    return (int)(temp - ar);
}

int main()
{
    cout << "Enter number: ";
    int num;
    cin >> num;
    cout << "Enter data: ";
    long data[num];
    for (int i = 0; i < num; i++)
        cin >> data[i];
    int numReduce = reduce(data, num);
    cout << "Number after reducing: " << numReduce << endl;
    for (int i = 0; i < numReduce; i++)
        cout << data[i] << " ";
    cout << endl;
}