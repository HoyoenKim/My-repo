#include <iostream>

int main () {
    int N;
    std::cin >> N;

    for (int i = 0 ; i < N ; i++) {
        int a, b;
        std::cin >> a >> b;
        std::cout << a + b << std::endl;
    }
    return 0;
}