#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string word;
    std::cin >> word;
    std::vector<int> numA('z' - 'a' + 1, 0);

    for(int i = 0 ; i < word.length() ; i++) {
        if (word[i] >= 'a') {
            numA[word[i] - 'a']++;
        }
        else {
            numA[word[i] - 'A']++;
        }
    }

    int max = -1;
    int multiMax = 0;
    int maxIndex = 0;
    for (int i = 0 ; i < numA.size() ; i++) {
        if (max < numA[i]) {
            max = numA[i];
            maxIndex = i;
            multiMax = 0;
        }
        else if (max == numA[i]) {
            multiMax = 1;
        }
    }

    if (multiMax == 1) {
        std::cout << "?\n";
    }
    else {
        std::cout << (char)('A' + maxIndex) << "\n";
    }
}