#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0 ; i < n; i++) {
        int H, W, N;
        std::cin >> H >> W >> N;
        if (N % H != 0) {
            if (N / H + 1 < 10) {
                std::cout << N % H << "0" << N / H + 1 << "\n";
            }
            else {
                std::cout << N % H << N / H + 1 << "\n";
            }
        }
        else {
            if (N / H < 10) {
                std::cout << H << "0" << N / H << "\n";
            }
            else {
                std::cout << H << N / H << "\n";
            }
        }
    }
}