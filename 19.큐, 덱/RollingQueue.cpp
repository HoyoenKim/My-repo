#include <iostream>
#include <deque>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> find(m);
    for(int i = 0 ; i < m ; i++) {
        std::cin >> find[i];
    }

    std::deque<int> dq;
    for(int i = 0 ; i < n ; i++) {
        // (front) 1, 2, 3 (back)
        // mid = 3 / 2 = 1
        // (front) 1, 2, 3, 4 (back)
        // mid = 4 / 2 = 2
        dq.push_back(i + 1);
    }

    int count = 0;
    for(int i = 0 ; i < m ; i++) {
        if(dq.front() == find[i]) {
            dq.pop_front();
        }
        else if(dq.back() == find[i]) {
            count++;
            dq.pop_back();
        }
        else{
            int j;
            for(j = 0 ; j < dq.size() ; j++) {
                //std::cout << dq[j] << "\n";
                if(dq[j] == find[i]) {
                    break;
                }
            }

            if(j <= dq.size() / 2) {
                while(1) {
                    if(dq.front() == find[i]) {
                        dq.pop_front(); 
                        break;
                    }
                    else {
                        dq.push_back(dq.front());
                        dq.pop_front();
                        count++;
                    }
                }
            }
            else {
                while(1) {
                    if(dq.back() == find[i]) {
                        dq.pop_back(); 
                        count++;
                        break;
                    }
                    else {
                        dq.push_front(dq.back());
                        dq.pop_back();
                        count++;
                    }
                }
            }
            //std::cout << dq[i] << "\n";
        }
    }
    std::cout << count << "\n";
}