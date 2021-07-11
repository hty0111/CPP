#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cout << "输入字符串：";
    std::getline(std::cin, str);
    std::cout << str;
}

/*std::string类
size()                          字符个数
length()                        字符串长度，同上
max_size()                      能包含的最大字符数
capacity()                      重新分配内存前的容量
A.compare(2, 2, B, 2, 2)        A下标为2开始的2位与B比较

begin()                         指向第一个元素
rbegin()                        指向结尾，一般用于反向遍历
end()                           指向最后一个元素的后面一位

push_back(' ')                  尾插
insert(str.begin(), ' ')        指定位置前插
append(" ")                     拼接字符串，或用"+"

erase(n1, n2)                   从n1开始索引n2个字符并删除
erase(p1, p2)                   删除从p1指向元素到p2指向元素的前一个

replace(n1, n2, " ")            从n1开始索引n2个字符并替换
replace(n1, n2, n3, ' ')        从n1开始索引n2个字符并替换位n3个字符
replace(p1, p2, " ")

find(' ', n)                    从第n位开始查找字符
rfing()                         向前查找

tolower(' ')
toupper(' ')

sort(p1, p2)
reverse(p1, p2)
*/