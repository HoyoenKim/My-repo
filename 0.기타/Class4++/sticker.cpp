#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;

    while(t > 0) {
        t--;

        int n;
        cin >> n;
        vector<vector<int>> sticker (2, vector<int> (n, 0));
        for(int i = 0 ; i < 2 ; i++) {
            for(int j = 0 ; j < n ; j++) {
                int score;
                cin >> score;
                sticker[i][j] = score;
            }
        }

        vector<vector<int>> dp (3, vector<int> (n, 0));

        for(int i = 0 ; i < n ; i++) {
            if(i == 0) {
                dp[0][i] = 0;
                dp[1][i] = sticker[0][i];
                dp[2][i] = sticker[1][i];
            }
            else {
                dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]);
                dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + sticker[0][i];
                dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + sticker[1][i];
            }
        }

        cout << max(dp[0][n - 1], max(dp[1][n - 1], dp[2][n - 1])) << "\n";
    }
}