#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findParent(int a, vector<int> &parent) {
    if(parent[a] == a) {
        return a;
    }

    return parent[a] = findParent(parent[a], parent);  
}

int ccw (vector<int> &a, vector<int> &b, vector<int> &c) {
    //      (   i   ,    j   , k)
    // ab = (ax - bx, ay - by, 0)
    // cb = (cx - bx, cy - by, 0)
    // ab x cb = (ax - bx) * (cy - by) - (ay - by) * (cx - bx) k

    long long ret = 1LL * (a[0] - b[0]) * (c[1] - b[1]) - 1LL * (a[1] - b[1]) * (c[0] - b[0]);

    if(ret > 0) {
        return 1;
    }
    else if(ret == 0) {
        return 0;
    }
    else {
        return -1;
    }
}

bool isCross(int i, int j, vector<vector<int>> &lines) {
    // ab cd
    // ccw(a, b, c) * ccw(a, b, d) <= 0 && ccw(c, d, a) & ccw(c, d, b) <= 0
    
    vector<int> a = {lines[i][0], lines[i][1]};
    vector<int> b = {lines[i][2], lines[i][3]};
    vector<int> c = {lines[j][0], lines[j][1]};
    vector<int> d = {lines[j][2], lines[j][3]};

    int ccw1 = ccw(a, b, c);
    int ccw2 = ccw(a, b, d);
    int ccw3 = ccw(c, d, a);
    int ccw4 = ccw(c, d, b);

    if(ccw1 * ccw2 == 0 && ccw3 * ccw4 == 0) {
        int maxxab = max(a[0], b[0]);
        int minxab = min(a[0], b[0]);
        int maxxcd = max(c[0], d[0]);
        int minxcd = min(c[0], d[0]);

        int maxyab = max(a[1], b[1]);
        int minyab = min(a[1], b[1]);
        int maxycd = max(c[1], d[1]);
        int minycd = min(c[1], d[1]);

        bool ret1 = (maxxab >= minxcd) && (maxyab >= minycd);
        bool ret2 = (maxxcd >= minxab) && (maxycd >= minyab);

        if(ret1 && ret2) {
            return true;
        }
    }
    else if(ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0){
        return true;
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> lines (n, vector<int> (4, 0));
    for(int i = 0 ; i < n ; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines[i] = {x1, y1, x2, y2};
    }

    vector<int> parent(n, -1);
    for(int i = 0 ; i < n ; i++) {
        parent[i] = i;
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            int a = findParent(i, parent);
            int b = findParent(j, parent);
            if(isCross(i, j, lines)) {
                if(a < b) {
                    parent[b] = a;
                }
                else {
                    parent[a] = b;
                }
            }
        }
    }

    for(int i = 0 ; i < n ; i++) {
        //cout << i << " " << parent[i] << "\n";
    }

    vector<int> group(n, 0);
    for(int i = 0 ; i < n ; i++) {
        group[parent[i]] += 1;
    }

    int groupnum = 0;
    int groupmax = 0;
    for(int i = 0 ; i < n ; i++) {
        if(group[i] > 0) {
            groupnum += 1;
        }

        groupmax = max(groupmax, group[i]);
    }
    cout << groupnum << "\n" << groupmax << "\n";
}