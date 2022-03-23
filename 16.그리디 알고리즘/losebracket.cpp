#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string str;
    std::cin >> str;

    std::vector<int> num;
    std::vector<int> op; //1: +, 0: -;
    std::string number = "";

    int i = 0;
    while(1) {
        if(i == str.length()) {
            break;
        }

        if(str[i] == '+' || str[i] == '-') {
            if(str[i] == '+') {
                op.push_back(1);
            }
            else if(str[i] == '-') {
                op.push_back(0);
            }
            num.push_back(std::stoi(number));
            number = "";
        }

        if('0' <= str[i] && str[i] <= '9') {
            number.append(1, str[i]);
        }
        i++;
    }
    num.push_back(std::stoi(number));
    number = "";

    /*
    for(int i = 0 ; i < num.size() ; i++) {
        std::cout << num[i] << " ";
    }
    std::cout << "\n";

    for(int i = 0 ; i < op.size() ; i++) {
        std::cout << op[i] << " ";
    }
    std::cout << "\n";
    */

    std::vector<int> newNum;
    int sum = 0;
    op.push_back(0);
    for(int i = 0; i < num.size(); i++) {
        sum += num[i];
        if(op[i] == 0) {
            newNum.push_back(sum);
            sum = 0;
        }
    }

    sum = newNum[0];
    for(int i = 1 ; i < newNum.size() ; i++) {
        sum -= newNum[i];
    }
    std::cout << sum << "\n";
}