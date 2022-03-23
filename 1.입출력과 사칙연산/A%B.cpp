#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;
    double ret = (double) A / (double) B;
    std::cout.precision(14);
    std::cout << ret << std::endl;
    return 0;
}