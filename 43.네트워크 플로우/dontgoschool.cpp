#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> space(n, vector<int> (m, 0));
    int did;
    int sid;
    for(int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        for(int j = 0 ; j < m ; j++) {
            int element = 0;
            if(s[j] == '.') {
                element = 0;
            }
            else if(s[j] == '#') {
                element = 1;
            }
            else if(s[j] == 'K') {
                element = 0;
                did = i * m + j;
            }
            else if(s[j] == 'H') {
                element = 0;
                sid = i * m + j;
            }
            space[i][j] = element;
        }
    }

    vector<vector<int>> flow (n * m, vector<int> (n * m, 0));
    vector<vector<int>> capcity (n * m, vector<int> (n * m, 0));
    vector<vector<int>> graph (n * m);
    
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            int id = i * m + j;
            for(int k = 0 ; k < 4 ; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                int nid = nx * m + ny;
                if(nx >= 0 && ny >= 0 && nx <= n - 1 && ny <= m -1 && space[nx][ny] == 0) {
                    capcity[id][nid] = 1;
                    graph[id].push_back(nid);
                    graph[nid].push_back(id);
                }
            }
        }
    }

    int total = 0, start = did, end = sid;

    int isPossible = 1;
    for(int i = 0 ; i < graph[start].size() ; i++) {
        int next = graph[start][i];
        if(next == end) {
            isPossible = 0;
            cout << "-1\n";
            return 0;
        }
    }

    while(1) {
        vector<int> before(n * m, -1);
        queue<int> q;
        q.push(start);

        while(!q.empty()) {
            int current = q.front();
            q.pop();

            for(int i = 0 ; i < graph[current].size() ; i++) {
                int next = graph[current][i];

                if(before[next] == -1 && capcity[current][next] - flow[current][next] > 0) {
                    before[next] = current;
                    q.push(next);

                    if(next == end) {
                        break;
                    }
                }
            }
        }

        if(before[end] == -1) {
            break;
        }

        int minResidue = INT32_MAX;
        int now = end;
        while(now != start) {
            minResidue = min(minResidue, capcity[before[now]][now] - flow[before[now]][now]);
            now = before[now];
        }

        now = end;
        while(now != start) {
            flow[before[now]][now] += minResidue;
            flow[now][before[now]] -= minResidue;
            now = before[now];
        }

        total += minResidue;
    }

    cout << total << "\n";
}