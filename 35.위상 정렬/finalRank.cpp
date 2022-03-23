#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t > 0) {
        t--;
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> graph(n + 1);
        std::vector<int> array(n, 0);
        for(int i = 0 ; i < n ; i++) {
            std::cin >> array[i];
        }

        for(int i = 0 ; i < n ; i++) {
            for(int j = i + 1 ; j < n ; j++) {
                graph[array[i]].push_back(array[j]);
            }
        }

        int m;
        std::cin >> m;
        for(int i = 0 ; i < m ; i++) {
            int a, b;
            std::cin >> a >> b;
            graph[b].erase(std::find(graph[b].begin(), graph[b].end(), a));
            graph[a].push_back(b);
        }

        std::vector<int> inDegree(n + 1, 0);
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 0 ; j < graph[i].size() ; j++) {
                inDegree[graph[i][j]] += 1;
            }
        }

        std::vector<int> answer(n + 1, 0);
        int isCycle = 0;
        std::queue<int> q;
        for(int i = 1 ; i <= n ; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        for(int i = 1 ; i <= n ; i++) {
            if(q.empty()) {
                // exist cycle
                isCycle = 1;
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

        if(isCycle) {
            std::cout << "IMPOSSIBLE\n";
        }
        else {
            for(int i = 0 ; i < answer.size() ; i++) {
                std::cout << answer[i] << " ";
            }
            std::cout << "\n";
        }
    }
}