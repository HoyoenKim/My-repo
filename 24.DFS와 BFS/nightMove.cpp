#include <iostream>
#include <vector>
#include <queue>

int main() {
    int N;
    std::cin >> N;

    for(int i = 0 ; i < N ; i++) {
        int n;
        std::cin >> n;
        int startX, startY;
        std::cin >> startX >> startY;

        int endX, endY;
        std::cin >> endX >> endY;

        std::vector<std::vector<int>> check(n, std::vector<int>(n, 0));
        std::queue<std::vector<int>> q;
        q.push({startX, startY, 0});

        int answer = 0;
        while(!q.empty()) {        
            int x = q.front()[0];
            int y = q.front()[1];
            int count = q.front()[2];
            q.pop();

            if(x == endX && y == endY) {
                answer = count;
                break;
            }

            if(check[x][y] == 1) {
                continue;
            }
            
            check[x][y] = 1;
            if(x - 2 >= 0 && y - 1 >= 0 && check[x - 2][y - 1] == 0) {
                q.push({x - 2, y - 1, count + 1});
            }

            if(x - 2 >= 0 && y + 1 <= n - 1 && check[x - 2][y + 1] == 0) {
                q.push({x - 2, y + 1, count + 1});
            }

            if(x - 1 >= 0 && y - 2 >= 0 && check[x - 1][y - 2] == 0) {
                q.push({x - 1, y - 2, count + 1});
            }

            if(x - 1 >= 0 && y + 2 <= n - 1 && check[x - 1][y + 2] == 0) {
                q.push({x - 1, y + 2, count + 1});
            }

            if(x + 2 <= n - 1 &&  y - 1 >= 0 && check[x + 2][y - 1] == 0) {
                q.push({x + 2, y - 1, count + 1});
            }

             if(x + 2 <= n - 1 &&  y + 1 <= n - 1 && check[x + 2][y + 1] == 0) {
                q.push({x + 2, y + 1, count + 1});
            }

            if(x + 1 <= n - 1 && y - 2 >= 0 && check[x + 1][y - 2] == 0) {
                q.push({x + 1, y - 2, count + 1});
            }

            if(x + 1 <= n - 1 && y + 2 <= n - 1 && check[x + 1][y + 2] == 0) {
                q.push({x + 1, y + 2, count + 1});
            }
        }

        std::cout << answer << "\n";
    }
}