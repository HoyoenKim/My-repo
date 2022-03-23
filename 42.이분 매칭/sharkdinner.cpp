#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool findMatch(int current, vector<vector<int>> &graph, vector<int> &visited, vector<int> &matched) {
    visited[current] = 1;

    for(int i = 0 ; i < graph[current].size() ; i++) {
        int next = graph[current][i];

        if(matched[next] == -1 || visited[matched[next]] == 0 && findMatch(matched[next], graph, visited, matched) ) {
            matched[next] = current;
            
            return true;
        }
    }

    return false;
}

bool compareAbility (int i, int j, vector<vector<int>> &sharkAbility) {
    int samecount = 0;
    for(int index = 0 ; index < 3 ; index ++) {
        if(sharkAbility[i][index] < sharkAbility[j][index]) {
            return false;
        }
        else if(sharkAbility[i][index] == sharkAbility[j][index]) {
            samecount += 1;
        }
    }

    if(samecount == 3) {
        if(sharkAbility[i][3] > sharkAbility[j][3]) {
            return false;
        }
    }


    return true;
}

bool compare (vector<int> &a, vector<int> &b) {
    if(a[0] == b[0]) {
        if(a[1] == b[1]) {
            if(a[2] == b[2]) {
                return a[3] < b[3];
            }
            return a[2] < b[2];
        }
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> sharkAbility (n);
    for(int i = 0 ; i < n ; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        sharkAbility[i] = {a, b, c, i};
    }

    //sort(sharkAbility.begin(), sharkAbility.end(), &compare);

    vector<vector<int>> graph (2 * n );
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(compareAbility(i, j, sharkAbility) && i != j) {
                //cout << i << " " << j << "\n";
                graph[i].push_back(j);
                graph[i + n].push_back(j);
            }
        }
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < graph[i].size() ; j++) {
            //cout << i << " " << graph[i][j] << "\n";
        }
    }
    
    int count = 0;
    vector<int> matched (2 * n, -1);
    for(int i = 0 ; i < 2 * n ; i++) {
        vector<int> visited (2 * n, 0);
        if(findMatch(i, graph, visited, matched)) {
            count += 1;
        }
    }

    cout << n - count << "\n";

}