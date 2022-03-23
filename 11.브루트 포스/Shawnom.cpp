#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int i = 1;
    int count = 0;

    while(1) {
        int j = i;
        int sucess = 0;
        while(j > 1) {
            if(j % 10 == 6) {
                sucess++;
            }
            else {
                sucess = 0;
            }
            if (sucess == 3) {
                count++;
                break;
            }
            j /= 10;
        }
        
        if (count == n) {
            break;
        }
        i++;
    }

    std::cout << i << "\n";
}