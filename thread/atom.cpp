/*
 * @Description: 原子操作
 * @version: v1.0
 * @Author: HTY
 * @Date: 2022-10-17 19:10:06
 */


#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

std::mutex mutex;
std::atomic<int> count = 0;

void thread_task()
{
    for (int i = 0; i < 1000000; ++i)
    {
        // mutex.lock();
        count++;
        // mutex.unlock();
    }
}


int main(int argc, char const *argv[])
{
    std::thread t1(thread_task);
    std::thread t2(thread_task);
    t1.join();
    t2.join();

    std::cout << count << std::endl;

    return 0;
}
