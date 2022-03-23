#include <iostream>

int hanoi_move(int N, int start, int middle, int end) {
    if (N == 1) {
        std::cout << start << " " << end << "\n";
        return 1;
    }
    else {
        return hanoi_move(N - 1, start, end, middle) + hanoi_move(1, start, middle, end) + hanoi_move(N - 1, middle, start, end);
    }
}

int hanoi(int N) {
    if (N == 1) {
        return 1;
    }
    else {
        return 2*hanoi(N - 1) + 1;
    }
}

/*
1
1 3

2
1 2
1 3
2 3

3
1 3
1 2
3 2
1 3
2 1
2 3
1 3
*/

int main() {
    int n;
    std::cin >> n;
    std::cout << hanoi(n)  << "\n";
    hanoi_move(n, 1, 2, 3);
}