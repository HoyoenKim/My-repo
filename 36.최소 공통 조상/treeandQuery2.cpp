#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maxDepth = log(100000) / log(2) + 1;
vector<int> visited(100001, 0);
void findDepth(int current, int d, vector<int> &depth, vector<vector<int>> &parent, vector<long long> &cost, vector<vector<vector<int>>> &tree) {
    visited[current] = 1;
    depth[current] = d;

    for(int i = 0 ; i < tree[current].size() ; i++) {
        int next = tree[current][i][0];
        int nextCost = tree[current][i][1];

        if(visited[next] == 0) {
            parent[next][0] = current;
            cost[next] = (long long) nextCost + cost[current];
            findDepth(next, d + 1, depth, parent, cost, tree);
        }
    }
}

int findLca(int u, int v, vector<int> &depth, vector<vector<int>> &parent) {
    if(depth[u] >  depth[v]) {
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
    else {
        for(int i = maxDepth - 1 ; i >= 0 ; i--) {
            if(parent[u][i] != parent[v][i]) {
                u = parent[u][i];
                v = parent[v][i];
            }
        }

        return parent[u][0];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<vector<int>>> tree(n + 1);
    for(int i = 0 ; i < n - 1 ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    vector<int> depth(n + 1, 0);
    vector<vector<int>> parent(n + 1, vector<int> (maxDepth, 0));
    vector<long long> cost(n + 1, 0);

    findDepth(1, 0, depth, parent, cost, tree);

    for(int j = 1 ; j < maxDepth ; j++) {
        for(int i = 1 ; i <= n ; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    int m;
    cin >> m;
    for(int i = 0 ; i < m ; i++) {
        int queryType;
        cin >> queryType;

        int u, v;
        cin >> u >> v;
        
        int lca = findLca(u, v, depth, parent);
        if(queryType == 1) {
            // (root -> u) - (root -> lca) + (root -> v) - (root -> lca) 
            long long answer = cost[u] + cost[v] - 2LL * cost[lca];
            cout << answer << "\n";
        }
        else if(queryType == 2) {
            int k;
            cin >> k;
            int nodeNum = depth[u] - depth[lca] + 1;

            if(k == nodeNum) {
                cout << lca << "\n";
            } 
            else if(k < nodeNum) {
                // u -> lca
                k -= 1; // u is start
                for(int i = maxDepth - 1 ; i >= 0 ; i--) {
                    if((k >> i) & 1 == 1) {
                        u = parent[u][i];
                    }
                }
                cout << u << "\n";
            }
            else {
                // lca -> v
                k -= nodeNum; // lca is start
                k = depth[v] - depth[lca] + 1 - k;
                k -= 1; // v is start
                for(int i = maxDepth - 1 ; i >= 0 ; i--) {
                    if((k >> i) & 1 == 1) {
                        v = parent[v][i];
                    }
                }
                cout << v << "\n";
            }
        }
    }
}