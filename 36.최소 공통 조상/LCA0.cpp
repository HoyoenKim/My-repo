#include <iostream>
#include <vector>

int n;
int LOG = 16;
void dfs(int current, int d, std::vector<std::vector<int>> &graph, std::vector<std::vector<int>> &parent, std::vector<int> &depth) {
    depth[current] = d;
    for(int i = 0 ; i < graph[current].size() ; i++) {
        int next = graph[current][i];
        parent[next][0] = current;
        dfs(next, d + 1, graph, parent, depth);
    }

}

void findParent(int root, std::vector<std::vector<int>> &graph, std::vector<std::vector<int>> &parent, std::vector<int> &depth) {
    dfs(root, 0, graph, parent, depth);
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

    int N;
    std::cin >> N;

    for(int i = 0 ; i < N ; i++) {
        std::cin >> n;
        std::vector<std::vector<int>> graph(n + 1);
        std::vector<int> findRoot(n + 1, 1);
        for(int j = 0 ; j < n - 1 ; j++) {
            int A, B;
            std::cin >> A >> B;
            findRoot[B] = 0;
            graph[A].push_back(B);
        }

        int A, B;
        std::cin >> A >> B;

        int root = 1;
        for(int j = 1 ; j <= n ; j++) {
            if(findRoot[j] == 1) {
                root = j;
                break;
            }
        }
        
        std::vector<std::vector<int>> parent(n + 1, std::vector<int>(LOG + 1, root));
        std::vector<int> depth(n + 1);
        
        findParent(root, graph, parent, depth);
        
        std::cout << findLCA(A, B, graph, parent, depth) << "\n";
    }
}