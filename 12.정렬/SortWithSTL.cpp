#include <iostream>
#include <vector>
#include <algorithm>

bool compare(int a, int b) {
    // a < b -> 1 2 3 4 5
    // a > b -> 5 4 3 2 1
    return a < b;
} 

int main() {
    /*
    int n;
    std::cin >> n;
    int array[n];
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i];
    }

    std::sort(array, array + n, compare);
    for(int i = 0 ; i < n ; i++) {
        std::cout << array[i] << "\n";
    }
    */

    int n;
    std::cin >> n;
    std::vector<int> array(n);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i];
    }

    std::sort(array.begin(), array.end());
    for(int i = 0 ; i < n ; i++) {
        std::cout << array[i] << "\n";
    }
}