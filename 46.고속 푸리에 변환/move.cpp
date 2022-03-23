#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
const double PI = acos(-1);

inline unsigned bitreverse(const unsigned n, const unsigned k) {
    unsigned r, i;
    for (r = 0, i = 0; i < k; ++i)
        r |= ((n >> i) & 1) << (k - i - 1);
    return r;
}
void fft(std::vector<std::complex<double>> &a, bool is_reverse = false) {
    /* 
    고려하는 수열의 길이는 유한한 자연수 N이다.

    1. 임의의 복소수 수열 a(n), b(n)에 대해서 내적은 다음과 같이 정의된다. (a*) is complex conjucation of a.
    a * b = a[0] * (b[0]*) + ... + a[N - 1] * (b[N - 1]*) = sigma(k, 0, N - 1) (a[k] * (b[k]*)) 이 된다.

    2. 복소수 수열 w_k = (n, 0, N -1) {exp(2*pi*n*k/N)} 에 대해서, w_k * w_l = 0 (k != l), w_k * w_k = N 이 된다. 이는 basis로 사용 가능하다.

    3. 이산 푸리에 변환
    임의의 복소수 수열 A(n)은 w_k[n] = exp(2*pi*k*n/N)를 basis로 이용해 적당한 복소수 수열 a(n)으로 표현이 가능하다.
    
    A[n] = a[0] * w_0[n] + a[1] * w_1[n] + ... + a[N - 1] * w_N-1[n]
         = sigma(k, 0, N - 1) a[k]*w_k[n]    
    
    -> 이런식으로 a를 이용해 A를 구할 경우 O(N^2)의 시간복잡도를 가지게 된다.
    
    4. 이산 푸리에 역변환
    Since, w_i * w_j = 0, we can pick a[n] by multiply w_n each side.
    a[n] = (1/N) * sigma(k, 0, N - 1) A[k]*w_N[n]^(-k)

    1. 이산 푸리에 변환, 분할 정복을 이용한 최적화(Cooley-Tukey) 
    N = 2^k인 경우에 대해서 이산 푸리에 변환을 최적화 할 수 있다.
    
    A[n] = sigma(k, 0, N - 1) a[k] * w_N[n]^k
    A[n] =   (a[0] + a[2] * w_N[n]^2 + ... + a[N - 2] * w_N[n]^(N - 2))
           + (a[1] + a[3] * w_N[n]^2 + ... + a[N - 1] * w_N[n]^(N - 2)) * w_N[n]

         = sigma(k, 0, N/2 - 1) (a[2*k] * W_N[n]^2k) + w_N[n] * sigma(k, 0, N/2 - 1) (a[2*k + 1] * W_N[n]^2k)
    
    Assume aEven[k] = a[2*k], aOdd[k] = a[2*k + 1], W_N/2[n] = W_N[n]^2 = exp(2 * pi * n / (N/2))

         = sigma(k, 0 , N/2 - 1) (aEven[k] * W_N/2[n]^k) + w_N[n] * sigma(k, 0, N/2 - 1) (aOdd[k] * W_N/2[n]^k)

    -> A[n] = Aeven[n] + w[n] * Aodd[n] (n <= N/2) 
       A[n] = Aeven[n] - w[n] * Aood[n] (n > N/2)

    -> 따라서 이런 식으로 길이 N/2 짜리 Aeven, Aodd를 구해서 재귀적으로 더해주면 된다. 
    
    2. 재귀 코드
    void fftRecursion(std::vector<std::complex<double>> &a) {
        unsigned long long N = a.size();
        if (N == 1){
            return a;
        }
        else {
            std::vector<std::complex<double>> aEven;
            std::vector<std::complex<double>> aOdd;
            std::vector<std::complex<double> wN;
            
            for(int i = 0 ; i < N ; i++) {
                if(i % 2 == 0) {
                    aEven.push_back(a[i]);
                }
                else {
                    aOdd.push_back(a[i]);
                }
                double t = i*(2*PI/N);
                std::complex<double> wNn(cos(t), sin(t));
                wN.push_back(wNn);
            }

            for(int i = 0 ; i < N / 2 ; i++) {
                a[i] = aEven[i] + wN[i] * aOdd[i];
                a[i + N/2] = aEven[i] - wN[i] * aOdd[i];
            }
        }
    }

    3. 재귀 없애기
    하지만 재귀를 사용하게 되면 메모리 할당이 반복되므로 문제가 생긴다.
    
    A8을 예를 들어 보면 아래와 같이 재귀 함수의 메모리가 할당되게 된다.
    a0 a1 a2 a3 a4 a5 a6 a7
    -> a0 a2 a4 a6 / a1 a3 a5 a7
    -> a0 a4 / a2 a6 / a1 a5 / a3 a7

    그냥 처음부터 a0 a4 a2 a6 a1 a5 a3 a7 의 순서대로 더하면 되지 않을까?
    -> {0, 1, 2, 3, 4, 5, 6, 7 (2^3 - 1)} -> {0, 4, 2, 6, 1, 5, 3, 7} 로의 변환 함수를 찾아보자.
    000 -> 000
    001 -> 100
    010 -> 010
    011 -> 110
    100 -> 001
    101 -> 010
    111 -> 111

    즉, 2진수로 변환했을 때 비트를 뒤집은 위치로 변환하는 것을 알 수 있다. n에 대해서 하위 k (= log(n)/log(2)) 개의 비트를 뒤집으면 된다. 
    이는 i번째 비트를 1로 보내고 k - i - 1 만큼 왼쪽으로 밀면 된다.

    이제 길이가 2, 4, ..., 2^k 까지의 W_2^k를 구해서 앞에서부터 곱한 뒤 2^k-1 개씩 더해주는 것을 반복한다.*/
    
    unsigned long long N = a.size();
    unsigned long long k = __builtin_ctz(N);

    for(unsigned long long i = 0 ; i < N ; i++) {
        unsigned j = bitreverse(i, k);
        if(i < j) {
            swap(a[i], a[j]);
        }
    }

    for(unsigned long long l = 2; l <= N ; l *= 2) {
        double t = 2 * PI / l;
        if(is_reverse) {
            t *= -1;
        }
        std::complex<double> wt(std::cos(t), std::sin(t));
        for(unsigned long long i = 0; i < N ; i += l) {
            std::complex<double> w(1);
            for(unsigned long long j = 0 ; j < l/2 ; j++) {
                std::complex<double> tmp = a[i + j + l/2] * w;
                a[i + j + l/2] = a[i + j] - tmp;
                a[i + j] += tmp;
                w *= wt;
            }
        }
    }

    if(is_reverse) {
        for(int i = 0 ; i < N ; i++) {
            a[i] /= N;
        }
    }
}

void convolution(std::vector<std::complex<double>> &a, std::vector<std::complex<double>> &b) {
    /*
        N = 2^k가 아닌 경우에는 fft를 한 방에 구할 수는 없다. N - 1에 대해서 N에 대한 fft를 구하는 알고리즘을 만든 뒤, N을 2^k의 합으로 분할해서 구한다. 
        하지만, convoultion은 빠르게 구할 수 있다.
        
        F(c)(n) = F(a)(n) * F(b)(n)
                = sigma(k, 0, N - 1) (a[k] * w_N[n]^k) sigma(l, 0, N - 1) (b[l] * w_N[n]^l)
                = sigma(k, 0, N - 1) sigma(l, 0, N - 1) (a[k] * b[l] * w_N[n]^(k + l))
                = sigma(k, 0, N - 1) c[k] * w_N[n]^k
        (where c[k] = sigma(l, 0, N - 1) a[l]b[k - l]) -> conv(a, b) = sigma(k, 0, N - 1) (a[k]*b[N - k])

        Let k such that min(N`: N` > 2 * N with N` = 2^k) and a`, b` below.
        a` = {a[0], a[1], ... , a[N - 1], 0, ... (N` - N times) ... 0}
        b` = {b[0], b[1], ... , b[N - 1], 0, ... (N` - 2*N times) ... 0, b[0], b[1], ... b[N - 1]}
        
        Then conv(a`, b`) = conv(a, b)
        (사실 b` 앞의 N개는 0이여도 되는데, resize를 해서 늘리기 때문에 그냥 이렇게 둔다.)
    */

    unsigned long long N = a.size();
    unsigned long long N0 = N;
    if(N != 0 && N != 1) {
        int k = std::log(2*N) / std::log(2);
        N0 = std::pow(2, k + 1);
        a.resize(N0);
        b.resize(N0);
        for(unsigned long long i = 0 ; i < N ; i++) {
            b[N0 - N + i] = b[i];
        }
    }

    fft(a); // F(a)
    fft(b); // F(b)

    for(unsigned long long i = 0 ; i < N0 ; i++) {
        a[i] *= b[i]; // F(a) * F(b) = F(c)
    }
    fft(a, true); // F-1(F(c))

    a.resize(N);
    b.resize(N);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::complex<double>> a(n);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> a[i];
    }

    std::vector<std::complex<double>> b(n);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> b[n - i - 1];
    }

    convolution(a, b);

    int answer = 0;
    for(int i = 0 ; i < n ; i++) {
        double num = a[i].real();
        int candid;
        if(num > 0) {
            candid = (int) (a[i].real() + 0.5);
        }
        else {
            candid = (int) (a[i].real() - 0.5);
        }
        
        answer = std::max(answer, candid);
    }

    std::cout << answer << "\n";
}