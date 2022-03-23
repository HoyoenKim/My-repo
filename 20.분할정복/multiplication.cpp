#include <iostream>
#include <string>
#include <cmath>

int A, B, C;


int multiplication(int x, int n) {
    if(n == 0) {
        return x;
    }
    else{
        int square = ((unsigned long long) x * (unsigned long long) x) % C;
        return multiplication(square, n - 1);
    }
}
int main() {    
    std::cin >> A >> B >> C;

    int m = std::log(B) / std::log(2);
    //std::cout << m << "\n";

    unsigned long long ret = 1;
    for(int i = m ; i >= 0 ; i--) {
        if( (B & ((unsigned long long)1 << i)) == ((unsigned long long)1 << i)) {
            //std::cout << i << "\n";
            ret *= (unsigned long long) multiplication(A, i);
            ret %= C;
        }
    }
    
    std::cout << ret << "\n";
}