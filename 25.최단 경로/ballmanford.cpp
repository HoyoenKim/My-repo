#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::vector<long long>>> graph(n + 1);
    for(int i = 0 ; i < m ; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    int INF = INT32_MAX;
    std::vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    int isCycle = 0;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1; j <= n ; j++) {
            for(int k = 0 ; k < graph[j].size() ; k++) {
                if(dist[j] != INF) {
                    if(dist[graph[j][k][0]] > dist[j] + graph[j][k][1]) {
                        dist[graph[j][k][0]] = dist[j] + graph[j][k][1];
                        if(i == n) {
                            isCycle = 1;
                        }
                    }
                }
            }
        }
    }

    if(isCycle) {
        std::cout << -1 << "\n";
    }
    else {
        for(int i = 2 ; i <= n ; i++) {
            if(dist[i] == INF) {
                std::cout << -1 << "\n";
            }
            else {  
                std::cout << dist[i] << "\n";
            }
        }
    }
}