#include <iostream>
#include <string>

int main() {
    std::string sentence;
    std::getline(std::cin, sentence);
    int count = 0;
    int isExistWord = 0;
    for(int i = 0 ; i < sentence.length() ; i++) {
        if (i != 0 && i != sentence.length() - 1 && sentence[i] == ' ') {
            count ++;
        }
        
        if ((sentence[i] <= 'z' && sentence[i] >= 'a') ||  (sentence[i] <= 'Z' && sentence[i] >= 'A')) {
            isExistWord = 1;
        }
    }

    std::cout << count + isExistWord << "\n";

}