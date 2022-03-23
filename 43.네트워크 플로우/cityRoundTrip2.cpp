#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    vector<vector<int>> capcity (2 * n + 1, vector<int>(2 * n + 1, 0));
    vector<vector<int>> flow (2 * n + 1, vector<int> (2 * n + 1, 0));
    vector<vector<int>> graph (2 * n + 1);

    for(int i = 0 ; i < p ; i++) {
        int x, y;
        cin >> x >> y;

        capcity[x + n][y] = 1;
        capcity[y + n][x] = 1;

        graph[x + n].push_back(y);
        graph[y].push_back(x + n);
        
        graph[y + n].push_back(x);
        graph[x].push_back(y + n);
    }

    for(int i = 1 ; i <= n ; i++) {
        capcity[i][i + n] = 1;
        graph[i].push_back(i + n);
        graph[i + n].push_back(i);
    }

    int total = 0, start = 1 + n, end = 2;

    while(1) {
        vector<int> before(2 * n + 1, -1);
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