#include <iostream>
#include <vector>
#include <queue>

struct compare{
    bool operator() (int a, int b) {
        return a > b;
    }
};

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, compare> q;
    for(int i = 0 ; i < n ; i++) {
        int j;
        std::cin >> j;
       
       if(j == 0) {
           if(q.size() == 0) {
               std::cout << 0 << "\n";
           }
           else {
               std::cout << q.top() << "\n";
               q.pop();
           }
       }
       else {
           q.push(j);
       }
    }
}