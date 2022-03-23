#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> seq(n, 0);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> seq[i];
    }

    int lis = 0;
    std::vector<int> dp;
    std::vector<int> index(n, 0);
    for(int i = 0 ; i < n ; i++) {
        int localMaxIdx = lower_bound(dp.begin(), dp.end(), seq[i]) - dp.begin();
        if(localMaxIdx == lis) {
            dp.push_back(seq[i]);
            lis += 1;
        }
        else {
            dp[localMaxIdx] = seq[i];
        }
        index[i] = localMaxIdx;
    }

    std::cout << lis << "\n";
    int count = lis;
    std::vector<int> answer;
    for(int i = n - 1 ; i >= 0 ; i--) {
        if(index[i] == count - 1) {
            answer.push_back(seq[i]);
            count -= 1;
        }
    }
    for(int i = answer.size() - 1 ; i >= 0 ; i--) {
        std::cout << answer[i] << " ";
    }
    std::cout << "\n";
}