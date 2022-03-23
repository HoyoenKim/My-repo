#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x, y, d, t;
    cin >> x >> y >> d >> t;

    double minlength = sqrt(x * x + y * y);

    int k = minlength / d;

    double candid = minlength;
    candid = min(candid, minlength - (double) (k * d) + (double) (k * t));
    candid = min(candid, (double) ((k + 1) * d) - minlength + (double) ((k + 1) * t));

    cout.precision(25);
    cout << candid << "\n";
}