/*
 * @Description: swap
 * @version: v1.0
 * @Author: HTY
 * @Date: 2022-10-16 16:29:14
 */

#include <iostream>
#include <thread>


void thread_task()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}


int main(int argc, char const *argv[])
{
    std::thread t1(thread_task);
    std::thread t2(thread_task);

    std::cout << "Thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "Thread 2 id: " << t2.get_id() << std::endl;

    std::swap(t1, t2);

    std::cout << "Thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "Thread 2 id: " << t2.get_id() << std::endl;

    t1.join();
    t2.join();

    return 0;
}
