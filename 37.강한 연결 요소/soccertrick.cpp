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

            sccIndex[t] = sccNum;
            visited[t] = 1;

            if(t == current) {
                break;
            }
        }
    }

    return parent;

}

int main() {

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t > 0) {
        t--;

        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n + 1);

        for(int i = 0 ; i < m ; i++) {
            int a, b;
            cin >> a >> b;
            a += 1;
            b += 1;
            graph[a].push_back(b);
        }

        id = 1;
        sccNum = 0;
        vector<int> num(n + 1, 0);
        vector<int> visited(n + 1, 0);
        vector<int> sccIndex(n + 1, 0);
        stack<int> s;

        for(int i = 1 ; i <= n ; i++) {
            if(visited[i] == 0) {
                findScc(i, num, visited, sccIndex, graph, s);
            }
        }

        if(n == 1) {
            cout << "0\n";
        }
        else {
            vector<int> sccInDegree (sccNum + 1, 0);

            for(int i = 1 ; i <= n ; i++) {
                int currentSccIndex = sccIndex[i];
                //cout << i << " " << currentSccIndex << "\n";
                for(int j = 0 ; j < graph[i].size() ; j++) {
                    int nextSccIndex = sccIndex[graph[i][j]];
                    if(currentSccIndex != nextSccIndex) {
                        sccInDegree[nextSccIndex] += 1;
                    }
                }
            }

            vector<int> zeroDegree;
            for(int i = 1 ; i <= sccNum ; i++) {
                if(sccInDegree[i] == 0) {
                    zeroDegree.push_back(i);
                }
            }

            if(zeroDegree.size() == 1) {
                vector<int> answer;
                for(int i = 0 ; i < zeroDegree.size() ; i++) {
                    for(int j = 1 ; j <=n ; j++) {
                        if(sccIndex[j] == zeroDegree[i]) {
                            answer.push_back(j);
                        }
                    }
                }

                sort(answer.begin(), answer.end());

                for(int i = 0 ; i < answer.size() ; i++) {
                    cout << answer[i] - 1 << "\n";
                }
            }
            else {
                cout << "Confused\n";
            }
        }

        if(t > 0) {
            cout << "\n";
        }       
    }
}