#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m;
    std::cin >> m >> n;

    std::vector<std::vector<int>> array(n, std::vector<int>(m, 0));
    std::queue<std::vector<int>> q;

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            std::cin >> array[i][j];
            if(array[i][j] == 1) {
                q.push({i, j, 1});
            }
        }
    }

    while(!q.empty()) {
        int currentX = q.front()[0];
        int currentY = q.front()[1];
        int day = q.front()[2];

        q.pop();
        if(currentX != 0 && array[currentX - 1][currentY] == 0) {
            array[currentX - 1][currentY] = day + 1;
            q.push({currentX - 1, currentY, day + 1});
        }

        if(currentX != n - 1 && array[currentX + 1][currentY] == 0) {
            array[currentX + 1][currentY] = day  + 1;
            q.push({currentX + 1, currentY, day + 1});
        }

        if(currentY != 0 && array[currentX][currentY - 1] == 0) {
            array[currentX][currentY - 1] = day + 1;
            q.push({currentX, currentY - 1, day + 1});
        }

        if(currentY != m - 1 && array[currentX][currentY + 1] == 0) {
            array[currentX][currentY + 1] = day + 1;
            q.push({currentX, currentY + 1, day + 1});
        }
    }

    int max = 1;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(array[i][j] == 0) {
                max = 0;
                break;
            }
            else if(array[i][j] > 0){
                if(array[i][j] > max) {
                    max = array[i][j];
                }
            }
        }
        if(max == 0) {
            break;
        }
    }

    std::cout << max - 1 << "\n";
}