#include <iostream>
#include <vector>
#include <queue>

struct compare {
    bool operator() (std::vector<int> a, std::vector<int> b) {
        return a[1] > b[1];
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::vector<int>>> graph(n + 1);
    for(int i = 0 ; i < m ; i++) {
        int u, v, value;
        std::cin >> u >> v >> value;
        graph[u].push_back({v, value});
    }
    int start, end;
    std::cin >> start >> end;

    int INF = 100000001;
    std::vector<int> d(n + 1, INF);
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, compare> q;
    d[start] = 0;
    q.push({start, d[start]});

    std::vector<int> path(n + 1, 0);
    for(int i = 0 ; i <= n ; i++) {
        path[i] = i;
    }

    while(!q.empty()) {
        int current = q.top()[0];
        int currentValue = q.top()[1];
        q.pop();
        if(current == end) {
            break;
        }
         if(d[current] < currentValue) {
            continue;
        }

        for(int i = 0 ; i < graph[current].size() ; i++) {
            int next = graph[current][i][0];
            int nextValue = graph[current][i][1] + d[current];

            if(nextValue < d[next]) {
                path[next] = current;
                d[next] = nextValue;
                q.push({next, d[next]});
            } 
        }
    }

    std::cout << d[end] << "\n";

    int current = end;
    std::vector<int> answer;
    answer.push_back(current);
    while(1) {
        current = path[current];
        answer.push_back(current);
        if(current == start) {
            break;
        } 
    }

    std::cout << answer.size() << "\n";
    for(int i = answer.size() - 1 ; i >= 0 ; i--) {
        std::cout << answer[i] << " ";
    }
    std::cout << "\n";
}