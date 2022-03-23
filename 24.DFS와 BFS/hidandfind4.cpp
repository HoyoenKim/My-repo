#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::queue<std::vector<int>> q;
    q.push({n, 0});

    std::vector<int> visited(2*std::max(k, n) + 1, 0);
    std::vector<int> before(2*std::max(k, n) + 1, 0);
    int ansTime;
    while(!q.empty()) {
        int current = q.front()[0];
        int time = q.front()[1];
        q.pop();

        if(current == k) {
            ansTime = time;
            break;
        }

        if(current < k && current != 0 && visited[current * 2] == 0) {
            visited[current * 2] = 1;
            before[current * 2] = current;
            q.push({current * 2, time + 1});
        }

        if(current < k && visited[current + 1] == 0) {
            visited[current + 1] = 1;
            before[current + 1] = current;
            q.push({current + 1, time + 1});
        }
            
        if(current > 0 && visited[current - 1] == 0) {
            visited[current - 1] = 1;
            before[current - 1] = current;
            q.push({current - 1, time + 1});
        }
    }
    
    std::cout << ansTime << "\n";

    std::vector<int> answer;

    int index = k;
    while(index != n) {
        answer.push_back(index);
        index = before[index];
    }
    answer.push_back(n);

    for(int i = answer.size() - 1; i >= 0 ; i--) {
        std::cout << answer[i] << " ";
    }
    std::cout << "\n";
}