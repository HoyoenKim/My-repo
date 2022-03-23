#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> liq(n, 0);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> liq[i];
    }
    std::sort(liq.begin(), liq.end());

    int left = 0, right = n - 1, ansLeft = 0, ansRight = n - 1;
    int svalue = INT32_MAX;
    while(left < right) {
        int temp = liq[left] + liq[right];
        if(std::abs(temp) < svalue) {
            svalue = std::abs(temp);
            ansLeft = left;
            ansRight = right;
        }

        if(temp == 0) {
            ansLeft = left;
            ansRight = right;
            break;
        }
        else if(temp > 0) {
            right -= 1;
        }
        else if(temp < 0) {
            left += 1;
        }
    }

    std::cout << liq[ansLeft] << " " << liq[ansRight] << "\n";
}