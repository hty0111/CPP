/*
 * @Description: 
 * @version: v1.0
 * @Author: HTY
 * @Date: 2022-10-16 15:48:35
 */

#include <iostream>
#include <thread>


void thread_task()
{
    std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}


int main(int argc, char const *argv[])
{
    std::thread t1;  // 默认构造函数创建的线程不能被join，即不是活动的执行线程
    std::cout << "Default constructor, joinable: " << t1.joinable() << std::endl;

    t1 = std::thread(thread_task);
    std::cout << "Normal constructor, joinable: " << t1.joinable() << std::endl;

    t1.join();
    std::cout << "t1 finished." << std::endl;

    std::thread t2(thread_task);    // 执行完任务但是未被join的线程也被认为是活动的执行线程
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "t2 finished." << std::endl;
    std::cout << "Finished task before join, joinabe: " << t2.joinable() << std::endl;

    t2.join();
    
    
    return 0;
}
