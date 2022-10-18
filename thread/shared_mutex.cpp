/*
 * @Description: 读写锁
 * @version: v1.0
 * @Author: HTY
 * @Date: 2022-10-17 15:19:49
 */

#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>


class ThreadSafeCounter
{
public:
    ThreadSafeCounter() = default;

    // 多个线程可以同时读数据
    int get() const
    {
        std::shared_lock locker(shared_mutex_);
        return value_;
    }

    // 只有一个线程可以写数据
    void increase()
    {
        std::unique_lock locker(shared_mutex_);
        value_++;
    }

    // 只有一个线程可以写数据
    void reset()
    {
        std::unique_lock locker(shared_mutex_);
        value_ = 0;
    }

private:
    mutable std::shared_mutex shared_mutex_;
    int value_ = 0;
};


int main(int argc, char const *argv[])
{
    ThreadSafeCounter counter;
    auto thread_task = [&counter]()
    {
        for (int i = 0; i < 3; ++i)
        {
            counter.increase();
            std::cout << std::this_thread::get_id() << " " << counter.get() << std::endl;
        }
    };

    std::thread t1(thread_task);
    std::thread t2(thread_task);

    t1.join();
    t2.join();

    return 0;
}
