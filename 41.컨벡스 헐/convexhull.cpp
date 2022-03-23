#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool compare (vector<int> &a, vector<int> &b) {
    if(a[1] == b[1]) {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

long long ccw (vector<int> &a, vector<int> &b, vector<int> &c) {
    // ab (ax - bx, ay - by) x cb (cx - bx, cy - by)
    // = (ax - bx) * (cy - by) - (ay - by) * (cx - bx)
    long long ret1 = 1LL * (a[0] - b[0]) * (c[1] - b[1]);
    long long ret2 = 1LL * (a[1] - b[1]) * (c[0] - b[0]);
    return ret1 - ret2;
}

bool compare2 (vector<int> &a, vector<int> &b) {
    vector<int> zero = {0, 0};
    long long ret = ccw(a, zero, b);
    if(ret != 0) {
        return ret > 0;
    }
    if(a[1] != b[1]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> points (n, vector<int> (2, 0));
    for(int i = 0 ; i < n ; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }
    sort(points.begin(), points.end(), &compare);

    vector<vector<int>> points2 (n, vector<int> (2, 0));
    for(int i = 1 ; i < n ; i++) {
        points2[i][0] = points[i][0] - points[0][0]; 
        points2[i][1] = points[i][1] - points[0][1];
    }
    sort(points2.begin(), points2.end(), &compare2);

    for(int i = 0 ; i < n ; i++) {
        //cout << points2[i][0] + 1<< " " << points2[i][1] + 1<< "\n";
    }

    stack<int> s;
    s.push(0);
    s.push(1);
    int next = 2;

    while(next < n) {
        while(s.size() >= 2) {
            int first = s.top();
            s.pop();
            int second = s.top();

            if(ccw(points2[first], points2[second], points2[next]) > 0) {
                s.push(first);
                break;
            }
        }
        s.push(next++);
    }

    cout << s.size() << "\n";
}