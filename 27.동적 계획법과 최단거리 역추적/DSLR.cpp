#include <iostream>
#include <vector>
#include <queue>
#include <string>

int D(int x) {
    return 2 * x % 10000;
}

int S(int x) {
    return (x - 1 + 10000) % 10000;
}

int L(int x) {
    int d1 = (x / 1000) % 10;
    int d2 = (x / 100) % 10;
    int d3 = (x / 10) % 10;
    int d4 = x % 10;

    return d2 * 1000 + d3 * 100 + d4 * 10 + d1;
}


int R(int x) {
    int d1 = (x / 1000) % 10;
    int d2 = (x / 100) % 10;
    int d3 = (x / 10) % 10;
    int d4 = x % 10;

    return d4 * 1000 + d1 * 100 + d2 * 10 + d3;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    for(int i = 0 ; i < N ; i++) {
        int A, B;
        std::cin >> A >> B;
        std::vector<int> check(10000, 0);
        std::queue<std::pair<int, std::string>> q;
        std::pair <int, std::string> p;
        
        check[A] = 0;
        p.first = A;
        p.second = "";
        q.push(p);

        std::string answer = "";
        while(!q.empty()) {
            int current = q.front().first;
            std::string count = q.front().second;
            q.pop();

            if(current == B) {
                answer = count;
                break;
            }

            int d = D(current);
            if(check[d] == 0) {
                check[d] = 1;
                p.first = d;
                p.second = count + "D";
                q.push(p);
            }

            int s = S(current);
            if(check[s] == 0) {
                check[s] = 1;
                p.first = s;
                p.second = count + "S";
                q.push(p);
            }

            int l = L(current);
            if(check[l] == 0) {
                check[l] = 1;
                p.first = l;
                p.second = count + "L";
                q.push(p);
            }

            int r = R(current);
            if(check[r] == 0) {
                check[r] = 1;
                p.first = r;
                p.second = count + "R";
                q.push(p);
            }
        }
        std::cout << answer << "\n";
    }
}