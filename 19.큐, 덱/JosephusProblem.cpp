#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> seq;
    std::queue<int> q;
    int i = n;
    int j = 1;
    while(1) {
        if(j > n && q.size() == 0) {
            break;
        }

        if(j <= n) {
            if(j % k != 0) {
                q.push(j);
            }
            else {
                seq.push_back(j);
            }
        }
        else {
            if(j % k == 0) {
                seq.push_back(q.front());
                q.pop();
            }
            else {
                q.push(q.front());
                q.pop();
            }
        }
        j++;
    }
    std::cout << "<";
    for(int i = 0 ; i < n ; i++) {
        std::cout << seq[i];
        if(i == n - 1) {
            std::cout << ">\n";
        }   
        else {
            std::cout << ", ";
        }
    }
}