#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findMaxIndependentSet (int current, vector<vector<int>> &tree, vector<vector<int>> &dp, vector<int> &visited, vector<int> &cost) {
    visited[current] = 1;

    dp[current][1] = cost[current];
    dp[current][0] = 0;

    for(int i = 0 ; i < tree[current].size() ; i++) {
        int next = tree[current][i];

        if(visited[next] == 0) {
            findMaxIndependentSet(next, tree, dp, visited, cost);
            dp[current][1] += dp[next][0];
            dp[current][0] += max(dp[next][0], dp[next][1]);
        }
    }
}

vector<int> element;
void findMaxIndependentSetElement (int current, int before, vector<vector<int>> &tree, vector<vector<int>> &dp, vector<int> &visited) {
    if(dp[current][1] > dp[current][0] && visited[before] == 0) {
        element.push_back(current);
        visited[current] = 1;
    }

    for(int i = 0 ; i < tree[current].size() ; i++) {
        int next = tree[current][i];

        if(next != before) {
            findMaxIndependentSetElement(next, current, tree, dp, visited);
        }
    }

}

int main() {
    int n;
    cin >> n;

    vector<int> cost (n + 1, 0);
    for(int i = 1 ; i <= n ; i++) {
        int c;
        cin >> c;

        cost[i] = c;
    }

    vector<vector<int>> tree (n + 1);
    for(int i = 0 ; i < n - 1 ; i++) {
        int x, y;
        cin >> x >> y;

        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    vector<vector<int>> dp (n + 1, vector<int> (2, 0));
    vector<int> visited (n + 1, 0);
    findMaxIndependentSet(1, tree, dp, visited, cost);

    vector<int> visited2 (n + 1, 0);
    findMaxIndependentSetElement(1, 1, tree, dp, visited2);

    cout << max(dp[1][0], dp[1][1]) << "\n";
    sort(element.begin(), element.end());
    for(int i = 0 ; i < element.size() ; i++) {
        cout << element[i] << " ";
    }
    cout << "\n";

}