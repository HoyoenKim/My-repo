#include <iostream>
#define NUM 10000
int selfNumber(int N) {
    int selfNum = N;

    while(1) {
        selfNum += N%10;
        if ( N / 10 == 0) {
            break;
        }
        N /= 10;
    }

    return selfNum;
}

int main() {
    char a[NUM] = "";

    for(int i = 1 ; i <= NUM ; i ++) {
        int selfNum = selfNumber(i);
        if (selfNum <= NUM) {
            a[selfNum - 1] = 1;
        }
    }

    for(int i = 0 ; i < NUM ; i++) {
        if(a[i] == 0) {
            std::cout << i + 1 << "\n";
        }
    }
    
    return 0;
}