#include <iostream>
#include <vector>

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> sum(n + 1, 0);
    for(int i = 0 ; i < n ; i++) {
        int x;
        std::cin >> x;
        if(i == 0) {
            sum[i + 1] = x;
        }
        else {
            sum[i + 1] = sum[i] + x; 
        }
    }

    for(int i = 0 ; i < m ; i++) {
        int lower, upper;
        std::cin >> lower >> upper;
        std::cout << sum[upper] - sum[lower -1] << "\n";
    }
}