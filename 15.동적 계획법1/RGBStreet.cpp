#include <iostream>
#include <vector>


int n;
std::vector<std::vector<int>> color(1000, std::vector<int>(3, 0));

int minCost = -1;
void findColor (int i, int beforeColor, int cost) {
    if(i >= n) {
        if(i == n) {
            if(beforeColor == 0) {
                cost += std::min(color[i - 1][1], color[i - 1][2]);
            }
            else if(beforeColor == 1) {
                cost += std::min(color[i - 1][0], color[i - 1][2]);
            }
            else if(beforeColor == 2) {
                cost += std::min(color[i - 1][0], color[i - 1][1]);
            }
        }

        if(minCost == -1) {
            minCost = cost;
        }
        else{
            if(cost < minCost) {
                minCost = cost;
            }
        }
    }
    else {
        for(int j = 0 ; j < 3 ; j++) {
            int moreCost;
            if(j == beforeColor) {
                if(j == 0) {
                    moreCost = color[i][j] + std::min(color[i - 1][1], color[i - 1][2]);
                }
                else if(j == 1) {
                    moreCost = color[i][j] + std::min(color[i - 1][0], color[i - 1][2]);
                }
                else if(j == 2) {
                    moreCost = color[i][j] + std::min(color[i - 1][0], color[i - 1][1]);
                }
                 
            }
            else {
                moreCost = color[i][j] + color[i - 1][3 - j - beforeColor]; 
            }
            findColor(i + 2, j, cost + moreCost);
        }
    }
}
int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> n;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < 3 ; j++) {
            std::cin >> color[i][j];
        }
    }

    std::vector<std::vector<int>> cost(1000, std::vector<int>(3, 0));
    for(int i = 0 ; i < n ; i++) {
        if(i == 0) {
            cost[i][0] = color[i][0];
            cost[i][1] = color[i][1];
            cost[i][2] = color[i][2];
        }
        else {
            cost[i][0] = std::min(cost[i - 1][1], cost[i - 1][2]) + color[i][0];
            cost[i][1] = std::min(cost[i - 1][0], cost[i - 1][2]) + color[i][1];
            cost[i][2] = std::min(cost[i - 1][0], cost[i - 1][1]) + color[i][2];
        }
    }
    
    int min = cost[n - 1][0];
    if(cost[n - 1][1] < min) {
        min = cost[n - 1][1];
    }
    if(cost[n - 1][2] < min) {
        min = cost[n - 1][2];
    }

    std::cout << min << "\n";
}