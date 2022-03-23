#include <iostream>
#include <vector>
int main() {
    int N;
    std::cin >> N;
    for(int j = 0 ; j < N ; j++) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> array(41, std::vector<int>(2, 0));
    
        for(int i = 0 ; i <= n ; i++) {
            if(i == 0) {
                array[i][0] = 1;
                array[i][1] = 0;
            }
            else if(i == 1) {
                array[i][0] = 0;
                array[i][1] = 1;
            }
            else {
                array[i][0] = array[i - 1][0] + array[i - 2][0];
                array[i][1] = array[i - 1][1] + array[i - 2][1];
            }
        }
    
        std::cout << array[n][0] << " " << array[n][1] << "\n";
    }
    

}