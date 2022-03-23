#include <iostream>

int main() {
    // 1) a/b, a+b-1 odd: 3/1 -> 2/2 -> 1/3, a+b-1 even: 1/2 -> 2/1.
    // 2) 1th 1, 2th 2, 3th 3

    int n;
    std::cin >> n;

    int i = 1;
    while(1) {
        if(n <= i*(i+1)/2) {
            break;
        }
        i++;
    }

    if (i % 2 == 0) {
        std::cout << i - (i*(i+1)/2 - n) << "/"  << (i*(i+1)/2 - n) + 1 << "\n";
    }
    else {
        std::cout << (i*(i+1)/2 - n) + 1 << "/" << i - (i*(i+1)/2 - n) << "\n";
    }
}   