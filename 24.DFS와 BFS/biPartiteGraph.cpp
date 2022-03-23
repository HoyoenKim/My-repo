#include <iostream>
#include <vector>
#include <stack>
#include <queue>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    
    int N;
    std::cin >> N;
    for(int i = 0 ; i < N ; i++) {
        int v, e;
        std::cin >> v >> e;
        std::vector<std::vector<int>> graph(v + 1);

        for(int j = 0 ; j < e ; j++) {
            int x, y;
            std::cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x); 
        }
        std::vector<int> check(v + 1, 0); // 0 not check, 1 red, 2 blue 
        
        // Use DFS
        for(int p = 1 ; p <= v ; p++) {
            if(check[p] == 0) {
                std::stack<std::vector<int>> s;
                s.push({p, 1});
                while(!s.empty()) {
                    int current = s.top()[0];
                    int color = s.top()[1];
                    s.pop();
                    if(check[current] == 0) {
                        check[current] = color;
                        for(int j = 0 ; j < graph[current].size() ; j++) {
                            int next = graph[current][j];
                            if(check[next] == 0) {
                                if(color == 1) {
                                    s.push({next, 2});
                                }
                                else {
                                    s.push({next, 1});
                                }
                            }   
                        }
                    }
                }
            }
        }

        /*
        // Use BFS
        for(int p = 1 ; p <= v ; p++) {
            if(check[p] == 0) {
                std::queue<std::vector<int>> q;
                q.push({p, 1});
                check[p] = 1;
                while(!q.empty()) {
                    int current = q.front()[0];
                    int color = q.front()[1];
                    q.pop();
                    for(int j = 0 ; j < graph[current].size() ; j++) {
                        int next = graph[current][j];
                        if(check[next] == 0) {
                            if(color == 1) {
                                q.push({next, 2});
                                check[next] = 2;
                            }
                            else if(color == 2) {
                                q.push({next, 1});
                                check[next] = 1;
                            }
                        }
                    }
                }
            }
        }*/

        int isBiPartiteGraph = 1;
        for(int i = 1 ; i <= v ; i++) {
            for(int j = 0 ; j < graph[i].size() ; j++) {
                if(check[i] == check[graph[i][j]]) {
                    isBiPartiteGraph = 0;
                    break;
                }
            }
            if(!isBiPartiteGraph) {
                break;
            }
        }
        if(isBiPartiteGraph) {
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
        }
    }
}