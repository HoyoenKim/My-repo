#include <iostream>

int main() {
    int N;
    std::cin >> N;

    if (N > 1) {
        int startInt = 2;
        while(N > 1) {
            for(int i = startInt ; i <= N ; i++) {
                if(N % i == 0) {
                    startInt = i;
                    N /= i;
                    std::cout << i << "\n";
                    break;
                }
            }
        }
    }   
}