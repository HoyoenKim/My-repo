#include <iostream>
#include <stack>
#include <string>

int main() {
    int n;
    std::cin >> n;

    for(int i = 0 ; i < n ; i++) {
        std::string str;
        std::cin >> str;
        std::stack<int> s;

        int isOkay = 1;
        for(int j = 0 ; j < str.length() ; j++) {
            if(str[j] == '(') {
                s.push(1);
            }
            else if(str[j] == ')') {
                if(s.size() > 0) {
                    s.pop();
                }
                else {
                    isOkay = 0;
                    break;
                }
            }
        }

        if(s.size() > 0) {
            isOkay = 0;
        }

        if(isOkay) {
            std::cout << "YES" << "\n";
        }
        else {
            std::cout << "NO" << "\n";
        }
    }
}