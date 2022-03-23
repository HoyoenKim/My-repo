#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void getVertexCover(int current, vector<vector<int>> &tree, vector<int> &visited, vector<vector<int>> &vertexCover) {
    visited[current] = 1;
    vertexCover[current][1] = 1;

    for(int i = 0 ; i < tree[current].size() ; i++) {
        int next = tree[current][i];
        if(visited[next] == 0) {
            getVertexCover(next, tree, visited, vertexCover);
            vertexCover[current][0] += vertexCover[next][1];
            vertexCover[current][1] += min(vertexCover[next][1], vertexCover[next][0]);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for(int i = 0  ; i < n - 1 ; i++) {
        int x, y;
        cin >> x >> y;

        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    vector<vector<int>> vertexCover(n + 1, vector<int> (2, 0));
    vector<int> visited(n + 1, 0);
    getVertexCover(1, tree, visited, vertexCover);

    cout << min(vertexCover[1][0], vertexCover[1][1]) << "\n";
}