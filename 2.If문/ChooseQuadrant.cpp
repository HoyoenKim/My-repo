#include <iostream>

int main () {
    int X, Y;
    std::cin >> X;
    std::cin >> Y;

    if (X*Y > 0) {
        if (X > 0) {
            std::cout << 1 << std::endl;
        }
        else {
            std::cout << 3 << std::endl;
        }
    }
    else {
        if (X > 0) {
            std::cout << 4 << std::endl;
        }
        else {
            std::cout << 2 << std::endl;
        }
    }
}