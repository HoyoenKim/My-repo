#include <iostream>
#include <deque>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    for(int i = 0 ; i < n ; i++) {
        std::string order;
        std::cin >> order;

        int arraySize;
        std::cin >> arraySize;

        std::deque<int> dq;
        std::string arrayStr;
        std::cin >> arrayStr;

        int j = 1;
        std::string number = "";
        while(1) {
            if(j == arrayStr.length()) {
                break;
            }
            if(arrayStr[j] == ',' || arrayStr[j] == ']') {
                if(number.length() > 0) {
                    dq.push_back(std::stoi(number));
                }
                number = "";
            }
            else if(arrayStr[j] <= '9' && arrayStr[j] >= '0') {
                number.append(1, arrayStr[j]);
            }
            j++;
        }
        /*
        (front) 1 2 3 4 (back)
        for(int i = 0 ; i < dq.size() ; i++) {
            std::cout << dq[i] << " ";
        }
        */
        int isPopFront = 1;
        int isError = 0;
        for(int k = 0; k < order.length() ; k++) {
            if(order[k] == 'R') {
                isPopFront += 1;
                isPopFront %= 2;
            }
            else if(order[k] == 'D') {
                if(dq.size() > 0) {
                    if(isPopFront) {
                        dq.pop_front();
                    }
                    else {
                        dq.pop_back();
                    }
                }
                else {
                    isError = 1;
                    break;
                }
            }
        }

        if(isError) {
            std::cout << "error\n";
        }
        else {
            std::cout << "[";
            if(isPopFront) {
                for(int k = 0 ; k < dq.size() ; k++) {
                    std::cout << dq[k];
                    if(k != dq.size() - 1) {
                        std::cout << ",";
                    }
                }
            }
            else {
                for(int k = dq.size() - 1 ; k >= 0 ; k--) {
                    std::cout << dq[k];
                    if(k != 0) {
                        std::cout << ",";
                    }
                }
            }
            
            std::cout << "]\n";
        }
    }
}