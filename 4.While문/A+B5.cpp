#include <iostream>

int main() {
    while(1) {
        int a, b;
        std::cin >> a >> b;
        if(a == 0 && b == 0) {
            break;
        }
        std::cout<<a+b<<"\n";
    }
}