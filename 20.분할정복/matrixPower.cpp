#include <iostream>
#include <vector>
#include <cmath>

int n;
std::vector<std::vector<int>> matrixMultiplication(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B) {
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            int sum = 0;
            for(int k = 0 ; k < n ; k++) {
                sum += (A[i][k] * B[k][j]) % 1000;
            }
            C[i][j] = sum % 1000;
        }
    }

    return C;
}

int main() {
    unsigned long long B;
    std::cin >> n >> B;
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 0));

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            std::cin >> A[i][j];
        }
    }

    int m = std::log(B) / std::log(2);
    std::vector<std::vector<std::vector<int>>> MT (m + 1, std::vector<std::vector<int>>(n, std::vector<int>(n, 0)));

    for(int i = 0 ; i <= m ; i++) {
        if(i == 0) {
            MT[i] = A;
        }
        else {
            MT[i] = matrixMultiplication(MT[i - 1], MT[i - 1]);
        }
    }

    std::vector<std::vector<int>> ret(n, std::vector<int>(n, 0));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(i == j) {
                ret[i][j] = 1;
            }
        }
    }

    for(int i = 0 ; i <= m ; i++) {
        if( (B & ((unsigned long long)1 << i)) == ((unsigned long long)1 << i) ) {
            ret = matrixMultiplication(ret, MT[i]);
        }
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            std::cout << ret[i][j] << " ";
        }
        std::cout << "\n";
    }
}