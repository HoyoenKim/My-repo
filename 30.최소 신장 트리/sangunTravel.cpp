#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    for(int i = 0 ; i < N ; i++) {
        int n, m;
        std::cin >> n >> m;
        for(int i = 0 ; i < m ; i++) {
            int x, y;
            std::cin >> x >> y;
        }
        std::cout << n - 1 << "\n";
    }
}