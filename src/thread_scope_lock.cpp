#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

int main() {
    std::mutex mutex_lock1;
    std::mutex mutex_lock2;
    int value = 0;

    auto increment = [&]() {
        std::scoped_lock lock(mutex_lock1, mutex_lock2);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        value++;
        std::cout << "Incrementing value to " << value << " in thread " << std::this_thread::get_id() << "\n";
    };

    std::vector<std::jthread> threads;
    threads.reserve(10);
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(increment);
    }

    return 0;
}