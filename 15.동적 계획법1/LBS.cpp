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

    std::vector<int> answer2(n, 1);

    for(int i = n - 2 ; i >= 0 ; i--) {
        int maxIndex = -1;
        for(int j = i + 1 ; j < n ; j++) {
            if(array[j] < array[i]) {
                if(maxIndex < 0) {
                    maxIndex = j;
                }
                else if(answer2[j] > answer2[maxIndex]) {
                    maxIndex = j;
                }
            }
        }
        if(maxIndex >= 0) {
            answer2[i] = answer2[maxIndex] + 1;
        }
    }

    for(int i = 0 ; i < n - 1; i++) {
        if((answer[i] + answer2[i]) > max) {
            max = (answer[i] + answer2[i]);
        }
    }

    if(max == 1) {
        std::cout << 1<< "\n";
    }
    else {
        std::cout << max - 1<< "\n";
    }
    

}