/*
 * @Description: 条件锁
 * @version: v1.0
 * @Author: HTY
 * @Date: 2022-10-17 14:38:20
 */


#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>

std::deque<int> my_deque;
std::mutex my_mutex;
std::condition_variable cond;


void foo1()
{
    int count = 10;
    while (count > 0)
    {
        std::unique_lock<std::mutex> locker(my_mutex);
        my_deque.push_back(count);
        locker.unlock();    // 释放锁
        cond.notify_one();  // 唤醒一个等待线程
        count--;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}


void foo2()
{
    int data;
    while (true)
    {
        std::unique_lock<std::mutex> locker(my_mutex);
        cond.wait(locker, []()->bool { return !my_deque.empty(); });    // 解锁locker并休眠，收到notify且my_deque不为空时线程重新激活并上锁
        data = my_deque.front();
        my_deque.pop_front();
        locker.unlock();    // 线程2释放锁后，线程1获得该锁

        std::cout << data << std::endl; // 10, 9, ..., 1

        if (data == 1)
            break;
    }
}


int main(int argc, char const *argv[])
{
    std::thread t1(foo1);
    std::thread t2(foo2);

    t1.join();
    t2.join();

    return 0;
}
