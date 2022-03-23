#include <iostream>

int main() {
    unsigned long long s;
    std::cin >> s;

    unsigned long long i = 1;
    while(1) {
        if(s < i * (i + 1LL) / 2LL) {
            break;
        }
        i += 1;
    }
    std::cout << i - 1 << "\n";
}