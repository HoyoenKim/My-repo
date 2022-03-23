#include <iostream>
#include <vector>
#include <stack>

using namespace std;

using namespace std;

int id = 1;
int sccNum = 0;

int findScc(int current, vector<int> &num, vector<int> &visited, vector<int> &sccIndex, vector<vector<int>> &graph, stack<int> &s) {
    num[current] = id;
    id += 1;

    s.push(current);

    int parent = num[current];
    for(int i = 0 ; i < graph[current].size() ; i++) {
        int next = graph[current][i];

        if(num[next] == 0) {
            parent = min(parent, findScc(next, num, visited, sccIndex, graph, s)); 
        }
        else if(visited[next] == 0) {
            parent = min(parent, num[next]);
        }
    }

    if(parent == num[current]) {
        sccNum += 1;
        while(!s.empty()) {
            int t = s.top();
            s.pop();

            visited[t] = 1;
            sccIndex[t] = sccNum;

            if(t == current) {
                break;
            }
        }
    }

    return parent;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cout.tie(NULL);
    //cin.tie(NULL);

    int n, m;

    while(cin >> n >> m) {
        vector<vector<int>> graph(2 * n + 1);

        for(int i = 0 ; i < m ; i++) {
            int x, y;
            cin >> x >> y;

            x +=n;
            y +=n;

            graph[2 * n - x].push_back(y);
            graph[2 * n - y].push_back(x);
        }

        graph[n - 1].push_back(n + 1);

        id = 1;
        sccNum = 0;

        vector<int> num (2 * n + 1, 0);
        vector<int> visited (2 * n +  1, 0);
        vector<int> sccIndex (2 * n + 1, 0);
        stack<int> s;

        for(int i = 0 ; i < 2 * n + 1 ; i++) {
            if(visited[i] == 0) {
                findScc(i, num, visited, sccIndex, graph, s);
            }
        }

        int isCNT = 1;
        for(int i = 0 ; i < n - 1 ; i++) {
            if(sccIndex[i] == sccIndex[2 * n - i]) {
                isCNT = 0;
                break;
            }
        }

        if(isCNT) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }

    }
}