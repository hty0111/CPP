#include <iostream>
using namespace std;

int main()
{
    char buf[20];
    cin.ignore(5);              //忽略n个字符
    cin.clear();                //清空缓冲区
    cin.getline(buf, 10);       //读一行的n个字符到字符串中
    cin.peek();                 //识别下一个字符后放回缓冲区
    cin.get();                  //读一个字符 
    cin.gcount();               //收集到的字符数
    cin.read(buf, 10);          //换行符也读取
    
    cout.write(buf, 20);        //换行符也输出
    cout.precision(2);          //输出精度
    cout.width(10);             //输出宽度                 
    cout.fill('*');             //空白处填充

}

//cin，cout都在std命名空间中

/*std::cin检查
eof()           达到文件结尾，返回1
fail()          cin无法工作，返回1
bad()           cin因为严重的原因无法工作（内存不足），返回1
good()          无事发生，返回1
*/
