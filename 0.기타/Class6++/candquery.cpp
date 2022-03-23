#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int p = 1000000007;
    int nmax = 4000000;

    vector<long long> f(nmax + 1, 1);
    for(long long i = 1 ; i <= nmax ; i++) {
        f[i] = (i * f[i - 1]) % p;
    }

    // x^(p - 2) == x^(-1) (mod p)
    // (x*y)^(p - 2) * y == x^(p - 2) (mod p) 
    long long inv = 1;
    long long temp = f[nmax];
    for(int i = 0 ; i < 32 ; i++) {
        if((((p - 2) >> i) & 1) == 1) {
            inv *= temp;
            inv %= p;
        }
        temp *= temp;
        temp %= p;
    }
    vector<long long> invf(nmax + 1, 1);
    invf[nmax] = inv;
    for(long long i = nmax - 1 ; i >= 0 ; i--) {
        invf[i] = ((i + 1) * invf[i + 1]) % p;
    }

    int m;
    cin >> m;
    while(m--) {
        int n, k;
        cin >> n >> k;
        long long ret = f[n];
        ret *= invf[n - k];
        ret %= p;
        ret *= invf[k];
        ret %= p;

        cout << ret << "\n";
    }

}