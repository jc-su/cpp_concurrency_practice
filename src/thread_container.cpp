#include <iostream>
#include <thread>
#include <vector>

int main() {
    constexpr auto greeting = [](int idx) {
        std::cout << idx << ": " << std::this_thread::get_id() << "\n";
    };

    std::vector<std::jthread> threads;
    threads.reserve(10);
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(greeting, i);
    }

    return 0;
}