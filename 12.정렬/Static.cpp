#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> array(n);
    std::vector<int> arrayCount(8001, 0);
    int sum = 0;
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i];
        sum += array[i];
        arrayCount[array[i] + 4000]++;
    }
    std::sort(array.begin(), array.end());

    int avg = std::floor((double) sum / (double) n + 0.5);
    int mid = array[n/2];

    std::vector<int> mostValue;
    int minCount = 0;
    for(int i = 0 ; i < 8001 ; i++) {
        if(arrayCount[i] > 0) {
            if(minCount == 0) {
                minCount = arrayCount[i];
                mostValue.push_back(i);
            }
            else if(minCount == arrayCount[i]) {
                mostValue.push_back(i);
            }
            else if(minCount < arrayCount[i]) {
                minCount = arrayCount[i];
                mostValue.clear();
                mostValue.push_back(i);
            }
        }
    }

    int mostV;
    if(mostValue.size() == 1) {
        mostV = mostValue[0];
    }
    else {
        std::sort(mostValue.begin(), mostValue.end());
        mostV = mostValue[1];
    }

    int range = array[n-1] - array[0];

    std::cout<< avg <<"\n";
    std::cout<< mid <<"\n";
    std::cout<< mostV - 4000 <<"\n";
    std::cout<< range <<"\n";
}