#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    while(N > 0) {
        N--;

        int t;
        std::cin >> n >> m >> t;
        int s, g, h;
        std::cin >> s >> g >> h;


        int distance = 0;
        std::vector<std::vector<std::vector<int>>> graph(n + 1);
        for(int i = 0 ; i < m ; i++) {
            int a, b, d;
            std::cin >> a >> b >> d;
            graph[a].push_back({b, d});
            graph[b].push_back({a, d});
            if( (a == g && b == h) || (a == h && b == g) ) {
                distance = d;
            }
        }
        // std::min(x -> g -> h -> s, x -> h -> g -> s)
        // == x -> s
        int x1 = dijstra(s, g, graph);
        int x2 = dijstra(s, h, graph);

        int near = x1;
        int nearx = g;
        int far = x2;
        int farx = h;
        if(x1 > x2) {
            // s -> h -> g -> x;
            near = x2;
            nearx = h;
            far = x1;
            farx = g;
        }
        else {
            // s -> g -> h -> x;
        }
        std::vector<int> answer;
        for(int i = 0 ; i < t ; i++) {
            int x;
            std::cin >> x;
            
            int shortest = dijstra(s, x, graph);
            int d1 = near;
            int d2 = distance;
            int d3 = dijstra(farx, x, graph);
            if(shortest == d1 + d2 + d3) {
                answer.push_back(x);
            }
        }
        std::sort(answer.begin(), answer.end());
        for(int i = 0 ; i < answer.size() ; i++) {
            std::cout << answer[i] << " ";
        }
        std::cout << "\n";
    }
}