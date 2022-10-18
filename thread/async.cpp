/*
 * @Description: 异步任务
 * @version: v1.0
 * @Author: HTY
 * @Date: 2022-10-17 16:12:31
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <future>


int thread_task(int value)
{
    std::cout << std::this_thread::get_id() << " Thread started" << std:: endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << std::this_thread::get_id() << " Thread ended" << std::endl;
    return value;
}


class ThreadTask
{
public:
    ThreadTask() = default;
    int thread_task(int value)
    {
        std::cout << std::this_thread::get_id() << " Thread started" << std:: endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << std::this_thread::get_id() << " Thread ended" << std::endl;
        return value;
    }
};


int main(int argc, char const *argv[])
{
    std::cout << "main started" << std::endl;

    std::future<int> f1 = std::async(thread_task, 10);
    std::cout << f1.get() << std::endl; // 等待子线程返回

    ThreadTask t2;
    std::future<int> f2 = std::async(&ThreadTask::thread_task, &t2, 20);
    std::cout << f2.get() << std::endl;

    ThreadTask t3;
    std::future<int> f3 = std::async(std::launch::async, &ThreadTask::thread_task, &t3, 30);
    std::cout << f3.get() << std::endl;
    
    return 0;
}
