#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> array(n, 0);

    for(int i = 1 ; i <= n ; i++) {
        if(i == 1) {
            array[i] = 9;
        }
        else {
            array[i] = (2 * array[i - 1] - 2 * i + 3) % 1000000000;
        }
    }

    std::cout << array[n] << "\n";
}