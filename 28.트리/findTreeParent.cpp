#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> graph(n + 1);

    for(int i = 0 ; i < n - 1; i++) {
        int x, y;
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    std::vector<int> check(n + 1);
    std::vector<int> parent(n + 1);
    std::queue<int> q;
    q.push(1);
    check[1] = 0;
    while(!q.empty()) {
        int current = q.front();
        q.pop();

        for(int j = 0 ; j < graph[current].size() ; j++) {
            int next = graph[current][j];
            if(check[next] == 0) {
                parent[next] = current;
                q.push(next);
                check[next] = 1;
            }
        }
    }

    for(int i = 2 ; i <= n ; i++) {
        std::cout << parent[i] << "\n";
    }
}