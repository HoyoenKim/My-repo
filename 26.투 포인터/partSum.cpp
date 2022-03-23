#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, s;
    std::cin >> n >> s;

    std::vector<int> seq(n, 0);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> seq[i];
    }

    int left = 0, right = 1;
    if(seq[0] >= s) {
        std::cout << 1 << "\n";
        return 0;
    }

    int sum = seq[0] + seq[1];
    int seqLen = -1;
    while(right < n) {
        if(sum >= s) {
            int seqLenTemp = right - left + 1;
            if(seqLen < 0) {
                seqLen = seqLenTemp;
            }
            else if(seqLenTemp < seqLen){
                seqLen = seqLenTemp;
            }
            
            sum -= seq[left];
            left += 1;
        }
        else {
            right += 1;
            sum += seq[right];
        }
    }

    if(seqLen == -1) {
        seqLen = 0;
    }
    std::cout << seqLen << "\n";
}