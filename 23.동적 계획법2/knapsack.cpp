#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> w(n, 0);
    std::vector<int> v(n, 0);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> w[i] >> v[i];
    }

    std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n, 0));
    // 가방의 크기가 i 일 때, j 번째 물건까지 담을 수 있는 경우 최대 가치

    for(int i = 1 ; i <= k ; i ++) {
        for(int j = 0 ; j < n ; j++) {
            if(i >= w[j]) {
                dp[i][j] = std::max(dp[i][j - 1], dp[i - w[j]][j - 1] + v[j]);
            }
            else{
                dp[i][j] = dp[i][j - 1];
            }
            
        }
    }
    std::cout << dp[k][n - 1] << "\n";
}