#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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

bool compare(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

int main() {
    int n, m;
    cin >> n >> m;
    // -n, -(n - 1), ... , 0, 1, 2, ... n;
    // 0, 1, .... n, n + 1, n + 2, ... , n + n

    vector<vector<int>> graph(2 * n + 1);

    for(int i = 0 ; i < m ; i++) {
        int x1, x2, x3;
        char c1, c2, c3;

        cin >> x1 >> c1 >> x2 >> c2 >> x3 >> c3;

        if(c1 == 'R') {
            x1 *= -1;
        }
        
        if(c2 == 'R') {
            x2 *= -1;
        }

        if(c3 == 'R') {
            x3 *= -1;
        }

        x1 += n;
        x2 += n;
        x3 += n;

        // (x1 or x2) and (x2 or x3) and (x1 or x3)

        graph[2 * n - x1].push_back(x2);
        graph[2 * n - x2].push_back(x1);

        graph[2 * n - x2].push_back(x3);
        graph[2 * n - x3].push_back(x2);

        graph[2 * n - x1].push_back(x3);
        graph[2 * n - x3].push_back(x1);
    }

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
    for(int i = 0 ; i < n ; i++) {
        if(sccIndex[i] == sccIndex[2 * n - i]) {
            isCNT = 0;
            break;
        }
    }

    if(isCNT) {
        vector<int> res(2 * n + 1, -1);
        
        vector<vector<int>> sccIndexWithIndex(2 * n + 1);
        for(int i = 0 ; i < 2 * n + 1 ; i++) {
            sccIndexWithIndex[i] = {sccIndex[i], i};
        }
    
        sort(sccIndexWithIndex.begin(), sccIndexWithIndex.end(), &compare);

        for(int i = 2 * n ; i >= 0 ; i--) {
            int currentIndex = sccIndexWithIndex[i][1];
            if(res[currentIndex] == -1) {
                res[currentIndex] = 0;
                res[2 * n - currentIndex] = 1;
            }
        }

        for(int i = n + 1 ; i < 2 * n + 1 ; i++) {
            if(res[i] == 0) {
                cout << "R";
            }
            else {
                cout << "B";
            }
        }
        cout << "\n";
    }
    else {
        cout << "-1\n";
    }
}