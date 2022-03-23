#include <iostream>
#include <vector>

int main() {
    int n;
    unsigned long long m;
    std::cin >> n;

    int count = 0, sum = 0, left = 0, right = 0;
    while(1) {
        if(right > n) {
            break;
        }

        if(sum == n) {
            count++;
        }
        
        if(n <= sum) {
            sum -= left + 1;
            left++;
        }
        else {
            sum += right + 1;
            right++;
        }
    }
    
    std::cout << count << "\n";
}