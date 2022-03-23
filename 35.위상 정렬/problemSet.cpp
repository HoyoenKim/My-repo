#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct compare {
    bool operator() (int a, int b) {
        return a > b;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n + 1);
    std::vector<int> inDegree(n + 1, 0);
    for(int i = 0 ; i < m ; i++) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        inDegree[v] += 1;
    }

    std::priority_queue<int, std::vector<int>, compare> pq;
    for(int i = 1 ; i <= n ; i++) {
        if(inDegree[i] == 0) {
            pq.push(i);
        } 
    }

    while(!pq.empty()) {
        int current = pq.top();
        pq.pop();
        std::cout << current << " ";
        for(int i = 0 ; i < graph[current].size() ; i++) {
            int nxt = graph[current][i];
            inDegree[nxt] -= 1;
            if(inDegree[nxt] == 0) {
                pq.push(nxt);
            }
        }
    }
    std::cout << "\n";
}