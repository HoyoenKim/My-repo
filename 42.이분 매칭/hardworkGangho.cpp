#include <iostream>
#include <vector>

using namespace std;

// 네트워크 플로우 문제에서 Capicity = 1 인 경우
// 이때는 에드몬드 카프 알고리즘 보다 더 효율적으로 DFS를 사용해서 해결 할 수 있다.
// 1 -> A, B, C / 2 -> A / 3 -> B;
// 1 -> A
// 2 -> A, 1 -> B
// 2 -> A, 3 -> B, 1 -> C

bool findMatching(int current, vector<vector<int>> &graph, vector<int> &visited, vector<int> &workMatched) {
    visited[current] = 1;

    for(int i = 0 ; i < graph[current].size() ; i++) {
        int next = graph[current][i];

        if(visited[workMatched[next]] == 0) {
            if(workMatched[next] == 0 || findMatching(workMatched[next], graph, visited, workMatched)) {
                workMatched[next] = current;
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for(int i = 1 ; i <= n ; i++) {
        int workNum;
        cin >> workNum;

        for(int j = 0 ; j < workNum ; j++) {
            int workIndex;
            cin >> workIndex;
            graph[i].push_back(workIndex);
        }
    }

    int count = 0;
    vector<int> workMatched (m + 1, 0);
    for(int i = 1 ; i <= n ; i++) {
        vector<int> visited(n + 1, 0);
        if(findMatching(i, graph, visited, workMatched)) {
            count += 1;
        }
    }

    cout << count << "\n";
}