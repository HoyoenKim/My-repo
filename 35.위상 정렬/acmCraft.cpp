#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;

    while(t > 0) {
        t--;
        int n, k;
        std::cin >> n >> k;
        
        std::vector<int> d(n + 1, 0);
        for(int i = 1 ; i <= n ; i++) {
            std::cin >> d[i];
        }

        std::vector<int> inDegree(n + 1, 0);

        std::vector<std::vector<int>> graph(n + 1);
        for(int i = 0 ; i < k ; i++) {
            int x, y;
            std::cin >> x >> y;
            graph[x].push_back(y);
            inDegree[y] += 1;
        }

        int w;
        std::cin >> w;

        std::vector<int> answer(n + 1, 0);
        std::queue<int> q;
        for(int i = 1 ; i <= n ; i++) {
            if(inDegree[i] == 0) {
                answer[i] = d[i];
                q.push(i);
            }
        }

        for(int i = 0 ; i < n ; i++) {
            if(q.empty()) {
                break;
            }

            int current = q.front();
            q.pop();
            for(int j = 0 ; j < graph[current].size() ; j++) {
                int nxt = graph[current][j];
                answer[nxt] = std::max(answer[nxt], answer[current] + d[nxt]);
                inDegree[nxt] -= 1;
                if(inDegree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }
        std::cout << answer[w] << "\n";
    }
}