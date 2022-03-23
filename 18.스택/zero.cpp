#include <iostream>
#include <stack>

int main() {
    int n;
    std::cin >> n;
    std::stack<int> s;

    for(int i = 0 ; i < n ; i++) {
       int j;
       std::cin >> j;
       if(j == 0) {
           s.pop();
       }
       else {
           s.push(j);
       }
    }

    int size = s.size();
    int sum = 0;
    while(size > 0) {
        sum += s.top();
        s.pop();
        size --;
    }

    std::cout << sum << "\n";

}