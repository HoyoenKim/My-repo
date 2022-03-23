#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> distance(n - 1);
    std::vector<int> price(n);

    for(int i = 0 ; i < n - 1 ; i++) {
        std::cin >> distance[i];
    }
    for(int i = 0 ; i < n ; i++) {
        std::cin >> price[i];
    }

    int i = 0;
    unsigned long long sum = 0;
    unsigned long long toGoDis = 0;
    int nowPrice = 0;
    while(1) {
        if(i == n - 1) {
            break;
        }
        toGoDis = 0; 
        nowPrice = price[i];
        while(1) {
            if(i == n - 1) {
                break;
            }
            toGoDis += distance[i];
            i++;
            if(nowPrice > price[i]) {
                break;
            }
        }
        sum += toGoDis * (unsigned long long) nowPrice;
    }
    std::cout << sum << "\n";
}