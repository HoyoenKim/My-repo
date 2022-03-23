#include <iostream>

int fibonachi(int N) {
    if (N == 0) {
        return 0;
    }
    else if(N == 1) {
        return 1;
    }
    else {
        return fibonachi(N - 1) + fibonachi(N - 2);
    }
}
int main() {
    int n;
    std::cin >> n;
    std::cout << fibonachi(n) << "\n";
}