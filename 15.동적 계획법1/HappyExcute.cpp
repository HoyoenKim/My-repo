#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<vector<int>>> array(21, vector<vector<int>>(21, vector<int>(21, 0)));
    for(int i = 0 ; i <= 20 ; i++) {
        for(int j = 0 ; j <= 20 ; j++) {
            for(int k = 0 ; k <= 20 ; k++) {
                if(i == 0 || j == 0 || k == 0) {
                    array[i][j][k] = 1;
                }
                else if(i < j && j < k) {
                    array[i][j][k] = array[i][j][k - 1] + array[i][j - 1][k - 1] - array[i][j - 1][k];
                }
                else {
                    array[i][j][k] = array[i - 1][j][k] + array[i - 1][j - 1][k] + array[i - 1][j][k - 1] - array[i - 1][j - 1][k - 1];
                }
            }
        }
    }

    while(1) {
        vector<int> num(3, 0);
        for(int i = 0 ; i < 3 ; i++) {
            cin >> num[i];
        }

        int isEnd = 1;
        for(int i = 0 ; i < 3 ; i++) {
            isEnd &= (num[i] == -1);
        }

        if(isEnd) {
            break;
        }

        std::cout << "w(" << num[0] << ", " << num[1] << ", " << num[2] << ") = ";
        if(num[0] <= 0 || num[1] <= 0 || num[2] <= 0) {
            std::cout << 1 << "\n";
        }
        else if(num[0] > 20 || num[1] > 20 || num[2] > 20) {
            std::cout << array[20][20][20] << "\n";
        }
        else {
            std::cout << array[num[0]][num[1]][num[2]] << "\n";
        }
    }
}