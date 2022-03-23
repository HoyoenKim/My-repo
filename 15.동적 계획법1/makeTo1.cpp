#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> array(n + 1, 0);

    for(int i = 2 ; i <= n ; i++) {
        if(i == 2) {
            array[i] = 1;
        }
        else if(i == 3) {
            array[i] = 1;
        }
        else {
            if(i % 6 == 0) {
                array[i] = std::min(std::min(array[i/3], array[i/2]), array[i -1]) + 1;
            }
            else if(i % 3 == 0) {
                array[i] = std::min(array[i/3], array[i - 1]) + 1;
            }
            else if(i % 2 == 0) {
                array[i] = std::min(array[i/2], array[i -1]) + 1;
            }
            else {
                array[i] = array[i - 1] + 1;
            }
        }
    }

    std::cout << array[n] << "\n";
}