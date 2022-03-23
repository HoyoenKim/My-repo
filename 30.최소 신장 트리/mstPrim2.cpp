/*
Spanning Tree
그래프에서 모든 정점을 연결하고 최소의 간선을 가지는 그래프의 최서 연결 부분 그래프
간선의 개수 = n - 1 개

Minimum Spanning Tree
Spanning Tree 중 간선의 합이 최소가 되는 spanning tree

구현 idea
0) 간선의 합이 최소
1) n개의 정점을 잇는 n - 1 개의 간선을 사용
2) cycle이 없음

1. Kruskal MST
탐욕적인 방법을 이용하여 네트워크의 모든 정점을 최소 비용으로 연결하는 최적 해답을 구하는 것

1) 그래프의 간선들을 가중치로 정렬
2) 정렬된 리스트에서 낮은 가중치를 먼저 선택 한 뒤 cycle이 생기면 제외 (union find를 이용)

2. Prim KST
시작 정점부터 출발해 mst 집합을 확장하는 방법

1) 시작 정점이 mst에 포함
2) mst에 인접한 정점들 중 최소 간선으로 연결된 정점을 선택하고 낮은 가중치를 먼저 선택한다.
3) n - 1 개의 간선을 가질 떄 까지 반복

Kruskal의 경우 eloge, prim의 경우 n^2 이므로
그래프에 간선이 많은 dense graph의 경우 prim을
그래프에 간선이 적은 sparse graph의 경우 kruskal을 이용한다.
*/

#include <iostream>
#include <vector>
#include <queue>

struct compare {
    bool operator() (std::vector<int> a, std::vector<int> b) {
        return a[1] > b[1];
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::vector<int>>> graph(n + 1);
    for(int i = 0 ; i < m ; i++) {
        int u, v, c;
        std::cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }

    int INF = INT32_MAX;
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, compare> dist; // T에 들어간 노드와 i 노드 사이의 간선 가중치 중 최소값
    std::vector<int> selected(n + 1, 0); // 노드가 T에 들어가 있으면 true 아니면 false
    
    int mst = 0;
    int min_dist = INF;
    dist.push({1, 0});
    for(int i = 1 ; i <= n ; i++) {
        int now = -1, min_dist = INF;
        while(!dist.empty()) {
            now = dist.top()[0];
            if(selected[now] == 0) {
                min_dist = dist.top()[1];
                break;
            }
            dist.pop();
        }
        if(min_dist == INF) {
            continue;
        }
        mst += min_dist;
        selected[now] = 1;
        for(int j = 0 ; j < graph[now].size() ; j++) {
            dist.push({graph[now][j][0], graph[now][j][1]});
        }
    }

    std::cout << mst << "\n";
}