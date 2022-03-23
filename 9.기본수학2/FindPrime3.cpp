#include <iostream>
#include <vector>

int main() {
    int M, N;
    std::cin >> M;
    std::cin >> N;
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

    for(int i = M ; i <=N ; i++) {
        if(isPrime[i] == 1) {
            std::cout << i << "\n";
        }
    }
}