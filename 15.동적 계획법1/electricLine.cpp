#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::vector<int> a, std::vector<int> b) {
    return a[0] < b[0];
}
bool compare2(std::vector<int> a, std::vector<int> b) {
    return a[1] < b[1];
}
int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> array(n, std::vector<int>(2));

    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i][0] >> array[i][1];
    }

    std::sort(array.begin(), array.end(), &compare);
    for(int i = 0 ; i < n ; i++) {
        //std::cout << array[i][0] << " " << array[i][1] << "\n";
    }

    std::vector<int> answer1(n, 1);
    for(int i = 1 ; i < n ; i++) {
        int maxIndex = -1;
        for(int j = 0 ; j < i ; j++) {
            if(array[i][1] > array[j][1]) {
                if(maxIndex < 0) {
                    maxIndex = j;
                }
                else {
                    if(answer1[j] > answer1[maxIndex]) {
                        maxIndex = j;
                    }
                }
            }
        }
        if(maxIndex >= 0) {
            answer1[i] = answer1[maxIndex] + 1; 
        }
    }

    std::vector<int> answer2(n, 1);
    for(int i = n - 2 ; i >= 0 ; i--) {
        int maxIndex = -1;
        for(int j = i + 1 ; j < n ; j++) {
            if(array[i][1] > array[j][1]) {
                if(maxIndex < 0) {
                    maxIndex = j;
                }
                else {
                    if(answer2[j] > answer2[maxIndex]) {
                        maxIndex = j;
                    }
                }
            }
        }
        if(maxIndex >= 0) {
            answer2[i] = answer2[maxIndex] + 1; 
        }
    }

    int max1 = 1;
    int max2 = 1;

    for(int i = 0 ; i < n ; i++) {
        if(max1 < answer1[i]) {
            max1 = answer1[i];
        }
        if(max2 < answer2[i]) {
            max2 = answer2[i];
        }
    }
    std::cout << max1 << "\n";

}