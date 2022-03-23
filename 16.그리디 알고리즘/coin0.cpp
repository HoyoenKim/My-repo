#include <iostream>
#include <vector>

int main() {
    int n, value;
    std::cin >> n >> value;

    std::vector<int> coin(n, 0);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> coin[i];
    }

    int k = 0;
    for(int i = n - 1 ; i >= 0 ; i--) {
        if(coin[i] <= value) {
            k += value / coin[i];
            value %= coin[i];
        }
    }

    std::cout << k << "\n";
}