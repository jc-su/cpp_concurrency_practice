#include <format>
#include <iostream>
#include <string_view>
#include <thread>

int main() {
    constexpr auto greeting = [](std::string_view sv) {
        std::cout << sv << std::this_thread::get_id() << "\n";
    };

    std::jthread t1(greeting, "Hello from thread: ");
    std::jthread t2(greeting, "Greeting from thread: ");

    return 0;
}