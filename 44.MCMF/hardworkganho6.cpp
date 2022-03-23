#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // 소스 -> 사람
    // 사람 -> 일
    // 일 -> 싱크
    // 사람: 0 ~ n - 1
    // 일: n ~ n + m - 1
    // 소스: n + m, 싱크: n + m + 1;

    vector<vector<int>> capcity (n + m + 2, vector<int> (n + m + 2, 0));
    vector<vector<int>> flow (n + m + 2, vector<int> (n + m + 2, 0));
    vector<vector<int>> cost (n + m + 2, vector<int> (n + m + 2, 0));
    vector<vector<int>> graph (n + m + 2);
            
            
    for(int i = 0 ; i < n ; i++) {
        // 소스 -> 사람
        capcity[n + m][i] = 1;
        graph[n + m].push_back(i);
        graph[i].push_back(n + m);
    }

    for(int i = 0 ; i < m ; i++) {
        // 일 -> 싱크
        capcity[i + n][n + m + 1] = 1;
        graph[i + n].push_back(n + m + 1);
        graph[n + m + 1].push_back(i + n);
    }

    int INF = 100000;
    for(int i = 0 ; i < n ; i++) {
        int worknum;
        cin >> worknum;
        for(int j = 0; j < worknum ; j++) {
            int workindex, workcost;
            cin >> workindex >> workcost;
            workindex -= 1;
            
            // 사람 -> 일
            capcity[i][workindex + n] = INF;
            cost[i][workindex + n] = -1 * workcost;
            cost[workindex + n][i] = workcost;
            graph[i].push_back(workindex + n);
            graph[workindex + n].push_back(i);
        }
    }

    int result = 0, total = 0, start = n + m, end = n + m + 1;
    while(1) {
        vector<int> before(n + m + 2, -1);
        vector<int> dist(n + m + 2, INF);
        vector<int> isInQueue(n + m + 2, 0);
        queue<int> q;

        dist[start] = 0;
        isInQueue[start] = 1;
        q.push(start);

        while(!q.empty()) {
            int current = q.front();
            q.pop();
            isInQueue[current] = 0;

            for(int i = 0 ; i < graph[current].size() ; i++) {
                int next = graph[current][i];

                if(capcity[current][next] - flow[current][next] > 0 && dist[next] > dist[current] + cost[current][next]) {
                    dist[next] = dist[current] + cost[current][next];
                    before[next] = current;

                    if(isInQueue[next] == 0) {
                        q.push(next);
                        isInQueue[next] = 1;
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
            result += minResidue * cost[before[now]][now];

            flow[before[now]][now] += minResidue;
            flow[now][before[now]] -= minResidue;
            now = before[now];
        }

        total += minResidue;
    }

    cout << total << "\n" << -1 * result << "\n";
}