#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long gcd (long long a, long long b) {
    if(a % b == 0) {
        return b;
    }
    
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    long long p = 1000000007;
    long long answer = 0;
    for(int i = 0 ; i < n ; i++) {
        int a, b;
        cin >> b >> a;

        long long GCD = gcd(a, b);
        a /= GCD;
        b /= GCD;

        // a * b ^(-1) == a * b^(p - 2) (mod p)
        // since, b^(p-1) == 1 (mod p) 

        int k = 30;
        vector<long long> mt(k + 1, 0);
        for(int i = 0 ; i <= k ; i++) {
            if(i == 0) {
                mt[i] = b;
            }
            else {
                mt[i] = ( mt[i - 1] * mt[i - 1] ) % p;
            }
        }

        long long ret = 1;
        for(int i = 0 ; i <= k ; i++) {
            if(((p - 2) >> i) & 1 == 1) {
                ret *= mt[i];
                ret %= p;
            }
        }
        answer += (a * ret) % p;
        answer %= p;
    }

    cout << answer << "\n";
}