#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::vector<int> a, std::vector<int> b) {
    return a[0] < b[0];
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> array(n, std::vector<int>(2)); //weight, value
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i][0] >> array[i][1];
    }

    std::vector<std::vector<int>> optimal(n + 1, std::vector<int>(k + 1, 0));

    for(int i = 0 ; i <= n ; i++) {
        for(int j = 0 ; j <= k ; j++) {
            if(i == 0 || j == 0) {
                optimal[i][j] = 0;
            }
            else {
                if(j >= array[i - 1][0]) {
                    optimal[i][j] = std::max(optimal[i - 1][j], optimal[i - 1][j - array[i - 1][0]] + array[i - 1][1]);
                }
                else {
                    optimal[i][j] = optimal[i - 1][j];
                }
            }
        }
    }

    std::cout << optimal[n][k] << "\n";
    
}