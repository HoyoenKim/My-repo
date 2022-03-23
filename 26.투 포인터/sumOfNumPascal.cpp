#include <iostream>
#include <vector>
#include <cmath>
#include <string>

int N, F;
std::vector<std::vector<unsigned long long>> c(11, std::vector<unsigned long long>(11, 0));
std::vector<int> ret(10, 0);
int f = 1;

bool valid() {
    std::vector<std::vector<int>> v(N, std::vector<int>(N, 0));
    for(int i = 0 ; i < N ; i++) {
        if(i == 0) {
            for(int j = 0 ; j < N ; j++) {
                v[i][j] = ret[j];
            }
        }
        else {
            for(int j = 0 ; j < N ; j++) {
                v[i][j] = v[i - 1][j] + v[i - 1][j + 1];
            }
        }
    }
    if(v[N - 1][0] == F) {
        return true;
    }
    return false;
}

void find(int count, std::vector<int> &flag) {
    if(count == N) {
        if(valid()) {
            f = 0;
            for(int j = 0 ; j < N ; j++) {
                std::cout << ret[j] << " ";
            }
            std::cout << "\n";
        }
    }
    else{
        for(int i = 1 ; i <= N ; i ++) {
            if(flag[i] == 0 && f == 1) {
                flag[i] = 1;
                ret[count] = i;
                find(count + 1, flag);
                flag[i] = 0;
            }
        }
    }
    
}

int main() {
    std::cin >> N >> F;
    std::vector<int> flag(N + 1, 0);
    find(0, flag);
}