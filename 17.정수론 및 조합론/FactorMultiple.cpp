#include <iostream>
using namespace std;

int main(){
    
    while(1) {
        int x, y;
        cin >> x >> y;
        
        if(x == 0 && y == 0) {
            break;
        }
        
        if(x > y) {
            if (x % y == 0) {
                cout << "multiple\n";
            }
            else {
                cout << "neither\n";
            }
        }
        else {
            if (y % x == 0) {
                cout << "factor\n";
            }
            else {
                cout << "neither\n";
            }
        }
    }

    return 0;
}
