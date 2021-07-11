#include <iostream>
#include <string>

//基类
class Animal
{
public:
    std::string name;

    Animal(std::string name);   //构造器
    ~Animal();                  //析构器
    virtual void eat();         //虚方法，用于避免子类匿名实例化的指针
    virtual void sleep();
    virtual void sleep( int sleepNum ); //重载

protected:
    void study();

    friend class People;
};

//子类
class Pig : public Animal
{
public:
    Pig(std::string name);
    void climb()    //可以直接在类中定义函数
    {
        std::cout << "我会上树" << std::endl;
    }
    void eat();     //覆盖
};

//友元关系
class People
{
public:
    std::string name;
    People(std::string name);
    void study(Animal &a); //必须传引用
};

//定义函数
Animal::Animal(std::string name)
{
    this->name = name;      //this指针指向本类中的对象
}

Animal::~Animal()
{
    name = "";
}

void Animal::eat()
{
    std::cout << "我在吃饭" << std::endl;
}

void Animal::sleep()
{
    std::cout << "我在睡觉" << std::endl;
}

void Animal::sleep( int eatNum )
{
    std::cout << "这是今天上课第" << eatNum << "次睡着啦\n";
}

void Animal::study()
{
    std::cout << name << "快去学习\n"; 
}

//子类也按照类的方法写
Pig::Pig(std::string name) : Animal(name)
{           //子类构造器继承基类的方法
}

void Pig::eat()
{
    Animal::eat();      //前面声明过了可以直接调用
    std::cout << "我还要吃\n";
}

//友元关系可以随意访问属性和方法
People::People(std::string name)
{
    this->name = name;      //this指针指向本类中的对象
}

void People::study(Animal &a)
{
    a.study();
    std::cout << name << "也快去学习\n";
}

int main()
{   
    Animal zxa("zxa");                  //实例化
    Animal * animal = new Pig("zxa");   //创建一个Pig指针赋值给Animal指针animal

    animal->eat();         //由于基类用了虚方法，所以调用的是Pig中的函数
    animal->sleep();       //重载1
    animal->sleep(3);      //重载2

    std::cout << "这只猪猪就是：" << animal->name <<"\n";

    People people("hty");
    people.study(zxa);

}

/*访问控制
public          任何代码
protected       这个类和子类
private         只有这个类本身
由上至下的顺序编程
*/

/*构造器
对类进行初始化
无返回值，函数前不需要void
ClassName(void);
每个类至少有一个构造器
先调用基类的构造器，后调用子类构造器，因为基类要在子类前先被初始化
*/

/*析构器
无返回值,不带参数
~ClassName();
在复杂的类里必须用析构器释放内存，否则可能引起内存泄漏
基类的析构器在子类的最后一条语句执行后被调用
*/

/*
覆盖：子类覆盖基类的函数，函数名和参数均相同，基类函数不起作用
重载：函数名相同，参数不同，两个函数均可调用
继承之后不能重载
*/

/*友元关系
关键字：friend
可以访问类中protected和private属性
*/

/*虚方法 virtual method
关键字：virtual
具有继承关系
实现多层次继承关系时，顶级的基类应该只有虚方法
析构器都是虚方法
*/

/*纯虚函数（抽象类）
抽象类无法实例化对象
抽象类的子类只有把抽象类中的纯虚函数全部实现之后，才可以实例化对象
*/
