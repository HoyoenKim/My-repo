#include <iostream>
#include <vector>
#include <queue>

struct compare {
    bool operator() (std::vector<int> a, std::vector<int> b) {
        return a[1] > b[1];
    }
};

int n, m;
int INF = INT32_MAX;
int dijstra(int start, int end, std::vector<std::vector<std::vector<int>>> &graph) {

    std::vector<int> check(n + 1, 0);
    std::vector<int> dist(n + 1, INF);
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, compare> q;

    q.push({start, 0});
    dist[start] = 0;

    while(!q.empty()) {
        int x = q.top()[0];
        int v = q.top()[1];
        q.pop();
        check[x] = 1;

        for(int i = 0 ; i < graph[x].size() ; i++) {
            int nx = graph[x][i][0];
            int nv = graph[x][i][1];

            if(check[nx] == 0 && dist[nx] > dist[x] + nv) {
                dist[nx] = dist[x] + nv;
                q.push({nx, dist[nx]});
            }

        }
    }
    return dist[end];
}

int main() {
    std::cin >> n >> m;
    std::vector<std::vector<std::vector<int>>> graph(n + 1);

    for(int i = 0 ; i < m ; i++) {
        int x, y, value;
        std::cin >> x >> y >> value;
        graph[x].push_back({y, value});
        graph[y].push_back({x, value});
    }

    int a, b;
    std::cin >> a >> b;

    
    int x1 = dijstra(1, a, graph);
    int x2 = dijstra(a, b, graph);
    int x3 = dijstra(b, n, graph);

    int candid1 = INF;
    if(x1 != INF && x2 != INF && x3 != INF) {
        candid1 = x1 + x2 + x3;
    } 
    
    int y1 = dijstra(1, b, graph);
    int y2 = dijstra(b, a, graph);
    int y3 = dijstra(a, n, graph);

    int candid2 = INF;
    if(y1 != INF && y2 != INF && y3 != INF) {
        candid2 = y1 + y2 + y3;
    }

    int d = std::min(candid1, candid2);
    
    if(d == INF) {
        std::cout << -1<< "\n";
    }
    else {
        std::cout << d << "\n";
    }
}