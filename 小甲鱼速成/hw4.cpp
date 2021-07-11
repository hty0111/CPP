/*
闭门造车
*/

#include <iostream>

using namespace std;
#define FULL_GAS 80

class Car
{
public:
    string color;
    string engine;
    int gas_tank;
    int wheel;

    Car(void);
    ~Car();
    void setColor(string col);
    void setEngine(string eng);
    void setWheel(int whe);
    void fillTank(int liter);
    int running(void);
    void warning(void);
};

Car::Car(void)
{
    color = "White";
    engine = "V8";
    wheel = 4;
    gas_tank = FULL_GAS;
}

Car::~Car()
{
    color = "";
    engine = "";
    wheel = 0;
    gas_tank = 0;   
}

void Car::setColor(string col)
{
    color = col;
}

void Car::setEngine(string eng)
{
    engine = eng;
}

void Car::setWheel(int whe)
{
    wheel = whe;
}

void Car::fillTank(int liter)
{
    gas_tank = liter;
}

int Car::running(void)
{   
    gas_tank -= 5;
    cout << "当前还剩 " << gas_tank << " 升油" << endl;

    char i;
    if( gas_tank <= 20 )
    {
        cout << "是否需要加油" << endl;
        cin >> i;
        if( i == 'Y' || i == 'y' )
        {
            fillTank(FULL_GAS);
        }
        else
        {
            warning();
        }

        if( gas_tank == 0 )
        {
            cout << "抛锚中" << endl;
            return 1;
        }
    }
    return 0;
}

void Car:: warning(void)
{
    cout << "警告：还剩 " << gas_tank << " 升油" <<endl;
}

int main()
{
    Car mycar;

    while( !mycar.running() )
    {
        ;
    }
    
    return 0;
}

