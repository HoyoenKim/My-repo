#include <iostream>
#include <vector>

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int k, n;
    std::cin >> k >> n;
    int minLen = -1;
    std::vector<int> lanlen(k, 0);
    for(int i = 0 ; i < k ; i++) {
        std::cin >> lanlen[i];
        if(i == 0) {
            minLen = lanlen[i];
        }
        else {
            if(minLen > lanlen[i]) {
                minLen = lanlen[i];
            }
        }
    }

    int end = INT32_MAX - 1;
    int start = 0;
    int i;
    while(start <= end) {
        i = ((unsigned long long) end + (unsigned long long) start) / 2;
        int count = 0;
        for(int j = 0 ; j < k ; j++) {
            count += lanlen[j] / (i + 1) ;
        }
        
        if(count >= n) {
            start = i + 1;
        }
        else if(count < n) {
            end = i - 1;
        }
    }

    std::cout << start << "\n";
}