#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int i = N / 5;
    int count;
    while(1) {
        if( (N - 5 * i) % 3 == 0) {
            count = i + (N - 5 * i) / 3;
            break;
        }
        if(i == 0) {
            count = -1;
            break;
        }
        i--;
    }

    std::cout << count << "\n";
}