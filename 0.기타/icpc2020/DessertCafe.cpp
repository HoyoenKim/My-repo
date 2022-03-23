#include <bits/stdc++.h>

using namespace std;

vector<int> isApart(100001, 0);
vector<int> visited(100001, 0);

int findNumOfAparts(int current, vector<vector<int>> &tree, vector<int> &numOfAparts) {
    visited[current] = 1;

    int ret = 0;
    if(isApart[current] == 1) {
        ret += 1;
    }

    for(int i = 0 ; i < tree[current].size() ; i++) {
        int next = tree[current][i];
        if(visited[next] == 0) {
            ret += findNumOfAparts(next, tree, numOfAparts);
        }
    }

    return numOfAparts[current] = ret;
}

int answer = 0;
vector<int> visited2(100001, 0);
void findGoodPlace(int current, vector<vector<int>> &tree, vector<int> &numOfAparts) {
    visited2[current] = 1;

    if(numOfAparts[current] == 0) {
        return ;
    }

    int count = 0;
    for(int i = 0 ; i < tree[current].size() ; i++) {
        int next = tree[current][i];
        if(visited2[next] == 0) {
            if(numOfAparts[next] > 0) {
                count += 1;
            }

            findGoodPlace(next, tree, numOfAparts);
        }
    }

    if(count >= 2) {
        answer += 1;
    }
    else if(count == 1 && numOfAparts[1] > numOfAparts[current]) {
        answer += 1;
    }
    else if(isApart[current]) {
        answer += 1;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> tree(n + 1);
    for(int index = 0 ; index < n - 1 ; index++) {
        int i, j, w;
        cin >> i >> j >> w;
        tree[i].push_back(j);
        tree[j].push_back(i);
    }

    for(int i = 0 ; i < k ; i++) {
        int a;
        cin >> a;
        isApart[a] = 1;
    }

    vector<int> numOfAparts(n + 1, 0);
    findNumOfAparts(1, tree, numOfAparts);
    findGoodPlace(1, tree, numOfAparts);

    std::cout << answer << "\n";
}