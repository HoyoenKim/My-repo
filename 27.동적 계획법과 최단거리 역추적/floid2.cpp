#include <iostream>
#include <vector>
std::vector<int> answer;

void findPath(int from, int to, std::vector<std::vector<int>> &path) {
    int prev = path[from][to];
    if(from == prev) {
        answer.push_back(from);
        return;
    }

    findPath(from, prev, path);
    findPath(prev, to, path);
}

int main() {
    int n, m;
    std::cin >> n >> m;

    int INF = 10000001;
    std::vector<std::vector<int>> dist(n + 1, std::vector<int>(n + 1, INF));
    for(int i = 0 ; i < m ; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        dist[a][b] = std::min(dist[a][b], c);
    }

    std::vector<std::vector<int>> path(n + 1, std::vector<int>(n + 1 , 0));
    for(int i = 0 ; i <= n ; i++) {
        for(int j = 0 ; j <= n ; j++) {
            path[i][j] = i;
        }
    }

    for(int k = 1 ; k <= n ; k++) {
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= n ; j++) {
                if(i == j) {
                    dist[i][j] = 0;
                }
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
            }
        }
    }

    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            if(dist[i][j] == INF) {
                std::cout << "0 ";
            }
            else {
                std::cout << dist[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            if(dist[i][j] == INF || i == j) {
                std::cout << "0";
            }
            else {
                answer.clear();           
                findPath(i, j, path);
                answer.push_back(j); 
                std::cout << answer.size() << " ";
                for(int k = 0 ; k < answer.size() ; k++) {
                    std::cout << answer[k] << " ";
                }
            }
            std::cout << "\n";
        }
    }
}