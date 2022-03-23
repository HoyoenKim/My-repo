#include <iostream>
#include <vector>

int n, m;
std::vector<int> array(9, 0);
std::vector<int> flag(9, 0);

void print() {
    for(int j = 0 ; j < m ; j++) {
        std::cout << array[j] << " ";
    }
    std::cout << "\n";
}

void set(int i) {
    if(i == m ) {
        print();
    }
    for(int j = 0 ; j < n ; j++) {
        if(!flag[j + 1]) {
            array[i] = j + 1;
            flag[j + 1] = 1;
            set(i + 1);
            flag[j + 1] = 0;
        }
    }
}

int main() {
    std::cin >> n >> m;
    set(0);
}