#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n + 1);
    std::vector<int> inDegree(n + 1, 0);
    std::vector<int> answer(n + 1, 0);

    for(int i = 0 ; i < m ; i++) {
        int x, y;
        std::cin >> x >> y;
        graph[x].push_back(y);
        inDegree[y] += 1;
    }

    // 진입차수 0 인 노드를 넣고 빼면서 진입차수 갱신
    // 빼는 순서대로가 topology sort 된 배열

    std::queue<int> q;
    for(int i = 1 ; i <= n ; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    for(int i = 1 ; i <= n ; i++) {
        if(q.empty()) {
            // exist cycle
            break;
        }

        int current = q.front();
        answer[i] = current;
        q.pop();

        for(int j = 0 ; j < graph[current].size() ; j++) {
            int next = graph[current][j];
            inDegree[next] -= 1;
            if(inDegree[next] == 0) {
                q.push(next);
            }
        }
    }

    for(int i = 1 ; i <= n ; i++) {
        std::cout << answer[i] << " ";
    }
    std::cout << "\n";
}