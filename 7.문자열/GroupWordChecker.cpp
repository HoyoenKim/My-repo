#include <iostream>
#include <string>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    int count = 0;
    for(int i = 0 ; i < N ; i++) {
        std::string word;
        std::cin >> word;
        std::vector<int> groupCheck('z' - 'a' + 1, -1);
        
        int isGroup = 1;
        for(int j = 0 ; j < word.length() ; j++) {
            if (groupCheck[word[j] - 'a'] == -1) {
                groupCheck[word[j] - 'a'] = j;
            }
            else {
                if(groupCheck[word[j] - 'a'] + 1 != j) {
                    isGroup = 0;
                }
                groupCheck[word[j] - 'a'] = j;
            }
        }

        if(isGroup == 1) {
            count++;
        }
    }

    std::cout << count;
}