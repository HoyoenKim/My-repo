#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, c;
    std::cin >> n >> c;
    std::vector<int> cord(n, 0);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> cord[i];
    }
    std::sort(cord.begin(), cord.end());    
    if(c == 2) {
        int dist = cord[n - 1] - cord[0];
        std::cout << dist << "\n";
    }
    else {
        double unit = (double) (n - 1) / (double) (c - 1);
        // cord[0], cord[0] + unit, ... cord[0] + (c - 1) * unit == cord[n -1];
    }
}