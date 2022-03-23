#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

std::vector<int> dfsVisit;
std::vector<int> bfsVisit;

std::vector<int> checkDfs1(1001, 0);
void dfs1(std::vector<std::vector<int>> graph, int v) {
    // 루트 노드에서 시작해서 다음 분기로 넘어가기 전에 해당 분기를 완벽하게 탐색
    // 루트 노드는 depth 0, 루트 노드에서 n번에 갈 수 있는 노드는 depth n이다.

    // depth 1a -> 2a -> 3a -> 4a ... / 1a -> 2b -> ... / 1b -> 2c -> 3 -> 4 ...
    // 모든 노드를 방문하고자 하는 경우 사용한다.
    // 재귀 이용
    if(checkDfs1[v] == 0){
        dfsVisit.push_back(v);
        checkDfs1[v] = 1;
        for(int j = 0 ; j < graph[v].size() ; j++) {
            int next = graph[v][j];
            if(checkDfs1[next] == 0) {
                dfs1(graph, next);
            }
        }
    }
}

std::vector<int> checkDfs2(1001, 0);
std::stack<int> dfsStack;
void dfs2(std::vector<std::vector<int>> graph, int v) {
    // 스택 이용
    dfsStack.push(v);
    while(!dfsStack.empty()) {
        int current = dfsStack.top();
        dfsStack.pop();
        if(checkDfs2[current] == 0) {
            dfsVisit.push_back(current);
            checkDfs2[current] = 1;
            for(int j = graph[current].size() - 1 ; j >= 0 ; j--) {
                int next = graph[current][j];
                //std::cout << "current : " << current << " next : " << next << "\n";
                if(checkDfs2[next] == 0) {
                    dfsStack.push(next);
                }
            }
        }
    }
}

std::vector<int> checkBfs(1001, 0);
std::queue<int> bfsQueue;
void bfs(std::vector<std::vector<int>> graph, int v) {
    // 루트 노드에서 시작해서 인접한 노드를 탐색
    // 루트 노드는 depth 0, 루트 노드에서 n 번에 갈 수 있는 노드는 depth n이다.

    // dept 1 all -> 2 all -> 3 all -> 4 all -> ...
    // 두 노드 사이의 최단 경로 or 임의의 경로를 찾을 때 사용한다. Prim, Dijkstra 와 유사
    // 큐 이용
    bfsQueue.push(v);
    checkBfs[v] = 1;
    while(!bfsQueue.empty()) {
        int current = bfsQueue.front();
        bfsQueue.pop();
        bfsVisit.push_back(current);
        for(int j = 0 ; j < graph[current].size() ; j++) {
            int next = graph[current][j];
            if(checkBfs[next] == 0) {
                bfsQueue.push(next);
                checkBfs[next] = 1;
            }
        }
    }

}

int main() {
    int n, m, v;
    std::cin >> n >> m >> v;

    std::vector<std::vector<int>> graph(n + 1);

    for(int i = 0 ; i < m ; i++) {
        int x, y;
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i = 1 ; i <= n ; i++) {
        std::sort(graph[i].begin(), graph[i].end());
        /*std::cout << i << " : ";
        for(int j = 0 ; j < graph[i].size() ; j++) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << "\n";*/
    }
    //dfs1(graph, v);
    dfs2(graph, v);
    bfs(graph, v);

    for(int i = 0 ; i < dfsVisit.size() ; i++) {
        std::cout << dfsVisit[i] << " ";
    }
    std::cout << "\n";

    for(int i = 0 ; i < bfsVisit.size() ; i++) {
        std::cout << bfsVisit[i] << " ";
    }
    std::cout << "\n";
}