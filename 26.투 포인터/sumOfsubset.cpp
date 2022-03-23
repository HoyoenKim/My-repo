#include <iostream>
#include <vector>

std::vector<int> set;
int count = 0;
int n, s;

std::vector<int> flag;
void findCount(int beforeIndex, int beforeSum) {
    for(int i = beforeIndex ; i < n ; i++) {
        if(flag[i] == 0) {
            if(beforeSum + set[i] == s) {
                count++;
            }
            flag[i] = 1;
            findCount(i, beforeSum + set[i]);
            flag[i] = 0;
        }
    }
}

int main() {
    std::cin >> n >> s;    
    for(int i = 0 ; i < n ; i++) {
        int num;
        std::cin >> num;
        set.push_back(num);
        flag.push_back(0);
    }
    findCount(0, 0);
    std::cout << count << "\n";
}