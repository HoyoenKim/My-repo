#include <iostream>
#include <vector>
#include <cmath>

int intMax = 1000000007;

std::vector<int> multiple(std::vector<int> a, std::vector<int> b) {
    std::vector<int> ret(2, 0);
    ret[0] = ( ( (unsigned long long) a[0] * (unsigned long long) b[0] ) % intMax + ( (unsigned long long) a[1] * (unsigned long long) b[0] ) % intMax + ( (unsigned long long) a[0] * (unsigned long long) b[1] ) % intMax ) % intMax;
    ret[1] = ( ( (unsigned long long) a[0] * (unsigned long long) b[0] ) % intMax + ( (unsigned long long) a[1] * (unsigned long long) b[1] ) % intMax ) % intMax; 
    return ret;
}
int main() {
    unsigned long long n;
    std::cin >> n;

    if(n == 0) {
        std::cout << 0 << "\n";
    }
    else {
        int m = std::log(n) / std::log(2);
    
        std::vector<std::vector<int>> array(m + 1, std::vector<int>(2, 0));
        for(int i = 0 ; i <= m ; i++) {
            if(i == 0) {
                array[i][0] = 1;
                array[i][1] = 0;
            }
            else {
                array[i] = multiple(array[i - 1], array[i - 1]);
            }
        }

        for(int i = 0 ; i <= m ; i++) {
            //std::cout << array[i][0] << " " << array[i][1] << "\n";
        }
        std::vector<int> answer(2, 0);
        int isInit = 0;

        for(int i = 0 ; i <= m ; i++) {
            if( (n & ((unsigned long long)1 << i)) == (unsigned long long) 1 << i) {
                if(isInit == 0) {
                    answer = array[i];
                    isInit = 1;
                }
                else {
                    answer = multiple(answer, array[i]);
                }
            }
        }
        std::cout << answer[0] << "\n";
    }
}