#include <iostream>

int main() {
    int A, B, C;
    std::cin >> A;
    std::cin >> B;
    std::cin >> C;

    int num = A * B * C;
    int array[10] = {0, };

    while(1) {
        array[num%10]++;
        if (num / 10 == 0) {
            break;
        }
        num /= 10;
    }

    for (int i = 0 ; i < 10 ; i++) {
        std::cout << array[i] << "\n";
    }
}