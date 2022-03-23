#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int num  = 1;
    while(1) {
        int n, m;
        std::cin >> n >> m;
        if(n == 0 && m == 0) {
            break;
        }

        std::vector<std::vector<int>> graph(n + 1);
        for(int i = 0 ; i < m ; i++) {
            int x, y;
            std::cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        int count = 0;
        std::vector<int> check(n + 1, 0);
        for(int i = 1 ; i <= n ; i++) {
            if(check[i] == 0) {
                int isTree = 1;
                std::queue<std::vector<int>> q;
                q.push({i, 0});
                check[i] = 1;
                while(!q.empty()) {
                    int current = q.front()[0];
                    int parent = q.front()[1];
                    q.pop();

                    for(int j = 0 ; j < graph[current].size() ; j++) {
                        int next = graph[current][j];
                        if(check[next] == 0 && next != parent) {
                            check[next] = 1;
                            q.push({next, current});
                        }
                        else {
                            if(next != parent) {
                                isTree = 0;
                                break;
                            }
                        }
                    }    
                }
                if(isTree) {
                    count += 1;
                }
            }
        }

        std::cout << "Case " << num << ": "; 
        if(count > 1) {
            std::cout << "A forest of " << count << " trees.\n"; 
        }
        else if(count == 1) {
            std::cout << "There is one tree.\n";
        }
        else if(count == 0) {
            std::cout << "No trees.\n";
        }
        num += 1;
    }
}