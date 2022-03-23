#include <iostream>
#include <vector>

using namespace std;

void findIndepSet (int current, vector<vector<int>> &graph, vector<vector<int>> &dp, vector<int> &visited, vector<int> &cost) {
    visited[current] = 1;

    dp[current][1] = cost[current];
    dp[current][0] = 0;
    for(int i = 0 ; i < graph[current].size() ; i++) {
        int next = graph[current][i];

        if(visited[next] == 0) {
            findIndepSet(next, graph, dp, visited, cost);
            dp[current][1] += dp[next][0];
            dp[current][0] += max(dp[next][1], dp[next][0]); 
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> cost (n + 1, 0);
    for(int i = 1 ; i <= n ; i++) {
        cin >> cost[i];
    }

    vector<vector<int>> graph (n + 1);
    for(int i = 0 ; i < n - 1 ; i++) {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<vector<int>> dp (n + 1, vector<int> (2, 0));
    vector<int> visited (n + 1, 0);

    findIndepSet(1, graph, dp, visited, cost);

    cout << max(dp[1][0], dp[1][1]) << "\n";
}