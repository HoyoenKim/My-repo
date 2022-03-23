#include <iostream>
#include <vector>

std::vector<std::vector<int>> ablity(20, std::vector<int>(20, 0));
std::vector<int> start(10, 0);
std::vector<int> link(10, 0);
int min = 0;
int isFirst = 0;
int n = 0;

int getScore(std::vector<int> array, int i) {
    int score = 0;
    for(int j = 0 ; j < i ; j++) {
        for(int k = j + 1; k < i ; k++) {
            //std::cout << array[j] << array[k] << " "; 
            score += ablity[array[j] - 1][array[k] - 1] +  ablity[array[k] - 1][array[j] - 1];
        }
    }
    //std::cout << "\n" << score << "\n";
    return score;
}

void seperate(int i) {
    if(i == n / 2) {
        //std::cout << "Hello" << "\n";
        std::vector<int> exist(n + 1, 0);
        for(int j = 0 ; j < i ; j++) {
            //std::cout << start[j] << " ";
            exist[start[j]] = 1;
        }
        //std::cout << "\n";
        int k = 0;
        for(int j = 1 ; j <= n ; j++) {
            if(exist[j] == 0) {
                link[k] = j;
                //std::cout << j << " ";
                k++;
            }
        }
        //std::cout << "\n";
        int startScore = getScore(start, i);
        int linkScore = getScore(link, i);

        if(isFirst == 0) {
            isFirst = 1;
            min = std::abs(startScore - linkScore);
        }
        else {
            int diff = std::abs(startScore - linkScore);
            if(diff < min) {
                min = diff;
            }
        }
    }
    else {
        for(int j = 1 ; j <= n ; j++) {
            if(i == 0) {
                if(j == 1) {
                    start[i] = j;
                    seperate(i + 1);
                }
                
            }
            else {
                if(start[i - 1] < j) {
                    start[i] = j;
                    seperate(i + 1);
                    start[i] = 0;
                }
            }
        }
    }
}

int main() {
    std::cin >> n;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            std::cin >> ablity[i][j];
        }
    }
    seperate(0);
    std::cout << min << "\n";
}