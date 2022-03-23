#include <iostream>
#include <cmath>

int main() {
    // 1
    // 1 1
    // 1 2 1 = 4
    // 1 2 2 1 = 6
    // 1 2 3 2 1 = 9
    // 1 2 3 3 2 1 = 12

    int n;
    std::cin >> n;
    for(int i = 0 ; i < n ; i++) {
        int x, y;
        std::cin >> x >> y;

        int dist = y - x;
        
        int j = std::sqrt(dist);
        if(dist == j*j) {
            std::cout << 2*j - 1 << "\n";
        }
        else if(dist <= j*(j+1)) {
            std::cout << 2*j << "\n";
        }
        else {
            std::cout << 2*j + 1 << "\n";
        }
    }
}