#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> h(n, 0);
    std::vector<int> w(n, 0);
    std::vector<int> r(n, 0);

    for(int i = 0 ; i < n ; i++) {
        std::cin >> w[i] >> h[i];
    }

    for(int i = 0 ; i < n ; i++) {
        int count = 0;
        for(int j = 0 ; j < n ; j++) {
            if(j != i) {
                if(w[i] < w[j] && h[i] < h[j]) {
                    count++;
                }
            }
        } 
        r[i] = count;
    }

    for(int i = 0 ; i < n ; i++) {
        std::cout << r[i] + 1 << " ";
    }
    std::cout << "\n";
}