/*
 * @Description: 构造函数
 * @version: v1.0
 * @Author: HTY
 * @Date: 2022-10-16 13:51:56
 */


#include <iostream>
#include <thread>


void f1(int n)
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Thread " << n << " executing.\n";
        std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}


void f2(int& n)
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Thread 2 executing.\n";
        std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}


int main(int argc, char const *argv[])
{
    int n = 0;
    std::thread t1;                     // not a thread
    std::thread t2(f1, n + 1);          // pass by value
    std::thread t3(f2, std::ref(n));    // pass by reference
    std::thread t4(std::move(t3));      // move t3 to t4
    t2.join();
    t4.join();
    std::cout << "Final value of n: " << n << std::endl;

    return 0;
}

