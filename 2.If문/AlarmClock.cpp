#include <iostream>

int main() {
    int H, M;
    std::cin >> H >> M;

    int totalM = H*60 + M;
    if (totalM < 45) {
        totalM += 24*60;
    }

    int retM = totalM - 45;
    std::cout << retM / 60 << " " << retM % 60 << std::endl;
    
    return 0;
}