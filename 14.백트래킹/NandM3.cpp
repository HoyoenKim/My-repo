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
    else {
        for(int j = 0 ; j < n ; j++) {
            array[i] = j + 1;
            set(i + 1);
        }
    }
}

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    set(0);
}