#include <iostream>
#include <vector>
#include <stack>

int n, m;
std::vector<std::vector<int>> a(500, std::vector<int>(500, 0));
std::vector<std::vector<int>> dp(500, std::vector<int>(500, -1));
// (a, b) -> (n - 1, m - 1) 까지의 가는 방법

std::vector<int> dx = {1, -1, 0, 0};
std::vector<int> dy = {0, 0, 1, -1};

int dfs(int x, int y) {
    if(x == n - 1 && y == m - 1) {
        return 1;
    }

    if(dp[x][y] == -1) {
        dp[x][y] = 0;
        for(int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx <= n - 1 && 0 <= ny && ny <= m - 1) {
                if(a[x][y] > a[nx][ny]) {
                    dp[x][y] = dp[x][y] + dfs(nx, ny);
                }   
            }
        }
    }
    return dp[x][y];
}



int main() {
    std::cin >> n >> m;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            std::cin >> a[i][j];
        }
    }
    std::cout << dfs(0, 0) << "\n";
}