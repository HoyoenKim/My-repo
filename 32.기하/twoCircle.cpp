#include <iostream>
#include <cmath>

double area(double r, double theta) {
    return r*r*(theta -std::cos(theta)*std::sin(theta));
}

int main() {
    double x1, y1, r1, x2, y2, r2;
    std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    if(r2 > r1) {
        double temp = r2;
        r2 = r1;
        r1 = temp;

        temp = x2;
        x2 = x1;
        x1 = temp;

        temp = y2;
        y2 = y1;
        y1 = temp;
    }

    //to convert (0,0) r1, (x2, 0) r2.
    x2 = x2 - x1;
    y2 = y2 - y1;
    x1 = 0;
    y1 = 0;

    x2 = std::sqrt(x2*x2 + y2*y2);
    y2 = 0;

    //std::cout << r1 << " " << r2 << " " << x2 << "\n"; 
    double a;
    if(r1 + r2 <= x2) {
        // no intersection.
        a = 0;
    }
    else if(r1 - r2 >= x2) {
        // all intersection.
        a = r2*r2*M_PI;
    }
    else {
        // find intersetion.
        double x = (r1*r1 - r2*r2 + x2*x2)/(2*x2);

        // find theta.
        double theta1 = std::acos(x / r1);
        double theta2 = std::acos((x2 - x) / r2);

        a = area(r1, theta1) + area(r2, theta2);
    }

    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << std::round(a*1000)/1000 << "\n";
}