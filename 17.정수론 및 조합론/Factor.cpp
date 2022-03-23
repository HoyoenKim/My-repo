#include<iostream>

using namespace std;

int main () {

    int n;

    cin >> n;

    int min = -1;

    int max = -1;

    for(int i = 0 ; i < n ; i++) {

        int x;

        cin >> x;

        

        if(i == 0) {

            min = x;

            max = x;

        }

        

        if(x < min){

            min = x;

        }

        if(x > max){

            max = x;

        }

    }

    cout << min*max << "\n";

}

