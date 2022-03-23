#include <iostream>
#include <stack>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> array(n);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i];
    }

    std::stack<int> s;
    std::vector<int> op;
    int isPossible = 1;
    int beforePut = 0;
    for(int i = 0 ; i < n ; i++) {
        if(s.size() == 0) {
            for(int j = beforePut + 1 ; j <= array[i] ; j++) {
                s.push(j);
                op.push_back(1);
            }
            s.pop();
            op.push_back(0);
            beforePut = array[i];
        }
        else {
            if(s.top() == array[i]) {
                s.pop();
                op.push_back(0);
            }
            else if(s.top() < array[i]) {
                for(int j = beforePut + 1 ; j <= array[i] ; j++) {
                    s.push(j);
                    op.push_back(1);
                }
                s.pop();
                op.push_back(0);
                beforePut = array[i];
            }
            else {
                isPossible = 0;
                break;
            }
        }
    }

    if(isPossible) {
        for(int i = 0 ; i < op.size() ; i++) {
            if(op[i] == 1) {
                std::cout << "+\n";
            }
            else {
                std::cout << "-\n";
            }
        }
    }
    else {
        std::cout << "NO\n";
    }
    
}