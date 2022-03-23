#include <iostream>
#include <vector>
#include <queue>

// 네트워크 플로우는 특정 지점에서 다른 지점으로 데이터가 얼마나 많이 흐르고 있는가를 측정하는 알고리즘이다.
// A - 8 -> B - 6 -> C - 7 -> D
// A -> D로 보낼 수 있는 최대 유량은 6이다.

// 포드 풀커슨(DFS, 실수에서는 사용 불가), 에드몬드 카프(BFS), 디닉 알고리즘 사용.

// s - 2 -> a - 2 -> t
//        - 1 ->
// s - 2 -> b - 2 -> t
// a -> b 로 흐르는 경로는 잘못된 경로이고 이를 보완하기 위해서 음의 유량을 계산한다.

int result = 0;
int INF = INT32_MAX - 1;

std::vector<int> before(52);
std::vector<std::vector<int>> value(52, std::vector<int>(52));
std::vector<std::vector<int>> flow(52, std::vector<int>(52));
std::vector<std::vector<int>> graph(52);

void maxFlow(int start, int end) {
    while(1) {
        std::fill(before.begin(), before.end(), -1);
        std::queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int current = q.front();
            q.pop();

            for(int i = 0 ; i < graph[current].size() ; i++) {
                int next = graph[current][i];
                if(before[next] == -1 && value[current][next] - flow[current][next] > 0) {
                    before[next] = current;
                    q.push(next);
                    if(next == end) {
                        break;
                    }
                }
            }
        }
        if(before[end] == -1) {
            break;
        }

        int f = INF;
        for(int i = end ; i != start ; i = before[i]) {
            f = std::min(f, value[before[i]][i] - flow[before[i]][i]);
        }

        for(int i = end ; i != start ; i = before[i]) {
            flow[before[i]][i] += f;
            flow[i][before[i]] -= f;
        }
        result += f;
    }
}

int c2i(char x) {
    if(x <= 'Z') {
        return x - 'A';
    }
    else {
        return x - 'a' + 26;
    }
}

int main() {
    int n;
    std::cin >> n;

    for(int i = 0 ; i < n ; i++) {
        char A, B;
        int v;
        std::cin >> A >> B >> v;
        A = c2i(A);
        B = c2i(B);
        value[A][B] += v;
        value[B][A] += v;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    maxFlow(c2i('A'), c2i('Z'));
    std::cout << result << "\n";
}