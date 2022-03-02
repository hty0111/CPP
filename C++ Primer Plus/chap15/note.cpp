//
// Created by hty on 2021/8/29.
//

#include <iostream>

class Tv;   //前向定义

class Remote{
private:
    int mode;
public:
    void set_vol(Tv & tv, int v);   //tv类尚未定义，因此只能在之后使用内联函数
};

class Tv{
private:
    int volume;
public:
//    friend class Remote;    //友元类
    friend void Remote::set_vol(Tv &tv, int v);     //友元成员函数
    void show_tv()
    {
        try
        {
            if (volume < 0)
                throw("Volume cannot be lower than zero.");
        }
        catch(const char *s)    //throw的参数传给catch
        {
            std::cout << s << std::endl;
        }
        std::cout << volume << "\n";
    }
};

inline void Remote::set_vol(Tv &tv, int v) { tv.volume = v; }

int main()
{
    Tv tv;
    Remote remote;
    remote.set_vol(tv, 1);
    tv.show_tv();
}