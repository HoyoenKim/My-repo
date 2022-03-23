#include <iostream>

int main() {
    int array[42] = {0, };
    for(int i = 0 ; i < 10 ; i++) {
        int N;
        std::cin >> N;

        array[N%42] ++;
    }

    int count = 0;
    for(int i = 0 ; i < 42; i++) {
        if (array[i] > 0) {
            count ++;
        }
    }
    std::cout << count << "\n";
}