#include <iostream>
#include <vector>
#include <stack>

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;

    std::vector<int> array(n);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i];
    }

    std::stack<int> s;
    std::vector<int> neg;
    for(int i = n - 1 ; i >= 0 ; i--) {
        if(i == n - 1) {
            neg.push_back(-1);
        }
        else {
            if(array[i] < array[i + 1]) {
                neg.push_back(array[i + 1]);
                s.push(array[i + 1]);
            }
            else{
                while(1) {
                    if(s.size() == 0) {
                        neg.push_back(-1);
                        break;
                    }
                    else {
                        if(array[i] < s.top()) {
                            neg.push_back(s.top());
                            break;
                        }
                        else {
                            s.pop();
                        }
                    }
                }
            }
        }
    }

    for(int i = n - 1; i >= 0 ; i--) {
        std::cout << neg[i] << " ";
    }
    std::cout << "\n";
}