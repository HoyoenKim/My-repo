#include <iostream>

int paper[2187][2187];

int m1 = 0;
int zero = 0;
int p1 = 0;

void checkPaper(int startX, int endX, int startY, int endY) {
    //std::cout << "??? : " << startX << " " << endX << " " << startY << " " << endY << "\n";

    int color = 0;
    if(paper[startX][startY] == 1) {
        color = 1;
    }

    if(paper[startX][startY] == -1) {
        color = -1;
    }

    int isOnePaper = 1;
    for(int i = startX ; i < endX ; i++) {
        for(int j = startY ; j < endY ; j++) {
            if(paper[i][j] != color) {
                isOnePaper = 0;
                break;
            }
        }
    }

    if(isOnePaper) {
        if(color == 1) {
            p1++;
        }
        else if(color == 0) {
            zero++;         
        }
        else {
            m1++;
        }
    }
    else {
        int x = (endX - startX) / 3;
        int y = (endY - startY) / 3;

        for(int k = 0 ; k < 3 ; k++) {
            for(int l = 0 ; l < 3 ; l++) {
                checkPaper(startX + k * x, startX + (k + 1) * x, startY + l * y, startY + (l + 1) * y);
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            std::cin >> paper[i][j];
        }
    }
    
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            //std::cout << paper[i][j];
        }
        //std::cout << "\n";
    }
    
    checkPaper(0, n, 0, n);
    std::cout << m1 << "\n" << zero << "\n" << p1 << "\n";

    return 0;
}