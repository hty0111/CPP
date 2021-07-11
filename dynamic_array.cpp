#include <iostream>
#include <string>
using namespace std;

int main()
{
    unsigned int count = 0;
    cout << "输入数组元素个数\n";
    cin >> count;

    int *x = new int[count];        //从堆中申请
    for( int i = 0; i < count; i++ )
    {
        x[i] = i;
    }
    for( int i = 0; i < count; i++ )
    {
        cout << x[i];
    }
    delete[] x;     //释放动态数组
}

