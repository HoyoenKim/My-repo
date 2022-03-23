#include<iostream>

using namespace std;

int main () {

    int n, k;

    cin >> n >> k;

    

    int ret = 1;

    for(int i = 0 ; i < k ; i++) {

        ret *= (n - i);

    }

    

    for(int i = 0 ; i < k ; i++) {

        ret /= (k - i);

    }

    

    cout << ret << "\n";

}

