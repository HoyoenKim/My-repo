#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include <algorithm>

using namespace std;
const long double PI = std::acos(-1.L);

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

    std::string num1;
    std::string num2;
    std::cin >> num1 >> num2;
    
    int n = num1.length();
    int m = num2.length();
    unsigned long long np = 1;
    for (; np < 2*std::max(n, m)-1; np *= 2);
 
    std::vector<std::complex<long double>> n1(np, 0), n2(np, 0);
    int j = 1;
    int temp = 0;
    int factor = 1;
    int count = 0;
    for(int i = num1.length() - 1 ; i >= 0 ; i--) {
        temp += factor*(num1[i] - '0');
        factor *= 10;
        j += 1;

        if(j % 6 == 0) {
            n1[count] = temp;
            count += 1;
            temp = 0;
            factor = 1;
            j = 1;
        }
    }
    if(temp > 0) {
        n1[count] = temp;
    }

    temp = 0;
    factor = 1;
    j = 1;
    count = 0;
    for(int i = num2.length() - 1 ; i >= 0 ; i--) {
        temp += factor*(num2[i] - '0');
        factor *= 10;
        j += 1;

        if(j % 6 == 0) {
            n2[count] = temp;
            count += 1;
            temp = 0;
            factor = 1;
            j = 1;
        }
    }
    if(temp > 0) {
        n2[count] = temp;
    }

    convolution(n1, n2);

    unsigned long long upper = 0;    
    std::string answer;
    for(int i = 0 ; i < n1.size() ; i++) {
        int num = ((unsigned long long) std::round(n1[i].real()) + upper) % 100000;
        upper = ((unsigned long long) std::round(n1[i].real()) + upper) / (unsigned long long) 100000;

        std::string numStr = std::to_string(num);
        while (numStr.length() < 5) {
            numStr = "0" + numStr;
        }
        std::reverse(numStr.begin(), numStr.end());
        answer += numStr;
    }

    int start = 0;
    for(int i = answer.size() - 1 ; i >= 0 ; i--) {
        if(answer[i] != '0') {
            start = i;
            break;
        }
    }

    for(int i = start ; i >= 0 ; i--) {
        std::cout << answer[i];
    }
    std::cout << "\n";
}