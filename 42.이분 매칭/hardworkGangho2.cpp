#include <iostream>
#include <vector>

using namespace std;

bool findMatching(int current, vector<vector<int>> &graph, vector<int> &whowork, vector<int> &visited) {
    visited[current] = 1;

    for(int i = 0 ; i < graph[current].size() ; i++) {
        int next = graph[current][i];

        if(visited[whowork[next]] == 0) {
            if(whowork[next] == 0 || findMatching(whowork[next], graph, whowork, visited)) {
                whowork[next] = current;
                
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(2 * n + 1);

    for(int i = 1 ; i <= n ; i++) {
        int workNum;
        cin >> workNum;

        for(int j = 0 ; j < workNum ; j++) {
            int workIndex;
            cin >> workIndex;

            graph[i].push_back(workIndex);
            graph[i + n].push_back(workIndex);
        }
    }

    int count = 0;
    vector<int> whowork (m + 1, 0);
    for(int i = 1 ; i <= 2 * n ; i++) {
        vector<int> visited (2 * n + 1, 0);
        if(findMatching(i, graph, whowork, visited)) {
            count += 1;
        }
    }

    cout << count << "\n";
}