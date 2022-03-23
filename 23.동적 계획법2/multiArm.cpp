#include <iostream>
#include <vector>

int n;
std::vector<int> w(31, 0);
std::vector<std::vector<int>> dp(31, std::vector<int>(15001, 0));

void solve(int i, int weight) {
    // dp[i][j] = (i번째까지 추를 사용했을 때 무게 j를 만들 수 있나?)
    // 1) i번째 추를 오른쪽에 올린다. (추 쪽) 2) i번째 추를 왼쪽에 올린다.(구슬 쪽) 3) 아무것도 하지 않는다.
    if(i > n) {
        return;
    }
    
    if(dp[i][weight] == 1) {
        return;
    }
    dp[i][weight] = 1;
    solve(i + 1, weight + w[i]);
    solve(i + 1, std::abs(weight - w[i]));
    solve(i + 1, weight);

}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 0 ; i < n ; i++) {
        std::cin >> w[i];
    }
    
    solve(0, 0);
    int m;
    std::cin >> m;
    for(int i = 0 ; i < m ; i++) {
        int x;
        std::cin >> x;
        if(x > 15000) {
            std::cout << "N ";
        }
        else if(dp[n][x] == 1) {
            std::cout << "Y ";
        }
        else {
            std::cout << "N ";
        }
    }
    std::cout << "\n";
}