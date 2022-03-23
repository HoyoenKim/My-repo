#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> capcity (2 * n + 3, vector<int> (2 * n + 3, 0));
        vector<vector<int>> flow (2 * n + 3, vector<int> (2 * n + 3, 0));
        vector<vector<int>> cost (2 * n + 3, vector<int> (2 * n + 3, 0));
        vector<vector<int>> graph(2 * n + 3);

        for(int i = 1 ; i <= n ; i++) {
            capcity[i][i + n] = INT32_MAX;
            graph[i].push_back(i + n);
            graph[i + n].push_back(i);
        }

        for(int i = 0 ; i < m ; i++) {
            int x, y;
            cin >> x >> y;
            cost[x + n][y] = 1;
            cost[y][x + n] = -1;

            cost[y + n][x] = 1;
            cost[x][y + n] = -1;

            capcity[x + n][y] = INT32_MAX;
            capcity[y + n][x] = INT32_MAX;

            graph[x + n].push_back(y);
            graph[y].push_back(x + n);
            graph[y + n].push_back(x);
            graph[x].push_back(y + n);
        }

        //src -> black coin (or white)
        //black point -> sink (or white)
        for(int i = 1 ; i <= n ; i++) {
            int pointcolor;
            cin >> pointcolor;
            if(pointcolor == 1) {
                capcity[i + n][2 * n + 2] = 1;
                graph[i + n].push_back(2 * n + 2);
                graph[2 * n + 2].push_back(i + n);
            }
        }

        for(int i = 1 ; i <= n ; i++) {
            int coincolor;
            cin >> coincolor;
            if(coincolor == 1) {
                capcity[2 * n + 1][i] = 1;
                graph[2 * n + 1].push_back(i);
                graph[i].push_back(2 * n + 1);
            }
        }

        int total = 0, start = 2 * n + 1, end = 2 * n + 2;
        while(1) {
            vector<int> before(2 * n + 3, -1);
            vector<int> dist(2 * n + 3, INT32_MAX);
            vector<int> inQueue(2 * n + 3, 0);
            queue<int> q;
            
            dist[start] = 0;
            inQueue[start] = 1;
            q.push(start);

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
                total += cost[before[now]][now] * minResidue;
                flow[before[now]][now] += minResidue;
                flow[now][before[now]] -= minResidue;
            }
        }

        cout << total << "\n";
    }
}