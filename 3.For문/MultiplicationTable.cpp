#include <iostream>

int main () {
    int A;
    std::cin >> A;

    for (int i = 0 ; i < 9 ; i++) {
        std::cout << A << " * " << i + 1 << " = " << A*(i+1) << std::endl; 
    }

    return 0;
}