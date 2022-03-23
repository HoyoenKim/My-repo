#include <iostream>

char isHansoo(int i) {
    if (i / 100 + i % 10 == 2*((i / 10) % 10)) {
        return true;
    }
    return false;
}

int main() {
    int N;
    std::cin >> N;

    int count = 0;
    for (int i = 1 ; i <= N ; i++) {
        if (i < 100) {
            count ++;
        }
        else if (i < 1000) {
            if (isHansoo(i)) {
                count ++;
            }
        }
    }

    std::cout << count << "\n";
}