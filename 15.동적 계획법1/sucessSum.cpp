#include <iostream>
#include <vector>

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<int> array(n);
    std::vector<int> sucessSum(n, 0);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i];
    }

    for(int i = 0 ; i < n ; i++) {
        if(i == 0) {
            sucessSum[i] = array[i];
        }
        else {
            int a = sucessSum[i - 1] + array[i];
            int b = array[i];
            sucessSum[i] = std::max(a, b);
        }
    }

    int max = -1000;
    for(int i = 0 ; i < n ; i++) {
        if(max < sucessSum[i]) {
            max = sucessSum[i];
        }
    }
    
    std::cout << max << "\n";
}