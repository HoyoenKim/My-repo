#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int id = 1;
int sccNum = 0;

int startSccIndex;
int startNum;

vector<int> sccCashNum;
vector<int> sccIsR;

int findScc(int current, vector<int> &num, vector<int> &visited, vector<int> &sccIndex, vector<vector<int>> &graph, stack<int> &s, vector<int> &cash, vector<int> &isR) {
    num[current] = id;
    id += 1;
    s.push(current);

    int parent = num[current];
    for(int i = 0 ; i < graph[current].size() ; i++) {
        int next = graph[current][i];

        if(num[next] == 0) {
            parent = min(parent, findScc(next, num, visited, sccIndex, graph, s, cash, isR));
        }
        else if(visited[next] == 0) {
            parent = min(parent, num[next]);
        }
    }

    if(parent == num[current]) {
        sccNum += 1;

        int isExistR = 0;
        int sccCash = 0;
        while(!s.empty()) {
            int t = s.top();
            s.pop();
            
            sccIndex[t] = sccNum;
            visited[t] = 1;

            sccCash += cash[t];            
            if(isR[t] == 1) {
                isExistR = 1;
            }

            if(t == startNum) {
                startSccIndex = sccNum;
            }

            if(t == current) {
                break;
            }
        }

        if(isExistR) {
            sccIsR.push_back(1);
        }
        else {
            sccIsR.push_back(0);
        }

        sccCashNum.push_back(sccCash);
    }

    return parent;
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

    vector<int> cash(n + 1);
    for(int i = 1 ; i <= n ; i++) {
        cin >> cash[i];
    }

    int rnum;
    cin >> startNum >> rnum;

    vector<int> isR(n + 1, 0);
    for(int i = 0 ; i < rnum ; i++) {
        int rindex;
        cin >> rindex;

        isR[rindex] = 1;
    }

    vector<int> num(n + 1, 0);
    vector<int> visited(n + 1, 0);
    vector<int> sccIndex(n + 1, 0);
    stack<int> s;

    for(int i = 1 ; i <= n ; i++) {
        if(visited[i] == 0) {
            findScc(i, num, visited, sccIndex, graph, s, cash, isR);
        }
    }

    vector<int> sccInDegree (sccNum + 1, 0);
    vector<vector<int>> sccGraph (sccNum + 1);
    for(int i = 1 ; i <= n ; i++) {
        int currentSccIndex = sccIndex[i];

        for(int j = 0 ; j < graph[i].size() ; j++) {
            int nextSccIndex = sccIndex[graph[i][j]];
            if(nextSccIndex != currentSccIndex) {
                sccGraph[currentSccIndex].push_back(nextSccIndex);
                sccInDegree[nextSccIndex] += 1;
            }
        }
    }

    vector<int> answer(sccNum + 1 , 0);
    vector<int> isStart(sccNum + 1, 0);
    isStart[startSccIndex] = 1;
    
    for(int i = 0 ; i < sccIsR.size() ; i++) {
        //cout << i << " " << sccIsR[i] << " " << sccCashNum[i] << " " << sccInDegree[i + 1] << " " << isStart[i + 1] << "\n";
    }

    queue<int> q;
    for(int i = 1 ; i <= sccNum ; i++) {
        answer[i] = sccCashNum[i - 1];
        if(sccInDegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {        
        int current = q.front();
        q.pop();

        for(int j = 0 ; j < sccGraph[current].size() ; j++) {
            int next = sccGraph[current][j];

            if(isStart[current] == 1) {
                answer[next] = max(answer[next], answer[current] + sccCashNum[next - 1]);
                isStart[next] = 1;
            }

            sccInDegree[next] -= 1;
            if(sccInDegree[next] == 0) {
                q.push(next);
            }
        }
    }

    int ret = 0;
    for(int i = 1 ; i <= sccNum ; i++) {
        if(sccIsR[i - 1] == 1 && isStart[i] == 1) {
            ret = max(ret, answer[i]);
        }
    }

    cout << ret << "\n";

}