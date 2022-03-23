#include <iostream>
#include <vector>
#include <map>

int main() {
    int n;
    std::cin >> n;
    std::map<int, int> m;
    for(int i = 0 ; i < n ; i++) {
        int j;
        std::cin >> j;
        if(m.count(j)) {
            m[j] += 1;
        }
        else {
            m[j] = 1;
        }
    }

    int k;
    std::cin >> k;
    for(int i = 0 ; i < k ; i++) {
        int find;
        std::cin >> find;
        if(m.count(find)) {
            std::cout << m[find] << " ";
        }
        else {
            std::cout << 0 << " ";
        }
    }
    std::cout << "\n";
}