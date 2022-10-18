/*
 * @Description: 赋值
 * @version: v1.0
 * @Author: HTY
 * @Date: 2022-10-16 14:20:51
 */


#include <iostream>
#include <thread>
#include <string>


void thread_task(int n)
{
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "Thread " << std::this_thread::get_id() << " sleep for " << n << " s\n";
}


int main(int argc, char const *argv[])
{
    std::thread threads[5];
    std::cout << "Spawning 5 threads...\n";
    for (int i = 0; i < 5; ++i)
    {
        threads[i] = std::thread(thread_task, i + 1);
    }
    std::cout << "Done spawning threads!\n";

    for (auto& t : threads)
    {
        t.join();
    }

    return 0;
}

