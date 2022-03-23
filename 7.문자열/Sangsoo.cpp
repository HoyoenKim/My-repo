#include <iostream>
#include <string>
#include <algorithm>

int reverseNum(int n) {
    return (n % 10) * 100 + ((n / 10) % 10) * 10 + n / 100;
}
int main() {

    /*
    int A, B;
    std::cin >> A >> B;

    A = reverseNum(A);
    B = reverseNum(B);  
    
    if (A > B) {
        std::cout << A << "\n";
    }
    else {
        std::cout << B << "\n";
    }
    */

    std::string A, B;
    std::cin >> A >> B;

    std::reverse(A.begin(), A.end());
    int a = std::stoi(A);

    std::reverse(B.begin(), B.end());
    int b = std::stoi(B);

    if (a > b) {
        std::cout << a << "\n";
    }
    else {
        std::cout << b << "\n";
    }
}