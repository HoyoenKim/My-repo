#include <iostream>
#include <vector>
int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> array(n, std::vector<int>(2, 0));

    int N = 0;
    for(int i = 0 ; i < n ; i++) {
        int a, b;
        std::cin >> a >> b;

        if(a > b) {
            array[i][0] = a;
            array[i][1] = b;
        }
        else {
            array[i][0] = b;
            array[i][1] = a;
        }

        if(array[i][0] > N) {
            N = array[i][0];
        }
    }

    std::vector<std::vector<unsigned long long>> bc(N + 1, std::vector<unsigned long long>(N + 1, 0));
    for(int i = 0 ; i <= N ; i++) {
        for(int j = 0 ; j <= i ; j++) {
            if(j == 0) {
                bc[i][j] = 1;
            }
            else if(i == j) {
                bc[i][j] = 1;
            }
            else {
                bc[i][j] = (bc[i - 1][j] + bc[i - 1][j - 1]);
            }
        }
    }

    for(int i = 0 ; i < n ; i++) {
        std::cout << bc[array[i][0]][array[i][1]] << "\n";
    }
}