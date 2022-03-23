#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m, l;
    std::cin >> m >> n >> l;

    std::vector<std::vector<std::vector<int>>> array(n, std::vector<std::vector<int>>(m, std::vector<int>(l, 0)));
    std::queue<std::vector<int>> q;

    for(int k = 0; k < l ; k++) {
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                std::cin >> array[i][j][k];
                if(array[i][j][k] == 1) {
                    q.push({i, j, k, 1});
                }
            }
        }
    }
    

    while(!q.empty()) {
        int currentX = q.front()[0];
        int currentY = q.front()[1];
        int currentZ = q.front()[2];
        int day = q.front()[3];

        q.pop();
        if(currentX != 0 && array[currentX - 1][currentY][currentZ] == 0) {
            array[currentX - 1][currentY][currentZ] = day + 1;
            q.push({currentX - 1, currentY, currentZ, day + 1});
        }

        if(currentX != n - 1 && array[currentX + 1][currentY][currentZ] == 0) {
            array[currentX + 1][currentY][currentZ] = day  + 1;
            q.push({currentX + 1, currentY, currentZ, day + 1});
        }

        if(currentY != 0 && array[currentX][currentY - 1][currentZ] == 0) {
            array[currentX][currentY - 1][currentZ] = day + 1;
            q.push({currentX, currentY - 1, currentZ, day + 1});
        }

        if(currentY != m - 1 && array[currentX][currentY + 1][currentZ] == 0) {
            array[currentX][currentY + 1][currentZ] = day + 1;
            q.push({currentX, currentY + 1, currentZ, day + 1});
        }

        if(currentZ != 0 && array[currentX][currentY][currentZ - 1] == 0) {
            array[currentX][currentY][currentZ - 1] = day + 1;
            q.push({currentX, currentY, currentZ - 1, day + 1});
        }

        if(currentZ != l - 1 && array[currentX][currentY][currentZ + 1] == 0) {
            array[currentX][currentY][currentZ + 1] = day + 1;
            q.push({currentX, currentY, currentZ + 1, day + 1});
        }
    }

    int max = 1;
    for(int k = 0 ; k < l ; k++) {
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(array[i][j][k] == 0) {
                    max = 0;
                    break;
                }
                else if(array[i][j][k] > 0){
                    if(array[i][j][k] > max) {
                        max = array[i][j][k];
                    }
                }
            }
            if(max == 0) {
                break;
            }
        }
        if(max == 0) {
            break;
        }
    }
    

    std::cout << max - 1 << "\n";
}