#include <iostream>
#include <vector>

int INT_MAX = 1000000007;

std::vector<std::vector<long long>> matrixMultiple(std::vector<std::vector<long long>> &a, std::vector<std::vector<long long>> &b) {
    std::vector<std::vector<long long>> ret(2, std::vector<long long>(2, 0));
    for(int i = 0 ; i < 2 ; i++) {
        for(int j = 0 ; j < 2 ; j++) {
            int sum = 0;
            for(int k = 0 ; k < 2 ; k++) {
                sum += ( (a[i][k] % INT_MAX) * (b[k][j] % INT_MAX) ) % INT_MAX;
                sum %= INT_MAX;
            }
            ret[i][j] = sum;
        }
    }
    return ret;
}

int main() {
    unsigned long long n;
    std::cin >> n;
    if(n % 2 == 1) {
        std::cout << 0 << "\n";
        return 0;
    }

    unsigned long long  N = n / 2;
    if(N == 2) {
        std::cout << 11 << "\n";
        return 0;
    }
    else if(N == 1) {
        std::cout << 3 << "\n";
        return 0;
    }

    /*
    점화식 이용
    std::vector<int> dp(std::max(N + 1, 3), 0);
    dp[1] = 3;
    dp[2] = 11;
    for(int i = 3 ; i <= N ; i++) {
        dp[i] = 4 * dp[i - 1] - dp[i - 2];
    }
    std::cout << dp[N] << "\n";
    */

    /*
    점화식 푸는 행렬 이용
    ( an   ) = ( 4 -1 ) (an - 1)
    ( an-1 )   ( 1  0 ) (an - 2)    
    xn = A^(n - 2) * x2
    */
    
    std::vector<std::vector<long long>> I = {{1, 0}, {0, 1}};
    std::vector<std::vector<long long>> A = {{4, -1}, {1, 0}};
    std::vector<std::vector<std::vector<long long>>> table(61, std::vector<std::vector<long long>>(2, std::vector<long long>(2, 0)));
    table[0] = A;
    for(int i = 1 ; i < 61 ; i++) {
        table[i] = matrixMultiple(table[i - 1], table[i - 1]); 
    }
    std::vector<std::vector<long long>> ans = {{1, 0}, {0, 1}};
    unsigned long long i = 0;
    while( (N - 2) >= (unsigned long long) 1 << i) {
        if(( (N - 2) >> i) & (unsigned long long) 1 == (unsigned long long) 1){
            ans = matrixMultiple(ans, table[i]);
        }
        i++;
    }
    int answer = ((ans[0][0] * (long long) 11) % INT_MAX + (ans[0][1] * (long long) 3) % INT_MAX) % INT_MAX;
    if(answer < 0) {
        answer += INT_MAX;
    }
    std::cout << answer << "\n";
}