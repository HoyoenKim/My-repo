#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    vector<vector<int>> tobutable = {
        {100, 70, 40, 0, 0, 0},
        {70, 50, 30, 0, 0, 0},
        {40, 30, 20, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };
    int n, m;
    cin >> n;
    m = n;

    vector<vector<int>> capcity (n * m + 2, vector<int> (n * m + 2, 0));
    vector<vector<int>> flow (n * m + 2, vector<int> (n * m + 2, 0));
    vector<vector<int>> cost (n * m + 2, vector<int> (n * m + 2, 0));
    vector<vector<int>> graph (n * m + 2);
    vector<vector<int>> tobu (n, vector<int> (m, 0));
    int start = n * m, end = n * m + 1;
    for(int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        for(int j = 0 ; j < m ; j++) {
            tobu[i][j] = s[j] - 'A';
            int id = i * m + j;
            if((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
                capcity[start][id] = 1;
                capcity[id][end] = 1;

                graph[start].push_back(id);
                graph[id].push_back(start);

                graph[id].push_back(end);
                graph[end].push_back(id);
            }
            else {
                capcity[id][end] = 1;

                graph[id].push_back(end);
                graph[end].push_back(id);
            }
        }
    }
    
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
                int id = i * m + j;
                for(int k = 0 ; k < 4 ; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    int nid = nx * m + ny;
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                        int c = tobutable[tobu[i][j]][tobu[nx][ny]];
                        cost[id][nid] = - 1 * c;
                        cost[nid][id] = 1 * c;

                        capcity[id][nid] = 1;

                        graph[id].push_back(nid);
                        graph[nid].push_back(id);
                    }
                }
            }
        }
        
    }

    int total = 0;
    while(1) {
        vector<int> before (n * m + 2, -1);
        vector<int> dist (n * m + 2, INT32_MAX);
        vector<int> inQueue (n * m + 2, 0);
        queue<int> q;

        q.push(start);
        dist[start] = 0;
        inQueue[start] = 1;

        while(!q.empty()) {
            int current = q.front();
            inQueue[current] = 0;
            q.pop();

            for(int i = 0 ; i < graph[current].size() ; i++) {
                int next = graph[current][i];

                if(capcity[current][next] - flow[current][next] > 0 && dist[next] > dist[current] + cost[current][next]) {
                    dist[next] = dist[current] + cost[current][next];
                    before[next] = current;
                    
                    if(inQueue[next] == 0) {
                        q.push(next);
                        inQueue[next] = 1;
                    }
                }
            }
        }

        if(before[end] == -1) {
            break;
        }

        int minResidue = INT32_MAX;
        for(int now = end ; now != start ; now = before[now]) {
            minResidue = min(minResidue, capcity[before[now]][now] - flow[before[now]][now]);
        }

        for(int now = end ; now != start ; now = before[now]) {
            total += minResidue * cost[before[now]][now];
            flow[before[now]][now] += minResidue;
            flow[now][before[now]] -= minResidue;
        }
    }

    cout << -1 * total << "\n";
}