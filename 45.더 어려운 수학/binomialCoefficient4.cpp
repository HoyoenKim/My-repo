#include <iostream>
#include <vector>

int main() {
    unsigned long long n, k, p;
    std::cin >> n >> k >> p;

    /*
    음 아닌 정수 n, k, 소수 p에 대해서
    n 과 k 를 p진법 전개식으로 나타냈을 때,
    n = n_m * p^m + n_m-1 * p^m-1 + ... + n_0
    k = k_m * p^m + k_m-1 * p^m-1 + ... + k_0

    nCk = (i = [0, k])PI n_iCk_i (mod p)
    */

    std::vector<std::vector<int>> dp(2001, std::vector<int>(2001, 0));
    for(int i = 0 ; i <= 2000 ; i++) {
        for(int j = 0 ; j <= i ; j++) {
            if(i == j || j == 0) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % p;
            }
        }
    }

    unsigned long long answer = 1;
    while(n > 0 && k > 0) {
        answer *= dp[n % p][k % p];
        answer %= p;
        n /= p;
        k /= p; 
    }
    std::cout << answer << "\n";
}