#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> alpabetExistence('z' - 'a' + 1, -1);
    std::string inputStr;
    std::cin >> inputStr;

    for (int i = 0 ; i < inputStr.length() ; i++) {
        if (alpabetExistence[inputStr[i] - 'a'] == -1) {
            alpabetExistence[inputStr[i] - 'a'] = i;
        }
    }

    for (int i = 0 ; i < alpabetExistence.size() ; i++) {
        std::cout << alpabetExistence[i] << " ";
    }
    std::cout << "\n";
}