#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            std::cin >> A[i][j];
        }
    }

    int K;
    std::cin >> M >> K;

    std::vector<std::vector<int>> B(M, std::vector<int>(K, 0));
    for(int j = 0 ; j < M ; j++) {
        for(int k = 0 ; k < K ; k++) {
            std::cin >> B[j][k];
        }
    }

    std::vector<std::vector<int>> C(N, std::vector<int>(K, 0));
    for(int i = 0 ; i < N ; i++) {
        for(int k = 0 ; k < K ; k++) {
            int sum = 0;
            for(int j = 0 ; j < M ; j++) {
                sum += A[i][j] * B[j][k];
            }
            C[i][k] = sum;
        }
    }

    for(int i = 0 ; i < N ; i++) {
        for(int k = 0 ; k < K ; k++) {
            std::cout << C[i][k] << " ";
        }
        std::cout << "\n";
    }
}
