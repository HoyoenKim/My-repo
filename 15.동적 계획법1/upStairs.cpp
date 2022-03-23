#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> score(n, 0);
    std::vector<int> isUpto1(n, 0);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> score[i];
    }

    std::vector<int> maxScore1(n, 0);
    std::vector<int> maxScore2(n, 0);

    for(int i = 0 ; i < n ; i++) {
        if(i == 0) {
            maxScore1[i] = score[i];
        }
        else if(i == 1) {
            maxScore1[i] = score[i] + score[i - 1];
            maxScore2[i] = score[i];
        }
        else {
            // maxScore1
            maxScore1[i] = maxScore2[i - 1] + score[i];
            maxScore2[i] = std::max(maxScore1[i - 2], maxScore2[i - 2]) + score[i];
        }
    }
    
    std::cout << std::max(maxScore1[n - 1], maxScore2[n - 1]) << "\n";
}