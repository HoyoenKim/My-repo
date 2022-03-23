#include <iostream>
#include <cmath>

int main() {
    int N;
    std::cin >> N;
    std::string ret = "";

    for(int i = 0; i < N ; i++) {
        for(int j = 0; j < N ; j++) {
            ret += "*";
        }
    }

    int n = N;
    while(n > 1) {
        n /= 3;
        for(int i = 0; i < N ; i++) {
            for(int j = 0; j < N ; j++) {
                if( (i / n) % 3 == 1 && (j / n) % 3 == 1) {
                    ret[i*N + j] = ' ';
                }
            }
        }

    }

    for(int i = 0; i < N ; i++) {
        for(int j = 0; j < N ; j++) {
            std::cout << ret[i*N + j];
        }
        std::cout << "\n";
    }
}