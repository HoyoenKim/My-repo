#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool findMatching(int current, vector<vector<int>> &graph, vector<int> &visited, vector<int> &matched) {
    visited[current] = 1;

    for(int i = 0 ; i < graph[current].size() ; i++) {
        int next = graph[current][i];

        if(matched[next] == -1 || visited[matched[next]] == 0 && findMatching(matched[next], graph, visited, matched)) {
            matched[next] = current;
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t > 0) {
        t--;
        int n, m;
        cin >> n >> m;
        vector<vector<int>> space(n, vector<int> (m, 0));
        int pointnum = n * m;

        for(int i = 0 ; i < n ; i++) {
            string s;
            cin >> s;
            for(int j = 0 ; j < m ; j++) {
                if(s[j] == 'x') {
                    space[i][j] = 1;
                    pointnum -= 1;
                }
            }
        }

        vector<int> dx = {-1, 0, -1, 0, 1, 1};
        vector<int> dy = {-1, -1, 1, 1, -1, 1};

        vector<vector<int>> graph(n * m);
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(j % 2 == 0 && space[i][j] == 0) {
                    int id = i * m + j;
                    for(int k = 0 ; k < 6 ; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        int nid = nx * m + ny;
                        if(nx >= 0 && ny >= 0 && nx < n && ny < m && space[nx][ny] == 0) {
                            graph[id].push_back(nid);
                        }
                    }
                }
            }
        }

        int count = 0;
        vector<int> matched (n * m, -1);
        for(int i = 0 ; i < n * m ; i++) {
            vector<int> visited(n * m, 0);
            if(findMatching(i, graph, visited, matched)) {
                count += 1;
            }
        }

        cout << pointnum - count << "\n";
    }
}