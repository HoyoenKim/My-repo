#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int m;
    std::cin >> m;

    std::vector<int> f(m + 1, 0);
    for(int i = 1 ; i <= m ; i++) {
        std::cin >> f[i];
    }

    int k = std::log(500000) / std::log(2);
    std::vector<std::vector<int>> f2n(k + 1, std::vector<int> (m + 1, 0));
    for(int i = 0 ; i <= k ; i++) {
        if(i == 0) {
            f2n[i] = f;
        }
        else {
            std::vector<int> temp(m + 1, 0);
            for(int j = 1 ; j <= m ; j++) {
                temp[j] = f2n[i - 1][f2n[i - 1][j]];
            }
            f2n[i] = temp;
        }
    }

    int q;
    std::cin >> q;
    for(int i = 0 ; i < q ; i++) {
        int n, x;
        std::cin >> n >> x;

        for(int j = 0 ; j <= k ; j++) {
            if((n >> j) & 1 == 1) {
                x = f2n[j][x];
            }
        }
        std::cout << x << "\n";
    }
}