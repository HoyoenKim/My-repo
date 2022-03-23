#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::vector<int> a, std::vector<int> b) {
    // a < b -> 1 2 3 4 5
    // a > b -> 5 4 3 2 1
    if (a[1] != b[1]) {
        return a[1] < b[1];
    }
    else {
        return a[0] < b[0];
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> coord;
    for(int i = 0 ; i < n ; i++) {
        int x, y;
        std::cin >> x >> y;
        coord.push_back({x, y});
    }
    std::sort(coord.begin(), coord.end(), &compare);
    for(int i = 0 ; i < n ; i++) {
        std::cout << coord[i][0] << " " << coord[i][1] << "\n";
    }
}