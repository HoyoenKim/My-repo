#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s1, s2, num1, num2;
    std::cin >> s1 >> s2;

    if(s1.length() > s2.length()) {
        num1 = s1;
        num2 = s2;
    }
    else {
        num1 = s2;
        num2 = s1;
    }

    std::string ret = "";
    int upperNum = 0;
    for(int i = 0 ; i < num1.length(); i++) {
        int n2 = 0;
        if(i < num2.length()) {
            n2 = num2[num2.length() - 1 - i] - '0';
        }
        int n1 = num1[num1.length() - 1 - i] - '0';

        if (n1 + n2 + upperNum >= 10) {
            ret += (char) ((n1 + n2 + upperNum - 10) + '0');
            upperNum = 1;
        }
        else {
            ret += (char) ((n1 + n2 + upperNum) + '0');
            upperNum = 0;
        }
    }

    if(upperNum == 1) {
        ret += '1';
    }

    std::reverse(ret.begin(), ret.end());
    std::cout << ret << "\n";
}