#include <iostream>
#include <queue>

int main() {
    unsigned long long A, B;
    std::cin >> A >> B;

    std::queue<std::vector<unsigned long long>> q;
    q.push({A, 0});

    int answer = -2;
    while(!q.empty()) {
        unsigned long long current = q.front()[0];
        unsigned long long count = q.front()[1];
        q.pop();

        if(current == B) {
            answer = count;
            break;
        }

        if(current > B) {

        }
        else {
            unsigned long long next = (unsigned long long) 2 * current;
            if(next <= B) {
                q.push({next, count + 1});
            }

            next = (unsigned long long) 10 * current + (unsigned long long) 1;
            if(next <= B) {
                q.push({next, count + 1});
            }
        }
    }
    std::cout << answer + 1 << "\n";
}