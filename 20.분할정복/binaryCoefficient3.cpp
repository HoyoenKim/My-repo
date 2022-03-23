#include <iostream>
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
    int n, k;
    std::cin >> n >> k;
    
    int p = 1000000007;

    unsigned long long ret1 = 1;
    unsigned long long ret2 = 1;
    for(int i = n ; i >= n - k + 1 ; i--) {
        ret1 *= (unsigned long long) i;
        ret1 %= p;

        ret2 *= (unsigned long long) (n + 1 - i);
        ret2 %= p;
    }
    
    A = ret2;
    B = p - 2;
    C = p;

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

    std::cout << (ret1 * ret) % p << "\n";
}