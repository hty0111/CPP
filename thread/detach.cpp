/*
 * @Description: detach
 * @version: v1.0
 * @Author: HTY
 * @Date: 2022-10-16 16:08:23
 */

#include <iostream>
#include <thread>


void thread_task()
{
    std::cout << "Start thread.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Exit thread.\n";
}


int main(int argc, char const *argv[])
{
    std::thread t(thread_task);
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}
