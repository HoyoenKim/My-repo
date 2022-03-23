#include <iostream>
#include <vector>

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> array(n);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i];
    }

    int a = array[0];

    for(int i = 1 ; i < n ; i++) {
        int m;
        if(a > array[i]) {
            m = gcd(a, array[i]);
        }
        else {
            m = gcd(array[i], a);
        }
        std::cout << a / m <<"/" << array[i] / m << "\n";
    }
}