#include <iostream>
#include <vector>
#include <queue>

struct compare {
    bool operator() (std::vector<int> &a, std::vector<int> &b) {
        return a[2] > b[2];
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    while(N > 0) {
        N--;

        int n, m, k;
        std::cin >> n >> m >> k;

        std::vector<std::vector<std::vector<int>>> graph(n + 1);
        for(int i = 0 ; i < k ; i++) {
            int u, v, c, t;
            std::cin >> u >> v >> c >> t;
            graph[u].push_back({v, c, t});
        }

        int INF = INT32_MAX / 2; 
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, INF));
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, compare> q;

        q.push({1, 0, 0});
        dp[1][0] = 0;
        while(!q.empty()) {
            int current = q.top()[0];
            int currentCost = q.top()[1];
            int currentTime = q.top()[2];
            q.pop();

            if(dp[current][currentCost] < currentTime) {
                continue;
            }

            for(int i = 0 ; i < graph[current].size() ; i++) {
                int next = graph[current][i][0];
                int nextCost = graph[current][i][1] + currentCost;
                int nextTime = graph[current][i][2] + dp[current][currentCost];

                if(nextCost <= m) {
                    if(dp[next][nextCost] > nextTime) {
                        for(int i = nextCost ; i <= m ; i++) {
                            if(dp[next][i] > nextTime) {
                                dp[next][i] = nextTime;
                            }
                        }
                        q.push({next, nextCost, nextTime});
                    }
                }
            }

        }
        
        int answer = INF;
        for(int i = 0 ; i <= m ; i++) {
            answer = std::min(answer, dp[n][i]);
        }

        if(answer == INF) {
            std::cout << "Poor KCM\n";
        }
        else {
            std::cout << answer << "\n";
        }
    }
}