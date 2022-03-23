#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> numArray;
    while(n > 0) {
        numArray.push_back(n%10);
        n /= 10;
    }

    std::sort(numArray.begin(), numArray.end());
    for(int i = numArray.size() - 1 ; i >= 0 ; i--) {
        std::cout << numArray[i];
    }
    std::cout << "\n";
    
}