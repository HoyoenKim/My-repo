#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> it(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> sumMax(n, std::vector<int>(n, 0));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j <= i ; j++) {
            std::cin >> it[i][j];
        }
    }

    sumMax[0][0] = it[0][0];
    for(int i = 1 ; i < n ; i++) {
        for(int j = 0 ; j <= i ; j++) {
            if(j == 0) {
                sumMax[i][j] = sumMax[i - 1][j] + it[i][j];
            }
            else if(j == i) {
                sumMax[i][j] = sumMax[i - 1][j - 1] + it[i][j];
            }
            else {
                sumMax[i][j] = std::max(sumMax[i - 1][j - 1], sumMax[i - 1][j]) + it[i][j];
            }
        }
    }

    int max = 0;
    for(int j = 0 ; j < n ; j++) {
        if(max < sumMax[n - 1][j]) {
            max = sumMax[n - 1][j];
        }
    }
    std::cout << max << "\n";
}