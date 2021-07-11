/*
提示用于以[**.* C]或[**.* F]的格式输入，转换后输出
F = 9.0 / 5.0 * C + 32
*/

#include <iostream>

int main()
{
    const unsigned short SUBTRACT = 32;
    const double RATIO = 9.0 / 5.0;
    
    double tempIn, tempOut;
    char typeIn, typeOut;
    std::cout << "input a temperature:" << "\n";
    std::cin >> tempIn >> typeIn;       //空格区分输入，与scanf类似
    std::cin.ignore(10, '\n');
    std::cout << "\n";

    switch( typeIn )
    {
        case 'C':
        case 'c':
            tempOut = tempIn *RATIO + SUBTRACT;
            typeOut = 'F';
            typeIn = 'C';
            break;
        case 'F':
        case 'f':
            tempOut = (tempIn - SUBTRACT) / RATIO;
            typeIn = 'F';
            typeOut = 'C';
        default:
            typeOut = 'E';
            break;
    }

    if( typeOut != 'E' )
    {
        std::cout << tempIn << typeIn << " = " << tempOut << typeOut << "\n";
    }
    else
    {
        std::cout << "Error" <<"\n";
    }

    std::cout << "按任意键结束" << "\n";
    std::cin.get();
}