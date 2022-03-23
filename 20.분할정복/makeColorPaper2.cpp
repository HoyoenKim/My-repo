#include <iostream>
#include <vector>
#include <string>

int paper[128][128];
int white = 0;
int black = 0;
std::string retStr = "";

void checkPaper(int startX, int endX, int startY, int endY) {
    //std::cout << "??? : " << startX << " " << endX << " " << startY << " " << endY << "\n";

    int color = 0;
    if(paper[startX][startY] == 1) {
        color = 1;
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
        if(color) {
            black++;
            retStr += "1";
        }
        else {
            white++;
            retStr += "0";
        }
    }
    else {
        int x = (endX - startX) / 2;
        int y = (endY - startY) / 2;

        retStr += "(";
        checkPaper(startX, startX + x, startY, startY + y);
        checkPaper(startX, startX + x, startY + y, endY);
        checkPaper(startX + x, endX, startY, startY + y);   
        checkPaper(startX + x, endX, startY + y, endY);
        retStr += ")";
    }
}

int main() {
    int n;
    std::cin >> n;

    for(int i = 0 ; i < n ; i++) {
        std::string temp;
        std::cin >> temp;
        for(int j = 0 ; j < n ; j++) {
            paper[i][j] = temp[j] - '0';
        }
    }
    
    //std::cout << "\n";
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            //std::cout << paper[i][j];
        }
        //std::cout << "\n";
    }
    
    checkPaper(0, n, 0, n);
    //std::cout << white << "\n" << black << "\n";
    std::cout << retStr << "\n";

    return 0;
}