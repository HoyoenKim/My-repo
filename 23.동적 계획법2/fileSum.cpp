#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    for(int i = 0 ; i < N ; i++) {
        int n;
        std::cin >> n;
        std::vector<int> file(n, 0);
        std::vector<int> sumFile(n, 0);

        for(int i = 0 ; i < n ; i++) {
            std::cin >> file[i];
            if(i == 0) {
                sumFile[i] = file[i];
            }
            else{
                sumFile[i] = sumFile[i - 1] + file[i];
            }
        }
        
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        //dp[i][j] : i 부터 j 까지 파일 합의 최소 (i < j)
        //dp[i][i + 1] = file[i] + file[i + 1]
        //dp[i][j] = min(dp[i][k] + dp[k + 1][j]) + sumFile[j] - sumFile[i - 1]
        
        //40 30 30 50
        // dp[0][1] = 70 / dp[0][2] = min(dp[1][2], dp[0][1]) + sumFile[2] / dp[0][3] = min(dp[1][3], dp[0][1] + dp[2][3], dp[0][2]) + sumFile[3]
        //               / dp[1][2] = 60 / dp[1][3] = min(dp[1][2], dp[2][3]) + sumFile[3] - sumFile[0]
        //                               / dp[2][3] = 80

        // j - i = 1, 2, 3 ... n - 1
        // 01 12 23 -> 02 13 -> 03
        for(int s = 1 ; s < n ; s++) {
            for(int i = 0 ; i + s < n ; i++) {
                int j = i + s;
                int sumMin = dp[i + 1][j];
                for(int k = i + 1 ; k < j ; k++) {
                    sumMin = std::min(sumMin, dp[i][k] + dp[k + 1][j]);
                }

                if(i > 0) {
                    dp[i][j] = sumMin + sumFile[j] - sumFile[i - 1];
                }
                else {
                    dp[i][j] = sumMin + sumFile[j];
                }
                
            }
        }
        std::cout << dp[0][n - 1] << "\n";
    }

}