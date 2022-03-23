#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
    int N, K;
    std::cin >> N >> K;
    int M = N - K + 1;

    unsigned long long num2 = 0;
    unsigned long long i = 2;
    while(i <= N) {
        // N ~ N - K + 1 = M;
        if(M % i == 0) {
            num2++;
        }
        num2 += N / i - M / i;
        // K ~ 1
        num2 -= K / i;
        i *= 2;
    }

    unsigned long long num5 = 0;
    i = 5;
    while(i <= N) {
        // N ~ N - K + 1 = M;
        if(M % i == 0) {
            num5++;
        }
        num5 += N / i - M / i;
        // K ~ 1
        num5 -= K / i;
        i *= 5;
    }

    if(num2 > num5) {
        std::cout << num5 << "\n";
    } 
    else {
        std::cout << num2 << "\n";
    }
}