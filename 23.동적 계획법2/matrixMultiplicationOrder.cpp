#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(2, 0));

    for(int i = 0 ; i < n ; i++) {
        int r, c;
        std::cin >> r >> c;
        matrix[i][0] = r;
        matrix[i][1] = c;
    }

    // 5,3 3,2 2,6
    // 5,2 2,6 -> 5*3*2
    // 5,6 -> 5*3*2 + 5*2*6
    // 5,3 3,6 -> 3*2*6
    // 5, 6 -> 3*2*6 + 5*3*6

    // d[i][j] 행렬 i 부터 j 까지 곱했을 때의 최소 합 (i < j)
    // d[i][j] = min(d[i][k] + d[k][j] + c[i]*c[k]*c[j])
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    for(int s = 1 ; s < n ; s++) {
        for(int i = 0 ; i + s < n ; i++) {
            int j = i + s;
            int minSum = INT32_MAX;
            for(int k = i; k < j ; k++) {
                int candid = dp[i][k] + dp[k + 1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1]; 
                if(candid < minSum) {
                    minSum = candid;
                }
            }
            dp[i][j] = minSum;
        }
    }
    std::cout << dp[0][n - 1] << "\n";
}