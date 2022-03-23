#include <iostream>
#include <vector>
#include <queue>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> array(n, std::vector<int>(m, 0));

    for(int i = 0 ; i < n ; i++) {
        std::string inputStr;
        std::cin >> inputStr;
        for(int j = 0 ; j < m ; j++) {
            array[i][j] = inputStr[j] - '0';
            //std::cout << array[i][j] << " ";
        }
        //std::cout << "\n";
    }

    std::queue<std::vector<int>> q;
    q.push({0, 0, 0, 1});

    std::vector<std::vector<std::vector<int>>> check(n, std::vector<std::vector<int>>(m, std::vector<int>(2, 0)));
    std::vector<int> deltaX = {1, -1, 0, 0};
    std::vector<int> deltaY = {0, 0, 1, -1};
    
    int answer = -1;
    while(!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int opp = q.front()[2];
        int count = q.front()[3];
        q.pop();

        if(x == n - 1 && y == m - 1) {
            answer = count;
            break;
        }

        for(int i = 0 ; i < 4 ; i++) {
            int nextX = x + deltaX[i];
            int nextY = y + deltaY[i];

            if(nextX >= 0 && nextX <= n - 1 && nextY >= 0 && nextY <= m - 1) {
                if(array[nextX][nextY] == 1 && opp == 0) {
                    check[nextX][nextY][opp + 1] = 1;
                    q.push({nextX, nextY, opp + 1, count + 1});
                }
                else if(array[nextX][nextY] == 0 && check[nextX][nextY][opp] == 0) {
                    check[nextX][nextY][opp] = 1;
                    q.push({nextX, nextY, opp, count + 1});
                }
            }
        }


    }
    std::cout << answer << "\n";
}