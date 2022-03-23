#include <iostream>

int main() {
    // 1, 1+6*1 = 7, 1+6*1+6*2 = 19

    int n;
    std::cin >> n;

    int s = 1;
    int i = 0;
    while(1) {
        if(n <= s + 6*i) {
            break;
        }
        s = s + 6*i;
        i++;
    }

    std::cout << i+1 << "\n";
}