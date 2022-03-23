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
#include <algorithm>

int findParent(int a, std::vector<int> &set) {
    if(a == set[a]) {
        return set[a];
    }

    return set[a] = findParent(set[a], set);
}

bool compare(std::vector<int> a, std::vector<int> b) {
    return a[2] < b[2];
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> array;
    for(int i = 0 ; i < m ; i++) {
        int u, v, c;
        std::cin >> u >> v >> c;
        array.push_back({u, v, c});
    }
    std::sort(array.begin(), array.end(), &compare);

    std::vector<int> set(n + 1, 0);
    for(int i = 0 ; i <= n ; i++) {
        set[i] = i;
    }

    int mst = 0;
    for(int i = 0 ; i < m ; i++) {
        int u = array[i][0];
        int v = array[i][1];
        int c = array[i][2];

        u = findParent(u, set);
        v = findParent(v, set);

        if(u != v) {
            if(u < v) {
                set[v] = u;
            }
            else {
                set[u] = v;
            }
            mst += c;
        }
    }

    std::cout << mst << "\n";
}