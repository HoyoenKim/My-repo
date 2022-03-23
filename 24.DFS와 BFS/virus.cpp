#include <iostream>
#include <vector>
#include <stack>

int main() {
    int n, m;
    std::cin >> n;
    std::cin >> m;
    std::vector<std::vector<int>> graph(n + 1);

    for(int i = 0 ; i < m ; i++) {
        int x, y;
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    std::vector<int> check(n, 0);
    std::stack<int> s;
    s.push(1);
    int count = 0;
    while(!s.empty()) {
        int current = s.top();
        s.pop();

        if(check[current] == 0) {
            check[current] = 1;
            //std::cout << current << "\n";
            count ++;
            for(int j = 0 ; j < graph[current].size() ; j++) {
                if(check[graph[current][j]] == 0) {
                    s.push(graph[current][j]);
                }
            }
        }
    }

    std::cout << count - 1<< "\n";
}