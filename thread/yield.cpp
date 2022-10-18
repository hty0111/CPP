/*
 * @Description: yield 放弃执行当前线程
 * @version: v1.0
 * @Author: HTY
 * @Date: 2022-10-16 16:39:13
 */

#include <iostream>
#include <thread>


void little_sleep(std::chrono::microseconds us)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto end = start + us;
    do
    {
        std::this_thread::yield();  // other threads run
    } while (std::chrono::high_resolution_clock::now() < end);
    
}


int main(int argc, char const *argv[])
{
    auto start = std::chrono::high_resolution_clock::now();
    
    little_sleep(std::chrono::microseconds(100));

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "wait for " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " us.\n";

    return 0;
}
