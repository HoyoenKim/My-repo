#include <iostream>
#include <vector>
int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<std::vector<int>> bc(N, std::vector<int>(N, 0));

    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j <= i ; j++) {
            if(j == 0) {
                bc[i][j] = 1;
            }
            else if(i == j) {
                bc[i][j] = 1;
            }
            else {
                bc[i][j] = (bc[i - 1][j] + bc[i - 1][j - 1]) % 10007;
            }
        }
    }
    std::cout << (bc[N - 1][K] + bc[N - 1][K - 1]) % 10007 << "\n";
}