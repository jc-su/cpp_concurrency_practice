#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

int main() {
    std::mutex mutex_lock;
    int value = 0;

    auto increment = [&]() {
        mutex_lock.lock();
        value++;
        std::cout << "Incrementing value to " << value << " in thread " << std::this_thread::get_id() << "\n";
        mutex_lock.unlock();
    };

    std::vector<std::jthread> threads;
    threads.reserve(10);
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(increment);
    }

    return 0;
}