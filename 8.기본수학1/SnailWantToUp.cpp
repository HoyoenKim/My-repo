#include <iostream>

int main() {
    int A, B, V;
    std::cin >> A >> B >> V;

    if ((V - A) % (A - B) == 0) {
        std::cout << (V - A) / (A - B) + 1 << "\n"; 
    }
    else {
        std::cout << (V - A) / (A - B) + 2 << "\n";
    } 
}