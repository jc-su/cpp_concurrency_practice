#include <future>
#include <iostream>

int main() {
    auto increment = [](int value) {
        value++;
        return value;
    };

    std::future<int> asyncFunction = std::async(increment, 0);
    for (int i = 0; i < 10; i++) {
        std::cout << increment(i) << std::endl;
    }

    std::cout << asyncFunction.get() << std::endl;
    return 0;
}