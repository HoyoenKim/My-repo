#include <iostream>
#include <stack>
#include <string>

int main() {
    while(1) {
        std::string str;
        std::getline(std::cin, str);

        if(str.length() == 1 && str[0] == '.') {
            break;
        }
        
        std::stack<int> s;

        int isOkay = 1;
        for(int j = 0 ; j < str.length() ; j++) {
            if(str[j] == '(') {
                s.push(1);
            }
            else if(str[j] == ')') {
                if(s.size() > 0) {
                    if(s.top() == 1) {
                        s.pop();
                    }
                    else {
                        isOkay = 0;
                        break;
                    }
                }
                else {
                    isOkay = 0;
                    break;
                }
            }
            else if(str[j] == '[') {
                s.push(2);
            }
            else if(str[j] == ']') {
                if(s.size() > 0) {
                    if(s.top() == 2) {
                        s.pop();
                    }
                    else {
                        isOkay = 0;
                        break;
                    }
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
            std::cout << "yes" << "\n";
        }
        else {
            std::cout << "no" << "\n";
        }
    }
}