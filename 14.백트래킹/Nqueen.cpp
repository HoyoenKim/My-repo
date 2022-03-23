#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> pos(15, 0);
int count = 0;
int n = 0;
bool isPossible (int i) {
    for(int j = 0 ; j < i ; j++) {
        if(pos[j] == pos[i] || std::abs(i - j) == std::abs(pos[i] - pos[j]) ) {
            return false;
        }
    }
    return true;
}

void takeQueen (int i) {
    if(i == n) {
        count++;
    }
    else {
        for(int j = 0 ; j < n ; j++) {
            pos[i] = j;
            if(isPossible(i)) {
                takeQueen(i + 1);
            }
        }
    }
}

int main() {
    std::cin >> n;
    takeQueen(0);
    std::cout << count << "\n";
}