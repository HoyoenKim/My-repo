#include <iostream>
#include <vector>

int n;
int LOG = 17;
void dfs(int current, int d, std::vector<std::vector<int>> &graph, std::vector<std::vector<int>> &parent, std::vector<int> &depth, std::vector<int> &check) {
    depth[current] = d;
    check[current] = 1;
    for(int i = 0 ; i < graph[current].size() ; i++) {
        int next = graph[current][i];
        if(check[next] == 0) {
            parent[next][0] = current;
            dfs(next, d + 1, graph, parent, depth, check);
        }
    }

}

void findParent(int root, std::vector<std::vector<int>> &graph, std::vector<std::vector<int>> &parent, std::vector<int> &depth) {
    std::vector<int> check(n + 1, 0);
    dfs(root, 0, graph, parent, depth, check);
    for(int j = 1 ; j <= LOG; j++) {
        for(int i = 1 ; i <= n ; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int findLCA(int A, int B, std::vector<std::vector<int>> &graph, std::vector<std::vector<int>> &parent, std::vector<int> &depth) {
    if(depth[A] > depth[B]) {
        std::swap(A, B);
    }

    for(int i = LOG ; i >= 0 ; i--) {
        if(depth[B] >= depth[A] + (1 << i)) {
            B = parent[B][i];
        }
    }

    if(A == B) {
        return A;
    }
    else {
        for(int i = LOG ; i >= 0 ; i--) {
            if(parent[A][i] != parent[B][i]) {
                A = parent[A][i];
                B = parent[B][i];
            }
        }
    }
    return parent[A][0];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n;
    std::vector<std::vector<int>> graph(n + 1);
    for(int j = 0 ; j < n - 1 ; j++) {
        int A, B;
        std::cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    int root = 1;
        
    std::vector<std::vector<int>> parent(n + 1, std::vector<int>(LOG + 1, root));
    std::vector<int> depth(n + 1);
        
    findParent(root, graph, parent, depth);

    int m;
    std::cin >> m;
    for(int i = 0 ; i < m ; i++) {
        int A, B;
        std::cin >> A >> B;
        std::cout << findLCA(A, B, graph, parent, depth) << "\n";
    }    
        

}