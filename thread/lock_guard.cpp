/*
 * @Description: lock_guard & mutex
 * @version: v1.0
 * @Author: HTY
 * @Date: 2022-10-16 17:11:34
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::vector<int> lists;
std::mutex list_mutex;   

void add_lists(int x)
{
    std::lock_guard<std::mutex> guard(list_mutex);
    // list_mutex.lock();
    lists.push_back(x);
    // list_mutex.unlock();
}

void thread_task(int x)
{
    std::cout << "Add " << x << " to list." << std::endl; 
    add_lists(x);
}

int main(int argc, char const *argv[])
{
    std::thread t1(thread_task, 1);
    std::thread t2(thread_task, 2);

    t1.join();
    t2.join();

    for (auto i : lists)
        std::cout << i << std::endl;
    
    return 0;
}
