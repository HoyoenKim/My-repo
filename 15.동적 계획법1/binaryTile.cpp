#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    int bbefore = 1;
    int before = 2;
    int now = 0;

    for(int i = 0 ; i < n ; i++) {
        if (i == 0) {
            now = bbefore;
        }
        else if(i == 1) {
            now = before;
        }
        else {
            now = (before + bbefore) % 15746;
            bbefore = before;
            before = now;
        }
    }

    std::cout << now << "\n";
}