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

    while(t > 0) {
        t--;
        int n, m;
        cin >> n >> m;

        // 0 ~ n * m - 1, s = n * m, t = n * m + 1
        int INF = INT32_MAX - 1;
        vector<vector<int>> capcity (n * m + 2, vector<int> (n * m + 2, 0));
        vector<vector<int>> flow (n * m + 2, vector<int>(n * m + 2, 0));
        vector<vector<int>> graph (n * m + 2);       
        
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        
        int sum = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                int number;
                cin >> number;
                sum += number;

                int id = i * m + j;
                if(i % 2 == 0) {
                    if(j % 2 == 0) {
                        graph[n * m].push_back(id);
                        graph[id].push_back(n * m);
                        capcity[n * m][id] = number;
                        for(int k = 0 ; k < 4 ; k++) {
                            int nx = i + dx[k];
                            int ny = j + dy[k];
                            if(nx >= 0 && ny >= 0 && nx <= n - 1 && ny <= m - 1) {
                                int nid = nx * m + ny;
                                graph[id].push_back(nid);
                                graph[nid].push_back(id);
                                capcity[id][nid] = INF;
                            }
                        }
                    }
                    else {
                        graph[n * m + 1].push_back(id);
                        graph[id].push_back(n * m + 1);
                        capcity[id][n * m + 1] = number;
                    }
                }
                else {
                    if(j % 2 == 0) {
                        graph[n * m + 1].push_back(id);
                        graph[id].push_back(n * m + 1);
                        capcity[id][n * m + 1] = number;
                    }
                    else {
                        graph[n * m].push_back(id);
                        graph[id].push_back(n * m);
                        capcity[n * m][id] = number;
                        for(int k = 0 ; k < 4 ; k++) {
                            int nx = i + dx[k];
                            int ny = j + dy[k];
                            if(nx >= 0 && ny >= 0 && nx <= n - 1 && ny <= m - 1) {
                                int nid = nx * m + ny;
                                graph[id].push_back(nid);
                                graph[nid].push_back(id);
                                capcity[id][nid] = INF;
                            }
                        }
                    }
                }
            }
        }

        int total = 0, start = n * m, end = n * m + 1;
        while(1) {
            vector<int> before (n * m + 2, -1);
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

        cout << sum - total<< "\n";
    }
}