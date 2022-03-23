#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> p[i];
    }

    std::sort(p.begin(), p.end());
    int sum = 0;
    for(int i = 0 ; i < n ; i++) {
        sum += p[i]*(n - i);
    }

    std::cout << sum << "\n";
}