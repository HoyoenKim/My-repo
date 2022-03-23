#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> isPrime(n + 1, 1);
    isPrime[0] = 0;
    isPrime[1] = 0;
    for(int i = 2; i <= n ; i++) {
        if(isPrime[i] == 1) {
            for(int j = 2 ; j <= n / i ; j++) {
                isPrime[i * j] = 0;
            }
        }
    }

    std::vector<int> prime;
    for(int i = 1 ; i <= n ; i++) {
        if(isPrime[i] == 1) {
            prime.push_back(i);
        }
    }

    int primeNum = prime.size();
    if(primeNum == 0) {
        std::cout << "0\n";
    }
    else if(primeNum == 1) {
        if(prime[0] == n) {
            std::cout << "1\n";
        }
        else {
            std::cout << "0\n";
        }
    }
    else {
        int left = 0, right = 1;
        int count = 0;
        if(prime[left] == n) {
            count += 1;
        }
        int sum = prime[left] + prime[right];
        while(right < primeNum) {
            if(sum == n) {
                count += 1;
                sum -= prime[left];
                left += 1;
            }
            else if(sum > n) {
                sum -= prime[left];
                left += 1;
            }
            else if(sum < n) {
                right += 1;
                sum += prime[right];
            }
        }
        std::cout << count << "\n";
    }
}