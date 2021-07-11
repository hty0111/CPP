#include <string>
#include <iostream>

struct struct1
{
    std::string str1;
    std::string str2;
    char ch;
};


int main()
{
    struct1 HTY = {"HTY", "NB", '!'};
    struct1 * pHTY = &HTY;
    (*pHTY).str1 = "HTY ";
    pHTY->ch = '.';
    std::cout << HTY.str1 << HTY.str2 << HTY.ch;
}