#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}

int main() {
    int n;
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> n;
    std::vector<int> array(n);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i];
    }

    int M = std::abs(array[1] - array[0]);
    for(int i = 2 ; i < n ; i++) {
        int m = std::abs(array[i] - array[i -1]);
        if(M > m) {
            M = gcd(M, m);
        }
        else {
            M = gcd(m, M);
        }
    }

    std::vector<int> factor;
    int factorNum = 0;

    int M0 = sqrt(M);
    for(int i = 2 ; i <= M0 ; i++) {
        if (M % i == 0) {
            std::cout << i << " ";
            if(i != M / i) {
                factor.push_back(M / i);
                factorNum++;
            } 
        }
    }

    for(int i = factorNum ; i > 0 ; i--) {
        std::cout << factor[i - 1] << " ";
    }
    std::cout << M << "\n";
}