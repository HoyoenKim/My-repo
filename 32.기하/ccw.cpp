#include <iostream>

int main() {
    int x1, x2, x3, y1, y2, y3;
    std::cin >> x1 >> y1;
    std::cin >> x2 >> y2;
    std::cin >> x3 >> y3;

    x3 = x3 - x1;
    x2 = x2 - x1;
    x1 = 0;

    y3 = y3 - y1;
    y2 = y2 - y1;
    y1 = 0;

    int a = x2*y3 - x3*y2;

    if(a == 0) {
        std::cout << 0 << "\n";
    }
    else if(a > 0) {
        std::cout << 1 << "\n";
    }
    else if(a < 0) {
        std::cout << -1 << "\n";
    }
}