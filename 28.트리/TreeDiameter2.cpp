#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    //1. 트리에서 임의의 정점 x를 잡는다.
    //2. 정점 x에서 가장 먼 정점 y를 찾는다.
    //3. 정점 y에서 가장 먼 정점 z를 찾는다.
    //트리의 지름은 정점 y와 정점 z를 연결하는 경로다.


    int n;
    std::cin >> n;
    std::vector<std::vector<std::vector<int>>> graph(n + 1);

    for(int i = 0 ; i < n - 1 ; i++) {
        int x, y, value;
        std::cin >> x >> y >> value;
        graph[x].push_back({y, value});
        graph[y].push_back({x, value});
    }

    // find lognest point from 1
    std::queue<std::vector<int>> q;
    std::vector<int> check(n + 1, 0);
    q.push({1, 0});
    check[1] = 1;

    int valueMax = 0;
    int MaxIndex = 1;
    while(!q.empty()) {
        int current = q.front()[0];
        int value = q.front()[1];
        q.pop();

        if(value > valueMax) {
            valueMax = value;
            MaxIndex = current;
        }

        for(int j = 0 ; j < graph[current].size() ; j++) {
            int next = graph[current][j][0];
            if(check[next] == 0) {
                int value2 = graph[current][j][1];
                q.push({next, value + value2});
                check[next] = 1;
            }
        }
    }

    // find lognest point from MaxIndex = 1;
    std::queue<std::vector<int>> q2;
    std::vector<int> check2(n + 1, 0);
    q2.push({MaxIndex, 0});
    check2[MaxIndex] = 1;

    int answer = 0;
    while(!q2.empty()) {
        int current = q2.front()[0];
        int value = q2.front()[1];
        q2.pop();
        if(answer < value) {
            answer = value;
        }

        for(int j = 0 ; j < graph[current].size() ; j++) {
            int next = graph[current][j][0];
            if(check2[next] == 0) {
                int value2 = graph[current][j][1];
                q2.push({next, value + value2});
                check2[next] = 1;
            }
        }
    }

    std::cout << answer << "\n";



}