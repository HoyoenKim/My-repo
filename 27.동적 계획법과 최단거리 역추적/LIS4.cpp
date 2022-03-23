#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> seq(n, 0);

    for(int i = 0 ; i < n ; i++) {
        std::cin >> seq[i];
    }

    std::vector<int> dp(n, 1);

    int seqLen = 1;
    for(int i = 0 ; i < n ; i++) {
        int localMaxIndex = -1;
        int localMaxLen = -1;
        for(int j = 0 ; j < i ; j++) {
            if(seq[j] < seq[i] && dp[j] > localMaxLen) {
                localMaxLen = dp[j];
                localMaxIndex = j;
            }
        }
        if(localMaxIndex >= 0) {
            dp[i] = dp[localMaxIndex] + 1;
        }

        if(dp[i] > seqLen) {
            seqLen = dp[i];
        }
    }

    int count = seqLen;
    std::vector<int> lis;
    for(int i = n - 1 ; i >= 0 ; i--) {
        if(dp[i] == count) {
            lis.push_back(seq[i]);
            count -= 1;
        }
    }
    std::cout << seqLen << "\n";
    for(int i = seqLen - 1 ; i >= 0 ; i--) {
        std::cout << lis[i] << " ";
    }
    std::cout << "\n";
}