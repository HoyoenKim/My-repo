#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string s1;
    std::string s2;
    std::cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    std::vector<std::vector<int>> array(n, std::vector<int>(m, 0));

    int max = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(s1[i] == s2[j]) {
                if(i == 0 || j == 0) {
                    array[i][j] = 1;
                }
                else{
                    array[i][j] = array[i - 1][j - 1] + 1;
                }
            }
            else {
                if(i == 0 || j == 0) {
                    if(i == 0 && j == 0) {
                    
                    }
                    else if(i == 0) {
                        array[i][j] = array[i][j - 1];
                    }
                    else {
                        array[i][j] = array[i - 1][j];
                    }
                }
                else {
                    array[i][j] = std::max(array[i - 1][j], array[i][j - 1]);
                }
            }
            if(array[i][j] > max) {
                max = array[i][j];
            }
        }
    }

    std::cout << max << "\n";
}