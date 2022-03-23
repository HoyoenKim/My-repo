#include <iostream>
#include <vector>

/*
    Matching: G = (V, E), M <= E 의 모든 e 가 v 를 공유하지 않을때 M 을 Matching 이라고 한다.
    Vertex cover: G = (V, E), U <= V 의 모든 e 의 끝점이 U 에 속하면 U 를 Vertex cover 이라고 한다.

    Thm1
    Matching M, Vertex cover U 에 대해서 |M| <= |U| 를 만족한다.

    Thm2
    Matching M, Vertex cover U 에 대해서 |M| = |U| -> 은 max matching, U 는 min vertex cover 이다.

    Koing's Thm
    모든 bipartite graph 에서 |max matching|= |min vertex cover|
*/

using namespace std;

bool findMatch (int current, vector<vector<int>> &graph, vector<int> &matched, vector<int> visited) {
    visited[current] = 1;

    for(int i = 0 ; i < graph[current].size() ; i++) {
        int next = graph[current][i];

        if(matched[next] == -1 || visited[matched[next]] == 0 && findMatch(matched[next], graph, matched, visited)) {
            matched[next] = current;
            return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for(int i = 0 ; i < m ; i++) {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
    }

    vector<int> matched (n + 1, -1);
    int count = 0;
    
    for(int i = 1 ; i <= n ; i++) {
        vector<int> visited (n + 1, 0);
        if(findMatch(i, graph, matched, visited)) {
            count += 1;
        }
    }

    cout << count << "\n";
}