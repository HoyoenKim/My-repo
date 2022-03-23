#include <iostream>
#include <vector>

int main() {
    int n;
    unsigned long long m;
    std::cin >> n >> m;

    std::vector<int> array(n);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i];
    }

    int count = 0, sum = 0, left = 0, right = 0;
    while(1) {
        if(right > n) {
            break;
        }

        if(sum == m) {
            count++;
        }
        
        if(m <= sum) {
            sum -= array[left];
            left++;
        }
        else {
            sum += array[right];
            right++;
        }
    }
    
    std::cout << count << "\n";
}