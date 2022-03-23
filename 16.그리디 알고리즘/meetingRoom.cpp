#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::vector<int> a, std::vector<int> b) {
    if(a[1] == b[1]) {
        return a[0] < b[0];
    }
    else {
        return a[1] < b[1];
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> mt(n, std::vector<int>(3, 0));
    int timeMax = 0;
    for(int i = 0 ; i < n ; i++) {
        std::cin >> mt[i][0] >> mt[i][1];
    }

    std::sort(mt.begin(), mt.end(), &compare);
    for(int i = 0 ; i < n ; i++) {
        std::cout << mt[i][0] << " " << mt[i][1] << "\n";
    }
    int count = 0;
    int beforeEnd = 0;
    for(int i = 0 ; i < n ; i++) {
        if(mt[i][0] >= beforeEnd) {
            beforeEnd = mt[i][1];
            count ++;
        }
    }

    std::cout << count << "\n";
}