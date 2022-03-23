#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::vector<int>>> graph(n + 1);
    for(int i = 0 ; i < m ; i++) {
        int x, y, v;
        std::cin >> x >> y >> v;
        graph[x].push_back({y, v});
    }

    int INF = INT32_MAX / 2;
    std::vector<std::vector<int>> dist(n + 1, std::vector<int>(n + 1, INF));
    for(int i = 1 ; i <= n ; i++) {
        dist[i][i] = 0;
        for(int j = 0 ; j < graph[i].size() ; j++) {
            dist[i][graph[i][j][0]] = std::min(dist[i][graph[i][j][0]], graph[i][j][1]);
        }
    }

    for(int k = 1 ; k <= n ; k++) {
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= n ; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            if(dist[i][j] == INF) {
                std::cout << 0 << " ";
            }
            else{
                std::cout << dist[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
}