#include <iostream>

int dSum(int N) {
    int n = N;
    int sum = N;
    while(n > 0) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main() {
    int N;
    std::cin >> N;

    int n = 0;
    for(int i = 0 ; i < N ; i++) {
        if(N == dSum(i)) {
            n = i;
            break;
        }
    }
    std::cout << n << "\n";
}