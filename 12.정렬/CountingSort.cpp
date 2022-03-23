#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    int array[10001] = {0, };

    for(int i = 0 ; i < n ; i++) {
        int num;
        std::cin >> num;
        array[num]++;
    }

    for(int i = 0 ; i < 10001 ; i++) {
        if(array[i] == 0) {
            continue;
        }
        for(int j = 0 ; j < array[i] ; j++) {
            std::cout << i << "\n";
        }
    }
}