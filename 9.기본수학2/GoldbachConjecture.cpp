#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int N = 10000;
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

    int n;
    std::cin >> n;

    for(int i = 0 ; i < n ; i++) {
        int even;
        std::cin >> even;

        int part1, part2, diff = -1;
        for(int j = 2 ; j < even ; j++) {
            if(isPrime[j] == 1) {
                if(isPrime[even - j] == 1) {
                    if (diff == -1) {
                        part1 = j;
                        part2 = even - j;
                        diff = std::abs(part1 - part2);
                    }
                    else if (std::abs(even - 2*j) < diff) {
                        part1 = j;
                        part2 = even - j;
                        diff = std::abs(part1 - part2);
                    }
                }
            }
        }
        if(part1 < part2) {
            std::cout << part1 << " " << part2 << "\n";
        }
        else {
            std::cout << part2 << " " << part1 << "\n";
        }
    }
}