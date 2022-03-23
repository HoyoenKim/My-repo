#include <iostream>

int main() {
    while(1) {
        int A, B, C;
        std::cin >> A >> B >> C;
        if (A == 0 && B == 0 && C == 0) {
            break;
        }
        int a, b, c;
        if(A > B && A > C) {
            c = A;
            b = B;
            a = C;
        }
        else if(B > A && B > C) {
            c = B;
            b = C;
            a = A;
        }
        else {
            c = C;
            b = B;
            a = A;
        }
        if(c*c == a*a + b*b) {
            std::cout << "right\n";
        }
        else {
            std::cout << "wrong\n";
        }
    }
}