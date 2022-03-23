#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<int> a(n, 0);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    // dp[i][j] = i 부터 j 까지 펠린드롬인지 아닌지
    // dp[i][j] = dp[i + 1][j - 1] && a[i] == a[j]

    for(int i = 0 ; i < n ; i++) {
        dp[i][i] = 1;
        if(i != n - 1) {
            if(a[i] == a[i + 1]) {
                dp[i][i + 1] = 1;
            }
        }
    }

    for(int i = n - 1 ; i >= 0 ; i--) {
        for(int j = i + 2 ; j < n ; j++) {
            if(a[i] == a[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
            }
        }
    }
    int m;
    std::cin >> m;
    for(int i = 0 ; i < m ; i++) {
        int a, b;
        std::cin >> a >> b;
        std::cout << dp[a - 1][b - 1] << "\n";
    }

}