//
// Created by hty on 2021/9/4.
//

#include <iostream>
#include <string>
using namespace std;
//输入输出重定向
//code.exe <inputFile >outputFile

int main()
{
    /*输出*/
    cout.width(10);  //设置字段宽度为10，只对下一个输出有效
    cout.fill('*');     //以*填充，始终有效
    cout.precision(2);  //设置精度，始终有效
    cout.setf(ios_base::boolalpha);     //输出bool值
    cout.unsetf(ios_base::boolalpha);   //取消设置

    /*输入*/
    get(char ch);       //不跳过空白和换行符
    char ch = get();    //适合转换C语言，类似于getchar()
    cin.ignore(20, '\n');   //丢弃10个字符或遇到换行符为止
    cin.get(char* str, 50);     //将换行符留在输入流中
    cin.getline(char* str, 50); //读取并丢弃换行符
    cin.read(char* str, 50);    //不会在输入后加上'\0'，因此不能将输入转换为字符串
    cin.peek();     //查看下一个字符，但不抽取
    cin.putback(char ch);   //将字符插入到输入字符串中

}