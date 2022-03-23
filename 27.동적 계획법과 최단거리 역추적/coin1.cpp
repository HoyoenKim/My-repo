#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4 ; i <= n ; i++) {
        int minCount = dp[i - 1];
        if(i % 2 == 0) {
            minCount = std::min(minCount, dp[i / 2]);
        } 

        if(i % 3 == 0) {
            minCount = std::min(minCount, dp[i / 3]);
        }
        dp[i] = minCount + 1;
    }
    std::cout << dp[n] << "\n";

    std::vector<int> answer;
    answer.push_back(n);
    int track = n;
    while(track > 1) {
        int next = track - 1;
        if(track % 2 == 0) {
            if(dp[next] > dp[track / 2]) {
                next = track / 2;
            }
        }

        if(track % 3 == 0) {
            if(dp[next] > dp[track / 3]) {
                next = track / 3;
            }
        }
        track = next;
        answer.push_back(track);
    }

    for(int i = 0 ; i < answer.size() ; i++) {
        std::cout << answer[i] << " ";
    }
    std::cout << "\n";
}