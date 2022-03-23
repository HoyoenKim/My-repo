#include <iostream>
#include <vector>
#include <queue>

struct compare{
    bool operator() (std::vector<int> a, std::vector<int> b) {
        return a[1] > b[1];
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    int start;
    std::cin >> start;

    std::vector<std::vector<std::vector<int>>> graph(n + 1);

    for(int i = 0 ; i < m ; i++) {
        int x, y, value;
        std::cin >> x >> y >> value;
        graph[x].push_back({y, value});
    }

    int INF = 3000001;
    std::vector<int> check(n + 1, 0);
    std::vector<int> d(n + 1, INF);
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, compare> q;
    d[start] = 0;
    q.push({start, d[start]});

    while(!q.empty()) {
        int current = q.top()[0];
        q.pop();
        check[current] = 1;

        for(int i = 0 ; i < graph[current].size() ; i++) {
            int next = graph[current][i][0];
            int value = graph[current][i][1];

            int candid = d[current] + value;
            if(check[next] == 0 && candid < d[next]) {
                d[next] = candid;
                q.push({next, d[next]});
            }
        }
    }
    
    for(int i = 1 ; i <= n ; i++) {
        if(d[i] == INF) {
            std::cout << "INF\n";
        }
        else {
            std::cout << d[i] << "\n";
        }
    }
}