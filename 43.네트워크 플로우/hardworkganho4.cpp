#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    // 0 ~ n -1 사람
    // n ~ n + m - 1 일
    // 소스 n + m, 소스2 n + m + 1, 싱크 n + m + 2

    int nn = n + m;
    vector<vector<int>> capcity(nn + 3, vector<int> (nn + 3, 0));
    vector<vector<int>> flow(nn + 3, vector<int> (nn + 3, 0));
    vector<vector<int>> graph(nn + 3);

    capcity[nn][nn + 1] = k;
    capcity[nn + 1][nn] = k;

    graph[nn].push_back(nn + 1);
    graph[nn + 1].push_back(nn);
    
    for(int i = 0 ; i < n ; i++) {
        // 소스, 소스2 -> 사람
        capcity[nn][i] = 1;
        capcity[nn + 1][i] = k;

        graph[nn].push_back(i);
        graph[i].push_back(nn);

        graph[nn + 1].push_back(i);
        graph[i].push_back(nn + 1);
    }

    for(int i = 0 ; i < m ; i++) {
        // 일 -> 싱크
        capcity[i + n][nn + 2] = 1;

        graph[i + n].push_back(nn + 2);
        graph[nn + 2].push_back(i + n);
    }

    for(int i = 0 ; i < n ; i++) {
        int worknum;
        cin >> worknum;
        for(int j = 0 ; j < worknum ; j++) {
            int workIndex;
            cin >> workIndex;
            workIndex--;

            capcity[i][workIndex + n] = 1;

            graph[i].push_back(workIndex + n);
            graph[workIndex + n].push_back(i);
        }
    }

    int total = 0, start = nn, end = nn + 2;
    while(1) {
        vector<int> before(nn + 3, -1);
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