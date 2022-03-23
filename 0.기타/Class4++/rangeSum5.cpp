#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> array(n + 1, std::vector<int>(n + 1, 0));

    //std::cout << "\n";
    for(int i = 1 ; i < n + 1 ; i++) {
        for(int j = 1 ; j < n + 1 ; j++) {
            int num = 0;
            std::cin >> num;
            if(j == 0) {
                array[i][j] = num;
            }
            else {
                array[i][j] = array[i][j - 1] + num;
            }
            //std::cout << array[i][j] << " ";
        }
        //std::cout << "\n";
    }

    for(int i = 0 ; i < m ; i++) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        
        int answer = 0;
        for(int j = x1 ; j <= x2 ; j++) {
            answer += array[j][y2] - array[j][y1 - 1];
        }
        std::cout << answer << "\n";
    }
}