#include <iostream>
#include <vector>
#include <algorithm>

int n;
std::vector<int> num;
std::vector<int> op(4, 0);

int isFrist = 0;
int min, max;
void calValue(int index, int value) {
    if(index == n) {
        if (isFrist == 0) {
            isFrist = 1;
            min = max = value;
        }
        else {
            if(value < min) {
                min = value;
            }

            if(value > max) {
                max = value;
            }
        }
    }
    else {
        for(int i = 0 ; i < 4 ; i++) {
            if(i == 0) {
                if(op[i] > 0) {
                    op[i]--;
                    calValue(index + 1, value + num[index]);
                    op[i]++;
                }
            }
            else if(i == 1) {
                if(op[i] > 0) {
                    op[i]--;
                    calValue(index + 1, value - num[index]);
                    op[i]++;
                }
            }
            else if(i == 2) {
                if(op[i] > 0) {
                    op[i]--;
                    calValue(index + 1, value * num[index]);
                    op[i]++;
                }
            }
            else if(i == 3) {
                if(op[i] > 0) {
                    op[i]--;
                    calValue(index + 1, value / num[index]);
                    op[i]++;
                }
            }
        }
    }
}

int main() {
    std::cin >> n;
    for(int i = 0 ; i < n ; i++) {
        int number;
        std::cin >> number;
        num.push_back(number);
    }

    for(int i = 0 ; i < 4 ; i++) {
        std::cin >> op[i];
    }
    calValue(1, num[0]);
    std::cout << max << "\n" << min << "\n";
}