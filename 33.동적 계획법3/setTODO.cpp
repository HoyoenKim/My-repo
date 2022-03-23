#include <iostream>
#include <vector>

int n;
std::vector<std::vector<int>> p2w(20, std::vector<int>(20, 0));
std::vector<std::vector<int>> dp(20, std::vector<int>(1 << 20, -1)); 
// i - 1 번째 사람까지 일이 할당 되었고, 그 일의 할당 배열은 j와 같다.
// j의 k 번째 비트가 1이면 k 번째 일이 할당 된 것이다.

int dfs(int x, int allocated) {
    if(allocated == ((1 << n) - 1)) {
        // 모든 일이 할당 됨.
        return 0;
    }
    if(dp[x][allocated] == -1) {
        dp[x][allocated] = INT32_MAX;
        for(int i = 0 ; i < n ; i++) {
            if((allocated & (1 << i)) == 0) {
                dp[x][allocated] = std::min(dp[x][allocated], dfs(x + 1, (allocated | (1 << i))) + p2w[x][i]);
            }
        }
    }
    return dp[x][allocated];
}

int main() {
    std::cin >> n;    
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            std::cin >> p2w[i][j];
        }
    }
    std::cout << dfs(0, 0) << "\n";
}