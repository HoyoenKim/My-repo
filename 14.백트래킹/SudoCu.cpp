#include <iostream>
#include <vector>

std::vector<int> array(81);
std::vector<int> solveIndex;

bool isPossible(int i, int tryNum) {

    int row = i / 9;
    int column = i % 9;
    for(int j = 0 ; j < 9 ; j++) {
        //vertical
        if(j * 9 + column != i && array[j * 9 + column] == tryNum) {
            return false;
        }
    }

    for(int k = 0 ; k < 9 ; k++) {
        //horizental
        if(row * 9 + k != i && array[row * 9 + k] == tryNum) {
            return false;
        }
    }

    for(int l = 0 ; l < 9 ; l++) {
        //Box
        if (i != ( (row / 3) * 3 + l / 3) * 9 + (column / 3) * 3 + l % 3 && array[( (row / 3) * 3 + l / 3) * 9 + (column / 3) * 3 + l % 3] == tryNum) {
            return false;
        }
    }

    return true;
}
int solveEnd = 0;
void solveSudoCu(int n) {
    if(n == solveIndex.size()) {
        std::cout << "\n";
        if(solveEnd == 0) {
            for(int i = 0 ; i < 81 ; i++) {
                std::cout << array[i] << " ";
                if((i + 1) % 9 == 0) {
                    std::cout << "\n";
                }
            }
        }
        solveEnd = 1;
    }
    else {
        for(int j = 1 ; j <= 9 ; j++) {
            if(solveEnd == 1) {
                break;
            }
            if(isPossible(solveIndex[n], j)) {
                array[solveIndex[n]] = j;
                solveSudoCu(n + 1);
                array[solveIndex[n]] = 0;
            }
        }
    }
}

int main() {
    for(int i = 0 ; i < 81 ; i++) {
        std::cin >> array[i];
        if(array[i] == 0) {
            solveIndex.push_back(i);
        }
    }

    solveSudoCu(0);
}