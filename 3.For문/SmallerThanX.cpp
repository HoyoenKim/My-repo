#include <iostream>
#include <vector>

int main() {
    int N, X;
    std::cin >> N >> X;

    for (int i = 0 ; i < N ; i++) {
        int x;
        std::cin >> x;
        if (x < X) {
            std::cout << x << " ";
        }
    }
    std::cout << "\n";
}