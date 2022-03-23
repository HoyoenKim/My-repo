#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> score(N);

    int max = -1;
    for (int i = 0 ; i < N ; i++) {
        int n;
        std::cin >> n;
        score[i] = n;

        if (max < n) {
            max = n;
        }
    }

    double sum = 0;
    for (int i = 0 ; i < N ; i++) {
        sum += ((double) score[i] / (double) max) * (double) 100;
    }
    std::cout << sum / (double) N << "\n";
}