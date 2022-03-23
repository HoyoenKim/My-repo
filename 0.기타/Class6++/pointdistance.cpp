#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void findDepth(int current, int d, vector<int> &depth, vector<int> &cost, vector<int> &visited, vector<vector<int>> &parent, vector<vector<vector<int>>> &tree) {
    visited[current] = 1;
    depth[current] = d;

    for(int i = 0 ; i < tree[current].size() ; i++) {
        int next = tree[current][i][0];
        int nextcost = tree[current][i][1];

        if(visited[next] == 0){
            cost[next] = cost[current] + nextcost;
            parent[next][0] = current;
            findDepth(next, d + 1, depth, cost, visited, parent, tree);
        }
    }
}

int maxDepth = log(40000) / log(2) + 1;
int findLCA(int u, int v, vector<int> &depth, vector<vector<int>> &parent) {
    if(depth[u] > depth[v]) {
        swap(u, v);
    }

    for(int i = maxDepth - 1 ; i >= 0 ; i--) {
        if(depth[v] >= depth[u] + (1 << i)) {
            v = parent[v][i];
        }
    }

    if(u == v) {
        return u;
    }

    for(int i = maxDepth - 1 ; i >= 0 ; i--) {
        if(parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

int main() {
    int n;
    cin >> n;
    vector<vector<vector<int>>> tree(n + 1);

    for(int i = 0 ; i < n - 1 ; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;
        tree[x].push_back({y, cost});
        tree[y].push_back({x, cost});
    }

    vector<int> depth(n + 1, 0);
    vector<int> cost(n + 1, 0);
    vector<int> visited(n + 1, 0);
    vector<vector<int>> parent(n + 1, vector<int> (maxDepth, 0));
    findDepth(1, 0, depth, cost, visited, parent, tree);
    
    for(int j = 1 ; j < maxDepth ; j++) {
        for(int i = 1 ; i <= n ; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
    
    int m;
    cin >> m;
    for(int i = 0 ; i < m ; i++) {
        int x, y;
        cin >> x >> y;

        int lca = findLCA(x, y, depth, parent);
        int answer = cost[x] + cost[y] - 2 * cost[lca];
        cout << answer << "\n";
    }
}