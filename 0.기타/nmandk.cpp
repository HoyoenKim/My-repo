#include <iostream>
#include <vector>

using namespace std;

vector<int> visited(121, 0);
vector<int> lattice(121, 0);
int n, m, k;
long long answer = -1 * INT64_MIN;
int count = 0;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

bool isPossible(int i) {
    if(visited[i] == 1) {
        return false;
    }
    int x = i / m;
    int y = i % m;
    for(int k = 0 ; k < 4 ; k ++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx >= 0 && ny >= 0 && nx <= n - 1 && ny <= m - 1 && visited[nx * m + ny] == 1) {
            return false;
        }
    }
    return true;
}


void findmax(int t, long long value, int index) {
    if(t == k) {
        count += 1;
        answer = max(answer, value);
        return;
    }

    for(int i = index ; i < n * m ; i++) {
        if(isPossible(i)) {
            visited[i] = 1;
            findmax(t + 1, value + (long long) lattice[i], i);
            visited[i] = 0;
        }
    }
}
int main() {
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            int num;
            cin >> num;
            lattice[i * m + j] = num;
        }
    }

    findmax(0, 0, 0);

    cout << answer << "\n";
}