#include <iostream>
#include <cmath>
int main() {
    double n;
    std::cin >> n;
    std::cout << std::fixed;
    std::cout.precision(6);
    std::cout << (double) n * (double) n * (double) M_PI << "\n" << (double) n * (double) n * (double) 2 << "\n";
}