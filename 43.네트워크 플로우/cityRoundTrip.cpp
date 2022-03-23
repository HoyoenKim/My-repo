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
// BFS를 사용해서 모든 가능한 경로를 다 찾은 뒤 남은 용량만큼 유량을 흘려 보내 준다. 이때 역방향으로는 음의 유량을 흘려 보내주면 된다.

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    vector<vector<int>> capcity (n + 1, vector<int> (n + 1, 0));
    vector<vector<int>> flow (n + 1, vector<int> (n + 1, 0));
    vector<vector<int>> graph (n + 1);

    for(int i = 0 ; i < p ; i++) {
        int x, y;
        cin >> x >> y;

        capcity[x][y] = 1;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int total = 0, start = 1, end = 2;
    while(1) {
        vector<int> before (n + 1, -1);
        queue<int> q;
        q.push(start);

        while(!q.empty()) {
            int current = q.front();
            q.pop();

            for(int i = 0 ; i < graph[current].size() ; i++) {
                int next = graph[current][i];

                if(before[next] == -1 && capcity[current][next] - flow[current][next] > 0) {
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

        int minResidue = INT32_MAX;
        int now = end;
        while(now != start) {
            minResidue = min(minResidue, capcity[before[now]][now] - flow[before[now]][now]);
            now = before[now];
        }

        now = end;
        while(now != start) {
            flow[before[now]][now] += minResidue;
            flow[now][before[now]] -= minResidue;
            now = before[now];
        }

        total += minResidue;
    }

    cout << total << "\n";

}