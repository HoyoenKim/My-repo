#include <iostream>
#include <vector>
int ccw(std::vector<int> x, std::vector<int> y, std::vector<int> z) {
    int x1 = y[0] - x[0];
    int y1 = y[1] - x[1];
    int x2 = z[0] - x[0];
    int y2 = z[1] - x[1];

    int ret = 1;
    long long value = (long long)x1* (long long)y2 - (long long)x2* (long long)y1;
    
    if(value == 0) {
        ret = 0;
    }
    else if(value < 0) {
        ret = -1;
    }
    
    return ret;
}
int main() {
    std::vector<std::vector<int>> cord(4, std::vector<int>(4, 0));

    for(int i = 0 ; i < 4 ; i++) {
        std::cin >> cord[i][0] >> cord[i][1];
    }

    int x0 = cord[0][0];
    int y0 = cord[0][1];

    int xFlip = 1;
    int yFlip = 1;
    if(cord[1][0] - x0 < 0) {
        xFlip = -1;
    }

    if(cord[1][1] - y0 < 0) {
        yFlip = -1;
    }

    for(int i = 0 ; i < 4 ; i++) {
        cord[i][0] = xFlip * (cord[i][0] - x0);
        cord[i][1] = yFlip * (cord[i][1] - y0);
        //std::cout << cord[i][0] << " " << cord[i][1] << "\n";
    }

    double x;
    double y;
    int isCross = 0;

    int ccw1 = ccw(cord[0], cord[1], cord[2]);
    int ccw2 = ccw(cord[0], cord[1], cord[3]);
    int ccw3 = ccw(cord[2], cord[3], cord[0]);
    int ccw4 = ccw(cord[2], cord[3], cord[1]);

    if(cord[1][0] == 0) {
        if(cord[2][0] == cord[3][0]) {
            if(cord[2][0] == 0) {
                int minY = std::min(cord[2][1], cord[3][1]);
                int maxY = std::max(cord[2][1], cord[3][1]);
                if(minY > cord[1][1]) {

                }
                else if(maxY < 0) {
                    
                }
                else {
                    isCross = 2;
                    if(maxY == 0) {
                        isCross = 1;
                        x = 0;
                        y = 0;
                    }

                    if(minY == cord[1][1]) {
                        isCross = 1;
                        x = 0;
                        y = cord[1][1];
                    }
                }
            }
        }
        else {
            if((ccw1 * ccw2 <= 0) && (ccw3 * ccw4 <= 0)) {
                isCross = 1;
                x = 0;
                double m2 = (double) (cord[2][1] - cord[3][1]) / (double) (cord[2][0] - cord[3][0]);
                y = (double) cord[2][1] - m2 * (double) cord[2][0];
            }
        }
    }
    else {
        double m1 = (double) cord[1][1] / (double) cord[1][0] ; 
        double m2 = (double) (cord[2][1] - cord[3][1]) / (double) (cord[2][0] - cord[3][0]);
        if(cord[2][0] == cord[3][0]) {
            if((ccw1 * ccw2 <= 0) && (ccw3 * ccw4 <= 0)) {
                isCross = 1;
                x = (double) cord[2][0];
                y = m1 * (x - (double)cord[1][0]) + (double)cord[1][1];
            }
        }
        else{    
            if(m1 == m2) {
                if(m2 * (double) cord[2][0] == (double) cord[2][1]) {
                    int minX = std::min(cord[2][0], cord[3][0]);
                    int maxX = std::max(cord[2][0], cord[3][0]);
                    if(minX > cord[1][0]) {

                    }
                    else if(maxX < 0) {

                    }
                    else {
                        isCross = 2;
                        if(maxX == 0) {
                            isCross = 1;
                            x = 0;
                            y = 0;
                        }

                        if(minX == cord[1][0]) {
                            isCross = 1;
                            x = cord[1][0];
                            y = cord[1][1];
                        }
                    }
                }
                
            }
            else {
                if((ccw1 * ccw2 <= 0) && (ccw3 * ccw4 <= 0)) {
                    isCross = 1;
                    x = (m2*(double)cord[2][0] - (double)cord[2][1]) / (m2 -m1);
                    y = (m1*m2*(double)cord[2][0] - m1*(double)cord[2][1]) / (m2 - m1);
                }
            }
        }
    }

    if(isCross > 0) {
        std::cout << 1 << "\n";
        if(isCross == 1) {
            x = xFlip * x + (double) x0;
            y = yFlip * y + (double) y0;

            std::cout << std::fixed;
            std::cout.precision(10);
            std::cout << x << " " << y << "\n";
        }
    }
    else {
        std::cout << 0 << "\n";
    }
}