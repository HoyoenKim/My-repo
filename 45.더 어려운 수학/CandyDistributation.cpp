#include<iostream>

long long extendedGcd(long long a, long long b){
    long long temp = a;
    long long t1 = 0;
    long long t2 = 1;
    long long Q, R, t;

    while(b != 0) {
        Q = a / b;
        R = a % b;

        a = b;
        b = R;

        t = t1 - Q *t2;
        
        t1 = t2;
        t2 = t;
    }

    while(t1 < 0) {
        t1 += temp;
    }

    return t1;
}

long long  gcd(long long a, long long b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int t;
    std::cin >> t;
    while(t > 0) {
        t--;
        long long k, c;
        std::cin >> k >> c;
        if (c == 1) {
            if (k < 1e9) {
                std::cout << k + 1 << "\n";
            }
            else {
                std::cout << "IMPOSSIBLE\n";
            }
        }
        else if(k == 1) {
            std::cout << "1\n";
        }
        else if(gcd(k, c) != 1) {
            std::cout << "IMPOSSIBLE\n";
        }
        else {
            int answer = extendedGcd(k, c);
            if(answer > 1e9) {
                std::cout << "IMPOSSIBLE\n";
            } 
            else {
                std::cout << answer << "\n";
            }
        }
    }
}