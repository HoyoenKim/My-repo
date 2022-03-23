#include <iostream>
#include <vector>


void floydWarshall() {
    // 모든 정점에서 모든 정점으로의 최단 경로를 구하고자 할 때 사용
    // x -> y vs x -> z -> y (for z = 1, .. n)
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::vector<long long>>> graph(n + 1);
    for(int i = 0 ; i < m ; i++) {
        long long x, y, value;
        std::cin >> x >> y >> value;
        graph[x].push_back({y, value});
    }
    long long INF = INT32_MAX - 1;
    std::vector<std::vector<long long>> dist(n + 1, std::vector<long long>(n + 1, INF));
    for(int i = 1 ; i <= n ; i++) {
        dist[i][i] = 0;
        for(int j = 0 ; j < graph[i].size() ; j++) {
            dist[i][graph[i][j][0]] = std::min(dist[i][graph[i][j][0]], graph[i][j][1]);
        }
    }

    for(int k = 1 ; k <= n ; k++) {
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= n ; j++) {
                // i -> j vs i -> k -> j;
                long long dist1 = dist[i][j];
                long long dist2 = dist[i][k] + dist[k][j];
                if(dist2 < dist1) {
                    dist[i][j] = dist2;
                }
            }
        }
    }

    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            if(dist[i][j] == INF) {
                std::cout << 0 << " ";
            }
            else {
                std::cout << dist[i][j] << " ";
            }
        }
        std::cout << "\n";
    }

}