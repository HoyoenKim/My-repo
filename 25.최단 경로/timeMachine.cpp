#include <iostream>
#include <vector>

int main() {
    std::ios_base :: sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::vector<long long>>> graph(n + 1);
    for(int i = 0 ; i < m ; i++) {
        long long x, y, value;
        std::cin >> x >> y >> value;
        graph[x].push_back({y, value});
    }

    int start = 1;
    long long INF = INT32_MAX;
    std::vector<long long> dist(n + 1, INF);
    // 음수 간선이 포함되어 있기 때문에 벨만 포드 알고리즘 사용.
    // 이는 한 점을 여러 번 방문 할 수도 있음.
    // 하지만, 음수 사이클이 존재하기 때문에 path의 길이는 n - 1이 최대임.
    // 거리를 무한대로 설정한 뒤 방문한 곳에 한해서만 거리를 갱신함.
    
    dist[start] = 0;
    int isCycle = 0;
    for(int i = 1 ; i <= n ; i++) {
        // path의 길이
        for(int j = 1 ; j <= n ; j++) {
            int current = j;
            // j -> graph[j][k][0] 으로 path를 고려해 갱신.
            for(int k = 0 ; k < graph[current].size() ; k++) {
                int next = graph[current][k][0];
                long long value = graph[current][k][1];
                long long candid = value + dist[current];
                if(dist[current] != INF && dist[next] > candid) {
                    dist[next] = candid;
                    if(i == n) {
                        isCycle = 1;
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