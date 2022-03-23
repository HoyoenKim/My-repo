#include <iostream>
#include <vector>

std::vector<int> isSum(8000000, 0);

std::vector<int> setA;
std::vector<int> setB;

std::vector<int> flagA;
std::vector<int> flagB;

unsigned long long count = 0;
int n, s;

int setASize, setBSize;

void findCountA(int beforeIndex, int beforeSum) {

    for(int i = beforeIndex ; i < setASize ; i++) {
        if(flagA[i] == 0) {
            isSum[4000000 + beforeSum + setA[i]] += 1;
            if(beforeSum + setA[i] == s) {
                count += 1;
            }
            flagA[i] = 1;
            findCountA(i, beforeSum + setA[i]);
            flagA[i] = 0;
        }
    }
}

void findCountB(int beforeIndex, int beforeSum) {

    for(int i = beforeIndex ; i < setBSize ; i++) {
        if(flagB[i] == 0) {
            count += isSum[4000000 + s - (beforeSum + setB[i])];
            if(beforeSum + setB[i] == s) {
                count += 1;
            }
            flagB[i] = 1;
            findCountB(i, beforeSum + setB[i]);
            flagB[i] = 0;
        }
    }
}


int main() {
    std::cin >> n >> s;    
    
    for(int i = 0 ; i < n / 2 ; i++) {
        int num;
        std::cin >> num;
        setA.push_back(num);
        flagA.push_back(0);
    }
    setASize = setA.size();

    for(int i = n / 2 ; i < n ; i++) {
        int num;
        std::cin >> num;
        setB.push_back(num);
        flagB.push_back(0);
    }
    setBSize = setB.size();

    findCountA(0, 0);
    findCountB(0, 0);
    std::cout << count << "\n";
}