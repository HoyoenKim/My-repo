#include <iostream>

int main() {
    int x, y, w, h;
    std::cin >> x >> y >> w >> h;
    int min = x;
    if(y < min) {
        min = y;
    }
    if(w - x < min) {
        min = w - x;
    }
    if(h - y < min) {
        min = h - y;
    }

    std::cout << min << "\n";
}