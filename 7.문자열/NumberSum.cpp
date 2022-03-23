#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;

    std::string numberStr;
    std::cin >> numberStr;

    int sum = 0;
    for(int i = 0 ; i < N ; i++) {
        sum += numberStr[i] - '0';
    }

    std::cout << sum << "\n";
}