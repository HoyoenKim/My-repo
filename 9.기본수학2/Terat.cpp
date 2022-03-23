#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    for(int i = 0 ; i < n ; i++) {
        double x1, y1, r1, x2, y2, r2;
        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double dist = std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
        if (dist == 0) {
            if (r1 == r2) {
                std::cout << -1;
            }
            else{
                std::cout << 0;
            }
        }
        else {
            if(dist > r1 + r2) {
                std::cout << 0;
            }
            else if(dist == r1 + r2) {
                std::cout << 1;
            }
            else if(dist < r1 + r2 && dist > std::abs(r2 - r1)) {
                std::cout << 2;
            }
            else if(dist == std::abs(r2 - r1)) {
                std::cout << 1;
            }
            else{
                std::cout << 0;
            }
        }
        
        std::cout << "\n";
    }
}