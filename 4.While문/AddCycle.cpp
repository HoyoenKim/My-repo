#include <iostream>

int add(int N) {
    if (N < 10) {
        return N * 10 + N;
    }
    else {
        return (N % 10) * 10 + (N / 10 + N % 10) % 10;
    }
}

int main() {
    int N;
    std::cin >> N;

    int newN = add(N); 
    int i = 1;
    while(1) {
        if(newN == N) {
            break;
        }
        newN = add(newN);
        i ++;
    }
    std::cout << i << "\n";
}