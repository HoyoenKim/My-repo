#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;

    if (A > B) {
        std::cout << ">" << std::endl;
    }
    else if (A == B) {
        std::cout << "==" << std::endl;
    }
    else {
        std::cout << "<" << std::endl;
    }
    return 0;
}