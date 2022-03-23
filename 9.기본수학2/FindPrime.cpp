#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int count = 0;
    for (int i = 0 ; i < n ; i++) {
        int targetNum;
        std::cin >> targetNum;

        if (targetNum > 1) {
            int isPrime = 1;
            for(int j = 2 ; j < targetNum ; j++) {
                if (targetNum % j == 0) {
                    isPrime = 0;
                }
            }
            if(isPrime == 1) {
                count++;
            }
        }
    }
    std::cout << count;
}