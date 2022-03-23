#include <iostream>
#include <vector>

int main() {
    int N = 123456 * 2;
    std::vector<int> isPrime(N+1, 1);
    isPrime[0] = 0;
    isPrime[1] = 0;
    for(int i = 2 ; i <= N ; i++) {
        if(isPrime[i] == 1) {
            for(int j = 2; j < N / i + 1 ; j++) {
                isPrime[i*j] = 0;
            }
        }
    }

    while(1) {
        int n;
        std::cin >> n;
        if(n == 0) {
            break;
        }

        int count = 0;
        for(int i = n + 1 ; i <= 2*n ; i++) {
            if(isPrime[i] == 1) {
                count++;
            }
        }

        std::cout << count << "\n";
    }
}