#include <iostream>
#include <vector>

using namespace std;

int taxiDist(vector<int> &a, vector<int> &b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> chicken;
    vector<vector<int>> house;

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            int num;
            cin >> num;

            vector<int> cord = {i, j};
            if(num == 1) {
                house.push_back(cord);
            }
            else if(num == 2) {
                chicken.push_back(cord);
            }
        }
    }
}