#include <iostream>

using namespace std;

void swap1( int a, int b );
void swap2( int *a, int *b );
void swap3( int &a, int &b );


int main()
{   
    char str[10] = "HTY NB!";
    char * p = str;
    std::cout << *(p + 1) << "\n";  //T
    std::cout << *p + 1 << "\n";    //I

    int *p = new int;       //相当于malloc
    *p = 110;
    delete p;               //相当于free
    
    int a = 1, b = 2;
    swap1(a, b);
    cout << a << b << endl;
    swap2(&a, &b);
    cout << a << b << endl;
    swap3(a, b);
    cout << a << b << endl;
}

void swap1( int a, int b )
{
    a ^= b;
    b ^= a;
    a ^= b;
    cout << "第一次：" << a << b << endl;
}

void swap2( int *a, int *b )
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    cout << "第二次：" << *a << *b << endl;
}

void swap3( int &a, int &b )
{
    a ^= b;
    b ^= a;
    a ^= b;
    cout << "第三次：" << a << b << endl;    
}

/*
传值：在内存中重新分配一块区域存放该值，不会影响原本的值
传地址：在内存中重新分配一块区域存放该值的地址
传引用：直接在定义函数时用取地址符，传参时传值对象本身，相当于在函数中对这个对象取别名
*/