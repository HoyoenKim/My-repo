#include <iostream>
#include <vector>

int main() {
    int M, N;
    std::cin >> M;
    std::cin >> N;

    int primeSum = 0;
    int primeMin = 0;
    for(int i = M ; i <= N ; i++) {
        if (i > 1) {
            int isPrime = 1;
            for(int j = 2 ; j <= i/2 ; j++) {
                if(i % j == 0) {
                    isPrime = 0;
                    break;
                }
            }
            if(isPrime == 1) {
                if(primeSum == 0) {
                    primeMin = i;
                }
                primeSum += i;
            }
        }
    }

    if(primeSum == 0) {
        std::cout << -1 << "\n";
    }
    else {
        std::cout << primeSum << "\n";
        std::cout << primeMin << "\n";
    }
}