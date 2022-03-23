#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int maxDepth = log(100000) / log(2) + 1;
vector<int> check(100000, 0);

void findDepth(int root, int d, vector<int> &depth, vector<vector<int>> &parent, vector<vector<int>> &tree) {
    depth[root] = d;
    check[root] = 1;

    for(int i = 0 ; i < tree[root].size() ; i++) {
        int next = tree[root][i];
        if(check[next] == 0) {
            parent[next][0] = root;
            findDepth(next, d + 1, depth, parent, tree);
        }

    }
}

int findLca(int u, int v, vector<int> &depth, vector<vector<int>> &parent) {
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for(int i = 0 ; i < n - 1 ; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> depth(n + 1, 0);
    vector<vector<int>> parent(n + 1, vector<int> (maxDepth, 0));
    findDepth(1, 0, depth, parent, tree);
    for(int j = 1 ; j < maxDepth ; j++) {
        for(int i = 1 ; i <= n ; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    int m;
    cin >> m;
    for(int i = 0 ; i < m ; i++) {
        int u, v;
        cin >> u >> v;
        cout <<  findLca(u, v, depth, parent) << "\n";
    }

}