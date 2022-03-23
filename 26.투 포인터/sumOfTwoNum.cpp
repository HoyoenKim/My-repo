#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    unsigned long long n, m;
    std::cin >> n;
    std::vector<unsigned long long> array(n);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i];
    }
    std::cin >> m;

    std::sort(array.begin(), array.end());
    
    int left = 0;
    int right = n - 1;
    int count = 0;
    while(left < right) {
        unsigned long long sum = array[left] + array[right];
        
        if(sum == m) {
            count += 1;
        }

        if(sum >= m) {
            right -= 1;
        }
        else {
            left += 1;
        }
    }
    std::cout << count << "\n";
}