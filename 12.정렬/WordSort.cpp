#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool compare(std::string a, std::string b) {
    int aSize = a.size();
    int bSize = b.size();
    if(aSize != bSize) {
        return aSize < bSize;
    }
    else {
        return a < b;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> wordList(n);
    
    for(int i = 0 ; i < n ; i++) {
        std::string str;
        std::cin >> str;
        wordList[i] = str;
    }
    
    std::sort(wordList.begin(), wordList.end(), &compare);

    for(int i = 0 ; i < n ; i++) {
        if(i != n -1) {
            if(wordList[i] == wordList[i + 1]) {
                continue;
            }
        }
        std::cout << wordList[i] << "\n";
    }
}