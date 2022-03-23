#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> card(N, 0);

    for(int i = 0 ; i < N ; i++) {
        std::cin >> card[i];
    }

    int maxSum = 0;
    for(int i = 0 ; i < N ; i++) {
        for(int j = i + 1 ; j < N ; j++) {
            for(int k = j + 1 ; k < N ; k++) {
                int tempSum = card[i] + card[j] + card[k];
                if(tempSum <= M && maxSum < tempSum) {
                    maxSum = tempSum;
                }
            }
        }
    }

    std::cout << maxSum << "\n";
}