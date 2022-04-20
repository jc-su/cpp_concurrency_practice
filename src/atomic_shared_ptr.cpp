#include <atomic>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

int main() {
    std::shared_ptr<int> ptr = std::make_shared<int>(0);
    std::atomic<std::shared_ptr<int>> atomic_ptr(ptr);

    auto increment = [&]() {
        ptr = std::make_shared<int>(*ptr + 1);
        atomic_ptr.store(ptr);
    };

    std::vector<std::jthread> threads;
    threads.reserve(10);
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(increment);
    }

    for (auto &t: threads) {
        t.join();
    }

    std::cout << "Increased value to " << *ptr << "\n";
    return 0;
}