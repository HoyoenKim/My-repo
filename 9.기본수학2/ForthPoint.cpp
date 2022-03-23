#include <iostream>

int main() {
    int X, Y;
    int x, y;

    std::cin >> x >> y;
    X = x;
    Y = y;

    std::cin >> x >> y;
    X ^= x;
    Y ^= y;

    std::cin >> x >> y;
    X ^= x;
    Y ^= y;

    std::cout << X << " " << Y << "\n";
}