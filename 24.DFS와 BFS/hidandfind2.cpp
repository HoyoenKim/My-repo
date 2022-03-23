#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::queue<std::pair<int, int>> q;
    std::pair<int, int> p(n, 0);
    q.push(p);

    std::vector<int> visited(2*std::max(k, n) + 1, 0);
    int timeTh = 0;
    int count = 0;
    while(!q.empty()) {
        int current = q.front().first;
        int time = q.front().second;
        q.pop();

        if(count > 0) {
            if(time == timeTh && current == k) {
                count++;
            }

            if(time > timeTh) {
                break;
            }
        }

        if(count == 0 && current == k) {
            timeTh = time;
            count++;
        }
        
        if(1) {
            
            visited[current] = 1;
            if(current < k && visited[current + 1] == 0) {
                p.first = current + 1;
                p.second = time + 1;
                q.push(p);
            }
            if(current < k && current != 0 && visited[current * 2] == 0) {
                p.first = 2 * current;
                p.second = time + 1;
                q.push(p);
            }
            if(current > 0 && visited[current - 1] == 0) {
                p.first = current - 1;
                p.second = time + 1;
                q.push(p);
            }
        }
    }
    std::cout << timeTh << "\n" << count << "\n";
}