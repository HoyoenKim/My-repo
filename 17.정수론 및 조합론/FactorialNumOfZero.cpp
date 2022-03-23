#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int numOf2 = 0;
    int numOf5 = 0;
    for(int i = 1 ; i <= n ; i++) {
        int j = i;
        while(j > 0) {
            if(j % 2 == 0) {
                numOf2++;
                j /= 2;
            }
            else {
                break;
            }
        }

        j = i;
        while(j > 0) {
            if(j % 5 == 0) {
                numOf5++;
                j /= 5;
            }
            else {
                break;
            }
        }
    }
    if(numOf2 > numOf5) {
        std::cout << numOf5 << "\n";
    } 
    else {
        std::cout << numOf2 << "\n";
    }
}