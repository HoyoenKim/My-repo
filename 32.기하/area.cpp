#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> array(n, std::vector<int>(2, 0));
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i][0] >> array[i][1];
    }

    long long a = (long long) array[n - 1][0] * (long long) array[0][1] - (long long) array[0][0] * (long long) array[n - 1][1];
    for(int i = 0 ; i < n ; i++) {
        if(i != n -1) {
            a += (long long) array[i][0] * (long long) array[i + 1][1];
        }

        if(i != 0) {
            a -= (long long) array[i][0] * (long long) array[i - 1][1];
        }        
    }
    
    if(a % 2 == 0) {
        std::cout << std::abs(a) / (long long) 2 << ".0\n";
    }
    else {
        std::cout << std::abs(a) / (long long) 2 << ".5\n";
    }
}