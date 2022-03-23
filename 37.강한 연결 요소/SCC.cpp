#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<std::vector<int>> scc;
int id = 0;

std::stack<int> s;
int dfs(int current, std::vector<std::vector<int>> &graph, std::vector<int> &uniqueNum, std::vector<int> &check) {
    id += 1;
    uniqueNum[current] = id;
    s.push(current);

    int parent = uniqueNum[current];
    for(int i = 0 ; i < graph[current].size() ; i++) {
        int next = graph[current][i];
        if(uniqueNum[next] == 0) {
            parent = std::min(parent, dfs(next, graph, uniqueNum, check));
        }
        else if(check[next] == 0) {
            parent = std::min(parent, uniqueNum[next]);
        }
    }

    if(parent == uniqueNum[current]) {
        std::vector<int> sccComponent;
        while(1) {
            int t = s.top();
            s.pop();
            sccComponent.push_back(t);
            check[t] = 1;
            if(t == current) {
                break;
            }
        }
        scc.push_back(sccComponent);
    }

    return parent;
}
bool compare(std::vector<int> a, std::vector<int> b) {
    return a[0] < b[0];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n + 1);

    for(int i = 0 ; i < m ; i++) {
        int x, y;
        std::cin >> x >> y;
        graph[x].push_back(y);
    }

    std::vector<int> uniqueNum(n + 1, 0);
    std::vector<int> check(n + 1, 0);
    
    for(int i = 1 ; i <= n ; i++) {
        if(uniqueNum[i] == 0) {
            dfs(i, graph, uniqueNum, check);
        }
    }

    for(int i = 0 ; i < scc.size() ; i++){
        std::sort(scc[i].begin(), scc[i].end());
    }

    std::sort(scc.begin(), scc.end(), compare);

    std::cout << scc.size() << "\n";
    for(int i = 0 ; i < scc.size() ; i++){
        std::sort(scc[i].begin(), scc[i].end());
        for(int j = 0 ; j < scc[i].size() ; j++){
            std::cout << scc[i][j] << " ";
        }
        std::cout << "-1\n"; 
    }
}