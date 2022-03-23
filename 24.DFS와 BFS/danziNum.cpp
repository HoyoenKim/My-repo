#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

struct compare {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> array(n, std::vector<int>(n, 0));
    for(int i = 0 ; i < n ; i++) {
        std::string inputStr;
        std::cin >> inputStr;

        for(int j = 0 ; j < n ; j++) {
            array[i][j] = inputStr[j] - '0';
        }
    }

    std::vector<std::vector<int>> graph(n*n);
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            //std::cout << array[i][j] << " ";
            int current = i * n + j;
            if(array[i][j] == 1) {
                if(i != 0 && array[i - 1][j] == 1) {
                    int next = (i - 1) * n + j;
                    graph[current].push_back(next);
                    graph[next].push_back(current);
                } 
                
                if(i != n - 1 && array[i + 1][j] == 1) {
                    int next = (i + 1) * n + j;
                    graph[current].push_back(next);
                    graph[next].push_back(current);
                }
                
                if(j != 0 && array[i][j - 1] == 1) {
                    int next = i * n + j - 1;
                    graph[current].push_back(next);
                    graph[next].push_back(current);
                }
                
                if(j != n -1 && array[i][j + 1] == 1) {
                    int next = i * n + j + 1;
                    graph[current].push_back(next);
                    graph[next].push_back(current);
                }
            }
        }
        //std::cout << "\n";
    }

    std::vector<int> check(n*n, 0);
    int numberOfDanzi = 0;
    std::priority_queue<int, std::vector<int>, compare> numberOfHome;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(array[i][j] == 1) {
                std::stack<int> s;
                s.push(i * n + j);
                int count = 0;
                while(!s.empty()) {
                    int current = s.top();
                    s.pop();

                    if(check[current] == 0) {
                        check[current] = 1;
                        count++;
                        for(int k = 0 ; k < graph[current].size() ; k++) {
                            int next = graph[current][k];
                            if(check[next] == 0) {
                                s.push(next);
                            }
                        }
                    }
                }

                if(count > 0) {
                    numberOfDanzi++;
                    numberOfHome.push(count);
                }
            }
        }
    }
    std::cout << numberOfDanzi << "\n";
    while(!numberOfHome.empty()) {
        std::cout << numberOfHome.top() << "\n";
        numberOfHome.pop();
    }
}