#include <iostream>
#include <vector>
#include <string>

int main() {
    int h, w;
    std::cin >> h >> w;
    std::vector<char> chessboard(h*w);

    for(int i = 0 ; i < h ; i++) {
        std::string temp;
        std::cin >> temp;
        for(int j = 0 ; j < w ; j++) {
            chessboard[i*w + j] = temp[j];
        }
    }
    int minCount = 64;

    for(int i = 0 ; i <= h - 8 ; i++) {
        for(int j = 0 ; j <= w - 8 ; j++) {
            int count1 = 0;
            int count2 = 0;
            for(int x = i ; x < i + 8; x++) {
                for(int y = j ;  y < j + 8; y++) {
                    if( (x-i) % 2 == 0 && (y-j) % 2 == 0 && chessboard[x*w + y] != 'W') {
                        count1++;
                    }
                    if( (x-i) % 2 == 0 && (y-j) % 2 == 1 && chessboard[x*w + y] != 'B') {
                        count1++;
                    }
                    if( (x-i) % 2 == 1 && (y-j) % 2 == 0 && chessboard[x*w + y] != 'B') {
                        count1++;
                    }
                    if( (x-i) % 2 == 1 && (y-j) % 2 == 1 && chessboard[x*w + y] != 'W') {
                        count1++;
                    }

                    if( (x-i) % 2 == 0 && (y-j) % 2 == 0 && chessboard[x*w + y] != 'B') {
                        count2++;
                    }
                    if( (x-i) % 2 == 0 && (y-j) % 2 == 1 && chessboard[x*w + y] != 'W') {
                        count2++;
                    }
                    if( (x-i) % 2 == 1 && (y-j) % 2 == 0 && chessboard[x*w + y] != 'W') {
                        count2++;
                    }
                    if( (x-i) % 2 == 1 && (y-j) % 2 == 1 && chessboard[x*w + y] != 'B') {
                        count2++;
                    }
                }
            }
            if (count1 < minCount) {
                minCount = count1;
            }
            if (count2 < minCount) {
                minCount = count2;
            }
        }
    }

    std::cout << minCount << "\n";
}