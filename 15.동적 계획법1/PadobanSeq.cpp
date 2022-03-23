#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    for(int i = 0 ; i < N ; i++) {
        int n;
        std::cin >> n;
        std::vector<long> array(n, 0);

        for(int j = 0 ; j < n ; j++) {
            if(j / 3 == 0) {
                array[j] = 1;
            }
            else if (j == 3 || j == 4) {
                array[j] = 2;
            }
            else {
                array[j] = array[j - 1] + array[j - 5];
            }
        }
        std::cout << array[n - 1] << "\n";
    }
}