#include <iostream>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;
    
    if (B >= C) {
        std::cout << -1 << "\n";
    }
    else {
        std::cout << A / (C -B) + 1 << "\n";
    }
}