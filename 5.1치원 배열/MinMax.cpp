#include <iostream>

int main () {
    int N, min, max;
    std::cin >> N;

    for (int i = 0 ; i < N ; i++) {
        int n;
        std::cin >> n;

        if (i == 0) {
            min = n;
            max = n;
        }
        else {
            if (min > n) {
                min = n;
            }
            if (max < n) {
                max = n;
            }
        }
    }

    std::cout << min << " " << max << "\n";
}