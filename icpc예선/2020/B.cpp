#include <iostream>
#include <vector>
int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a %b);
    }
}

int main() {
    std::vector<int> dice1(6);
    std::vector<int> dice2(6);

    for(int i = 0 ; i < 6 ; i++) {
        std::cin >> dice1[i];
    }

    for(int i = 0 ; i < 6 ; i++) {
        std::cin >> dice2[i];
    }

    int count = 0;
    for(int i = 0 ; i < 6 ; i++) {
        for(int j = 0 ; j < 6 ; j++) {
            if(dice1[i] > dice2[j]) {
                count++;
            }
        }
    }

    int g = gcd(count, 36);

    std::cout << count / g << "/" << 36 / g << "\n";
}