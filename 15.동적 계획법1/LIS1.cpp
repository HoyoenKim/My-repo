#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> array(n);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i];
    }

    std::vector<int> answer(n, 1);

    int max = 1;
    for(int i = 1 ; i < n ; i++) {
        int maxIndex = -1;
        for(int j = 0 ; j < i ; j++) {
            if(array[j] < array[i]) {
                if(maxIndex < 0) {
                    maxIndex = j;
                }
                else if(answer[j] > answer[maxIndex]) {
                    maxIndex = j;
                }
            }
        }
        if(maxIndex >= 0) {
            answer[i] = answer[maxIndex] + 1;
        }
    }

    for(int i = 0 ; i < n ; i++) {
        if(answer[i] > max) {
            max = answer[i];
        }
    }

    std::cout << max << "\n";

}