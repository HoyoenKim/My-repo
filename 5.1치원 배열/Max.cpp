#include <iostream>

int main () {
    int max, maxIndex;
    for(int i = 0; i < 9; i ++) {
        int n;
        std::cin >> n;
        if (i == 0) {
            max = n;
            maxIndex = i + 1;
        }
        else {
            if (max < n) {
                max = n;
                maxIndex = i + 1;
            }
        }
    }
    std::cout << max << "\n" << maxIndex << "\n";
}