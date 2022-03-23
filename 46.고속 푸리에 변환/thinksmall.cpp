#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>

using namespace std;

const long double PI = acos(-1.L);

unsigned long long bitconvert(unsigned long long  n, unsigned long long  k) {
    unsigned long long  ret = 0;
    for(unsigned long long  i = 0 ; i < k ; ++i) {
        ret |= ( (n >> i) & (unsigned long long) 1 ) << (k - i - (unsigned long long) 1); 
    }
    return ret;
}

void fft(std::vector<std::complex<long double>>&a, bool is_reverse = false) {
    // 0 1 2 3 4 5 6 7
    // 0 2 4 6 1 3 5 7
    // 0 4 2 6 1 5 3 7

    unsigned long long n = a.size();
    unsigned long long k = __builtin_ctz(n);
    for(unsigned long long i = 0 ; i < n ; i++) {
        unsigned long long j = bitconvert(i, k);
        if(i < j) {
            std::complex<long double> temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // 0 1 2 3 4 5 6 7
    // 0 2 4 6 / 1 3 5 7
    // 0 4 / 2 6 / 1 5 / 3 7
    
    // a[n] = aeven[n] + w[n] * aodd[n]
    // a[n + N/2] = aeven[n] - w[n] * odd[n]
    // w[n] = exp(2 pi/ s )
    for(unsigned long long s = 2 ; s <= n ; s *= 2) {
        std::vector<std::complex<long double>> w(s/2);
        for(int i = 0 ; i < s/2 ; i++) {
            long double t = (long double)2 * PI * i / (long double)s;
            if(is_reverse) {
                t *= (long double) -1;
            }
            w[i] = std::complex<long double> (cos(t), sin(t));
        }
        for(unsigned long long i = 0 ; i < n ; i += s) {
            for(unsigned long long j = 0 ; j < s/2 ; j++) {
                std::complex<long double> odd = a[i + j + s/2];
                std::complex<long double> even = a[i + j];
                a[i + j] = even + w[j] * odd;
                a[i + j + s/2] = even - w[j] * odd;
            }
        }
    }

    if(is_reverse) {
        for(unsigned long long  i = 0 ; i < n ; i++) {
            a[i] /= (long double) n;
        }
    }
}

void convolution (std::vector<std::complex<long double>> &a, std::vector<std::complex<long double>> &b) {
    fft(a);
    fft(b);
    for(unsigned long long i = 0 ; i < a.size() ; i++) {
        a[i] *= b[i];
    }
    fft(a, true);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    unsigned long long n, m, np = 1;
    std::cin >> n >> m;

    while(1) {
        if(np >= 2 * std::max(n + 1, m + 1) - 1) {
            break;
        }
        np *= 2;
    }

    std::vector<std::complex<long double>> f(np, 0);
    for(int i = 0 ; i < n + 1; i++) {
        std::cin >> f[i];
    }

    std::vector<std::complex<long double>> g(np, 0);
    for(int i = 0 ; i < m + 1; i++) {
        std::cin >> g[i];
    }

    convolution(f, g);

    unsigned long long res = 0;
    for(unsigned long long i = 0 ; i < n + m + 1 ; i++) {
        res ^= (unsigned long long)(f[i].real() + (f[i].real() > 0? 0.5L : -0.5L));
    }

    std::cout << res << "\n";
}
