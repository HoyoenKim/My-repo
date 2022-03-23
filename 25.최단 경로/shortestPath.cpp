#include <iostream>
#include <vector>
#include <queue>

int INF = 3000001;
int n, m;
std::vector<std::vector<int>> graph(20001, std::vector<int>(20001, INF));
std::vector<int> check(20001, 0);
std::vector<int> d(20001, INF);

int getMinIndex() {
    int min = INF;
    int minIndex = 0;
    for(int i = 1 ; i <= n ; i++) {
        if(d[i] < min && check[i] == 0) {
            min = d[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstraN2(int start) {
    
    for(int i = 1 ; i <= n ; i++) {
        d[i] = graph[start][i];
    }
    d[start] = 0;
    check[start] = 1;

    for(int i = 0 ; i < n - 2 ; i++) {
        int current = getMinIndex();
        check[current] = 1;

        for(int j = 1 ; j <= n ; j++) {
            if(check[j] == 0) {
                int cand = d[current] + graph[current][j];
                if(cand < d[j]) {
                    d[j] = cand;
                }
            }
        }
    }
}

struct compare {
    bool operator() (std::vector<int> a, std::vector<int> b) {
        return a[1] > b[1];
    }
};

void dijkstraNlogN(int start) {
    // 출발 노드로부터 다른 노드로까지의 최단 거리를 구할 때 이용.
    // 시작점부터 갈 수 있는 곳의 거리를 구해 d를 갱신힌다.
    // 다음 이동은 방문하지 않았고 d가 가장 짧은 곳.
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, compare> q;

    d[start] = 0;
    check[start] = 1;
    q.push({start, 0});

    while(!q.empty()) {
        int current = q.top()[0];
        int dist = q.top()[1];
        q.pop();

        for(int i = 1 ; i < n ; i++) {
            if(check[i] == 0) {
                int cand = d[current] + graph[current][i];
                if(cand < d[i]) {
                    d[i] = cand;
                    q.push({i, d[i]});
                }  
            }
        }
    }
}

int main() {
    std::cin >> n >> m;

    int start;
    std::cin >> start;
    for(int i = 0 ; i < m ; i++) {
        int x, y, value;
        std::cin >> x >> y >> value;
        graph[x][y] = std::min(graph[x][y], value);
    }

    dijkstraNlogN(start);

    for(int i = 1 ; i <= n ; i++) {
        if(d[i] == INF) {
            std::cout << "INF\n";
        }
        else {
            std::cout << d[i] << "\n";
        }
    }
}