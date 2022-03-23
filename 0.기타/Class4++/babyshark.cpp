#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(vector<int> &a, vector<int> &b) {
    if(a[2] == b[2]) {
        if(a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    return a[2] < b[2];
}

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
vector<int> babySharkLocation;
int babySharkSize = 2;
int eatNum = 0;
int eatTime = 0;
int n;

int main() {
    cin >> n;
    vector<vector<int>> space(n, vector<int> (n, 0));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            int spaceElement;
            cin >> spaceElement;

            if(spaceElement == 9) {
                babySharkLocation = {i, j};
                spaceElement = 0;
            }

            space[i][j] = spaceElement;
        }
    }

    while(1) {
        vector<vector<int>> fishLocation;
        vector<vector<int>> visited (n, vector<int> (n, 0));
        queue<vector<int>> q;
        q.push({babySharkLocation[0], babySharkLocation[1], 0});
        visited[babySharkLocation[0]][babySharkLocation[1]] = 1;
        while(!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            int move = q.front()[2];
            q.pop();

            for(int i = 0 ; i < 4 ; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny < n && visited[nx][ny] == 0) {
                    if(space[nx][ny] > 0 && space[nx][ny] < babySharkSize) {
                        fishLocation.push_back({nx, ny, move + 1});
                    }

                    if(space[nx][ny] <= babySharkSize) {
                        q.push({nx, ny, move + 1});
                        visited[nx][ny] = 1;
                    }
                }
            }
        }

        if(fishLocation.size() == 0) {
            break;
        }

        sort(fishLocation.begin(), fishLocation.end(), &compare);
        babySharkLocation = fishLocation[0];
        space[fishLocation[0][0]][fishLocation[0][1]] = 0;
        eatTime += fishLocation[0][2];

        eatNum += 1;
        if(eatNum == babySharkSize) {
            babySharkSize += 1;
            eatNum = 0;
        }
    }

    cout << eatTime << "\n";
}