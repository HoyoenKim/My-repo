#include <iostream>
#include <vector>
#include <stack>

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;
    for(int i = 0 ; i < N ; i++) {
        int m, n, num;
        std::cin >> m >> n >> num;
        //std::cout << n << m << num;
        std::vector<std::vector<int>> array(m, std::vector<int>(n, 0));

        for(int j = 0 ; j < num ; j++) {
            int x, y;
            std::cin >> x >> y;
            array[x][y] = 1;
        }
        std::vector<std::vector<int>> graph(m * n);
        for(int h = 0 ; h < n ; h++) {
            for(int w = 0 ; w < m ; w++) {
                //std::cout << array[w][h] << " ";
                if(array[w][h] == 1) {
                    int current = w * n + h;                
                    if(h != 0 && array[w][h - 1] == 1) {
                        int next = w * n + (h - 1);
                        graph[current].push_back(next);
                        graph[next].push_back(current);
                    }
                    
                    if(h != n - 1 && array[w][h + 1] == 1) {
                        int next = w * n + h + 1;
                        graph[current].push_back(next);
                        graph[next].push_back(current);
                    
                    }
    
                    if(w != 0 && array[w - 1][h] == 1) {
                        int next = (w - 1) * n + h;
                        graph[current].push_back(next);
                        graph[next].push_back(current);
                    }
    
                    if(w != m - 1 && array[w + 1][h] == 1) {
                        int next = (w + 1) * n + h;
                        graph[current].push_back(next);
                        graph[next].push_back(current);
                    }
                }
            }
            //std::cout << "\n";
        }

        std::vector<int> check(n * m, 0);
        int count = 0;
        for(int h = 0 ; h < n ; h++) {
            for(int w = 0 ; w < m ; w++) {
                if(array[w][h] == 1) {
                    std::stack<int> s;
                    s.push(w * n + h);

                    int isNew = 0;
                    while(!s.empty()) {
                        int current = s.top();
                        s.pop();

                        if(check[current] == 0) {
                            check[current] = 1;
                            isNew = 1;
                            for(int k = 0 ; k < graph[current].size() ; k++) {
                                int next = graph[current][k];
                                if(check[next] == 0) {
                                    s.push(next);
                                }
                            }
                        }
                    }

                    if(isNew) {
                        count++;
                    }
                }
            }
        }
        std::cout << count << "\n";
    }
}