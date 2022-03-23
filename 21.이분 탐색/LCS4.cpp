#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::vector<int> a, std::vector<int> b) {
    return a[0] < b[0];
}

int findLIS(std::vector<int> array, int n) {
    std::vector<int> answer(n, 1);
    std::vector<int> xArray;
    std::vector<int> xAnswer;
    int num = -1;
    for(int i = 0 ; i < n ; i++) {
        if(i == 0) {
            xArray.push_back(array[i]);
            xAnswer.push_back(answer[i]);
            num ++;
        }
        else {
            if(xArray[num] < array[i]) {
                xArray.push_back(array[i]);
                answer[i] = xAnswer[num] + 1;
                xAnswer.push_back(answer[i]);
                num++;
            }
            else {
                int changeIndex = std::lower_bound(xArray.begin(), xArray.end(), array[i]) - xArray.begin();
                answer[i] = xAnswer[changeIndex];
                xArray[changeIndex] = array[i];
            }
        }
    }

    for(int i = 0 ; i <= num ; i++) {
        //std::cout << xArray[i] << " ";
    }
    //std::cout << "\n";
    return xAnswer[num];
}

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<int> converter(n + 1);
    std::vector<int> array1(n);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array1[i];
        converter[array1[i]] = i + 1;
    }

    std::vector<int> array2(n);
    for(int i = 0 ; i < n ; i++) {
        int j;
        std::cin >> j;
        array2[i] = converter[j];
    }

    std::cout << findLIS(array2, n) << "\n";
}