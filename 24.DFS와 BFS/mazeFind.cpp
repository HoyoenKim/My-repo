#include <iostream>
#include <string>
#include <vector>
#include <queue>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> array(n, std::vector<int>(m, 0));
    for(int i = 0 ; i < n ; i++) {
        std::string inputStr;
        std::cin >> inputStr;
        for(int j = 0 ; j < m; j++) {
            array[i][j] = inputStr[j] - '0';
        }
    }
    
    std::vector<std::vector<int>> graph(n * m);
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            //std::cout << array[i][j] << " ";
            if(array[i][j] == 1) { 
                int current = i * m + j;
                if(i != 0 && array[i - 1][j] == 1) {
                    int next = (i - 1) * m + j;
                    graph[current].push_back(next);
                    graph[next].push_back(current);
                }

                if(i != n - 1 && array[i + 1][j] == 1) {
                    int next = (i + 1) * m + j;
                    graph[current].push_back(next);
                    graph[next].push_back(current);
                }

                if(j != 0 && array[i][j - 1]) {
                    int next = i * m + j - 1;
                    graph[current].push_back(next);
                    graph[next].push_back(current);
                }

                if(j != m - 1 && array[i][j + 1]) {
                    int next = i * m + j + 1;
                    graph[current].push_back(next);
                    graph[next].push_back(current);
                }
            }
        }
        //std::cout << "\n";
    }

    std::queue<std::vector<int>> q;
    q.push({0, 0});

    int count = 0;
    int distation = n * m - 1;
    std::vector<int> check(n * m, 0);
    while(!q.empty()) {
        int current = q.front()[0];
        int depth = q.front()[1];
        q.pop();

        //std::cout << current << " " << depth << "\n";
        if(current == distation) {
            std::cout << depth + 1 << "\n";
            break;
        }
        

        if(check[current] == 0) {
            check[current] = 1;
            for(int i = 0 ; i < graph[current].size() ; i++) {
                int next = graph[current][i];
                if(check[next] == 0) {
                    q.push({next, depth + 1});
                }
            }
        }
    }
}