#include <iostream>
#include <stdexcept>
#include "counter.hpp"

class TestClass : public Counter<TestClass, 3> {};

int main() {
    try {
        TestClass a;
        TestClass b;
        TestClass c;
        TestClass d;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}
