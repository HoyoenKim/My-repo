#include<iostream>

using namespace std;

int main () {

    int n;

    cin >> n;

    

    for (int i = 0 ; i < n ; i++) {

    int x, y;

    cin >> x >> y;

    

    int x1 = x;

    int y1 = y;

    

    while(1) {

        int temp = x1 % y1;

        x1 = y1;

        y1 = temp;

        

        if(y1 == 0) {

            break;

        }

    }

    

    cout << (x / x1) * y << "\n";

    }

}

