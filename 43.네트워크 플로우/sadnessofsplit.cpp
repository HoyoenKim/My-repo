#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int INF = INT32_MAX;

bool bfs(int start, int end, vector<int> &level, vector<vector<int>> &graph, vector<vector<int>> &capcity, vector<vector<int>> &flow) {
    queue<int> q;
    
    q.push(start);
    level[start] = 0;

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        for(int i = 0 ; i < graph[current].size() ; i++) {
            int next = graph[current][i];

            if(level[next] == -1 && capcity[current][next] - flow[current][next] > 0) {
                q.push(next);
                level[next] = level[current] + 1;
            }
        }
    }

    if(level[end] == -1) {
        return false;
    }
    
    return true;
}

int dfs(int current, int end, int f, vector<int> &work, vector<int> &level, vector<vector<int>> &graph, vector<vector<int>> &capcity, vector<vector<int>> &flow) {
    if(current == end) {
        return f;
    }
    for(int i = work[current] ; i < graph[current].size() ; i++) {
        work[current] += 1;
        int next = graph[current][i];
        int tempf = capcity[current][next] - flow[current][next];

        if(level[next] == level[current] + 1 && tempf > 0) {
            int nf = dfs(next, end, min(tempf, f), work, level, graph, capcity, flow);
            if(nf > 0) {
                flow[current][next] += nf;
                flow[next][current] -= nf;
                return nf;
            }
        }

    }
    return 0;
}

int main() {
    cin >> n;

    vector<vector<int>> capcity (n + 2, vector<int> (n + 2, 0));
    vector<vector<int>> flow (n + 2, vector<int> (n + 2, 0));
    vector<vector<int>> graph (n + 2);
    int start = n, end = n + 1;
    for(int i = 0 ; i < n ; i++) {
        int type;
        cin >> type;

        if(type == 1) {
            // source -> i;
            capcity[start][i] = INF;

            graph[start].push_back(i);
            graph[i].push_back(start);
        }
        else if(type == 2) {
            // i -> sink
            capcity[i][end] = INF;

            graph[i].push_back(end);
            graph[end].push_back(i);
        }
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            int sad;
            cin >> sad;
            capcity[i][j] = sad;
            if(i != j) {
                graph[i].push_back(j);
            }
        }
    }

    int total = 0;
    while(1) {
        vector<int> level (n + 2, -1);
        if(bfs(start, end, level, graph, capcity, flow) == 0) {
            break;
        }

        vector<int> work (n + 2, 0);
        while(1) {
            int f = dfs(start, end, INF, work, level, graph, capcity, flow);
            if(f == 0) {
                break;
            }
            total += f;
        }
    }
    cout << total << "\n";

    vector<int> visited(n + 2, 0);
    queue<int> q;

    q.push(start);
    visited[start] = 1; 
    while(!q.empty()) {
        int current = q.front();
        q.pop();

        for(int i = 0 ; i < graph[current].size() ; i++) {
            int next = graph[current][i];
            
            if(visited[next] == 0 && capcity[current][next] - flow[current][next] > 0) {
                q.push(next);
                visited[next] = 1;
            }
        }
    }

    for(int i = 0 ; i < n ; i++) {
        if(visited[i] == 1) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
    for(int i = 0 ; i < n ; i++) {
        if(visited[i] == 0) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
    
}