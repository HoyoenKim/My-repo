#include <iostream>
#include <vector>

int main() {
    int v, e; // v개의 마을과 e개의 도로로 구성된 도시
    std::cin >> v >> e;

    int INF = 10001;
    std::vector<std::vector<int>> dp(v + 1, std::vector<int>(v + 1, INF));
    for(int i = 0 ; i < e ; i++) {
        int a, b, c; // a -> b 로 가는 길의 거리는 c
        std::cin >> a >> b >> c;
        dp[a][b] = c;
    }


    for(int k = 1 ; k <= v ; k++) {
        for(int i = 1 ; i <= v ; i++) {
            for(int j = 1 ; j <= v ; j++) {
                if(dp[i][k] + dp[k][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    int min = INF;
    for(int i = 1 ; i <= v ; i++) {
        if(dp[i][i] < min) {
            min = dp[i][i];
        }
    }

    if(min == INF) {
        std::cout << "-1\n";
    }
    else {
        std::cout << min << "\n";
    }


}