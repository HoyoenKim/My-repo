#include <iostream>
#include <vector>

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> tree(n, 0);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> tree[i];
    }

    int end = 1000000000 - 1;
    int start = 0;

    while(start <= end) {
        int mid = (end + start) / 2;
        
        unsigned long long cutLen = 0;
        for(int i = 0 ; i < n ; i++) {
            if(tree[i] > mid + 1) {
                cutLen += (unsigned long long) tree[i] - (unsigned long long) (mid + 1);
            }
        }

        if(cutLen >= (unsigned long long) m) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    std::cout << start << "\n";
}