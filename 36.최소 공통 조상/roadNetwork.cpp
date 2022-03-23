#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maxDepth = log(100000) / log(2) + 1;
vector<int> visited(100001, 0);

void findDepth (int current, int d, vector<int> &depth, vector<vector<int>> &parent, vector<vector<int>> &minLength, vector<vector<int>> &maxLength, vector<vector<vector<int>>> &tree) {
    depth[current] = d;
    visited[current] = 1;

    for(int i = 0 ; i < tree[current].size() ; i++) {
        int next = tree[current][i][0];
        int roadLength = tree[current][i][1];

        if(visited[next] == 0) {
            parent[next][0] = current;
            minLength[next][0] = roadLength;
            maxLength[next][0] = roadLength;
            findDepth(next, d + 1, depth, parent, minLength, maxLength, tree);
        }
    }
}

int minL = 1000001;
int maxL = 0;

void findLca(int u, int v, vector<int> &depth, vector<vector<int>> &parent, vector<vector<int>> &minLength, vector<vector<int>> &maxLength) {
    if(depth[u] > depth[v]) {
        swap(u, v);
    }

    for(int i = maxDepth - 1 ; i >= 0 ; i--) {
        if(depth[v] >= depth[u] + (1 << i)) {
            minL = min(minL, minLength[v][i]);
            maxL = max(maxL, maxLength[v][i]);
            v = parent[v][i];
        }
    }

    if(u == v) {
        return;
    }
    else {
        for(int i = maxDepth - 1 ; i >= 0 ; i--) {
            if(parent[u][i] != parent[v][i]) {
                minL = min(minL, minLength[u][i]);
                maxL = max(maxL, maxLength[u][i]);

                minL = min(minL, minLength[v][i]);
                maxL = max(maxL, maxLength[v][i]);
                
                u = parent[u][i];
                v = parent[v][i];
            }
        }

        minL = min(minL, minLength[u][0]);
        maxL = max(maxL, maxLength[u][0]);

        minL = min(minL, minLength[v][0]);
        maxL = max(maxL, maxLength[v][0]);

        return;
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
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    vector<int> depth(n + 1, 0);
    vector<vector<int>> parent(n + 1, vector<int> (maxDepth, 0));
    vector<vector<int>> minLength(n + 1, vector<int> (maxDepth, 0));
    vector<vector<int>> maxLength(n + 1, vector<int> (maxDepth, 0));
    findDepth(1, 0, depth, parent, minLength, maxLength, tree);

    for(int j = 1 ; j < maxDepth ; j++) {
        for(int i = 1 ; i <= n ; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
            minLength[i][j] = min(minLength[i][j - 1], minLength[parent[i][j - 1]][j - 1]);
            maxLength[i][j] = max(maxLength[i][j - 1], maxLength[parent[i][j - 1]][j - 1]);
        }
    }
    
    int m;
    cin >> m;
    for(int i = 0 ; i < m ; i++) {
        int d, e;
        cin >> d >> e;
        
        minL = 1000001;
        maxL = 0;
        findLca(d, e, depth, parent, minLength, maxLength);

        cout << minL << " " << maxL << "\n";
    }
}