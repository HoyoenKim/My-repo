#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

struct lineSeg {
    int eq, min, max;
    bool operator < (const lineSeg &s) const {
        return ii(eq, max) < ii(s.eq, s.max);
    }
};

vector<lineSeg> xLine, yLine;
vector<ii> point, dualPoint;

vector<int> dx = {0, -1, 0, 1};
vector<int> dy = {1, 0, -1, 0};

int INTMAX = 100000;
vector<vector<int>> nextPointInex (INTMAX, vector<int>(4, -1));

bool isSameLine(vector<lineSeg> &lineGroup, int eq, int min, int max) {
    int index = lower_bound(lineGroup.begin(), lineGroup.end(), (lineSeg){eq, 0, max}) - lineGroup.begin();
    if(index != lineGroup.size() && lineGroup[index].eq == eq && lineGroup[index].min <= min && min <= lineGroup[index].max) {
        return true;
    } 
    return false;
}

long long moveDist(int i, int j) {
    ii a = point[i];
    ii b = point[j];
    return abs(a.first - b.first) + abs(a.second - b.second);
}

long long getCycleLength(int startPointIndex, int startDirection) {
    long long len = 0;
    ii startPoint = point[startPointIndex];
    
    int nowPointIndex = startPointIndex;
    int nowDirection = startDirection;
    while(1) {
        while(nextPointInex[nowPointIndex][nowDirection] == -1) {
            nowDirection = (nowDirection + 1) % 4;
        }
        
        len += moveDist(nowPointIndex, nextPointInex[nowPointIndex][nowDirection]);
        nowPointIndex = nextPointInex[nowPointIndex][nowDirection];
        nowDirection = (nowDirection + 1) % 4;
        
        if(startPointIndex == nowPointIndex) {
            break;
        }
    }

    return len;
}

void simulation(int startPointIndex, int t, int startDirection) {
    int nowPointIndex = startPointIndex;
    int nowDirection = startDirection;

    while(1) {
        while(nextPointInex[nowPointIndex][nowDirection] == -1) {
            nowDirection = (nowDirection + 1) % 4;
        }

        if(t <= moveDist(nowPointIndex, nextPointInex[nowPointIndex][nowDirection])) {
            int x = point[nowPointIndex].first + dx[nowDirection] * t;
            int y = point[nowPointIndex].second + dy[nowDirection] * t;
            std::cout << x << " " << y << "\n";
            break;
        }
        else {
            t -= moveDist(nowPointIndex, nextPointInex[nowPointIndex][nowDirection]);
            nowPointIndex = nextPointInex[nowPointIndex][nowDirection];
            nowDirection = (nowDirection + 1) % 4;
        }
    }
}


int n, t;
int main() {
    cin >> n >> t;

    ii startPoint;
    int startDirection;
    for(int i = 0 ; i < n ; i++) {
        int bx, by, ex, ey;
        cin >> bx >> by >> ex >> ey;
        
        if(i == 0) {
            startPoint = ii(bx, by);
        }

        if(bx > ex) {
            swap(bx, ex);
        }
        if(by > ey) {
            swap(by, ey);
        }


        if(bx == ex) {
            xLine.push_back({bx, by, ey});
            if(i == 0) {
                if(startPoint.second == by) {
                    startDirection = 0;
                }
                else {
                    startDirection = 2;
                }
            }
        }
        else if(by == ey) {
            yLine.push_back({by, bx, ex});
            if(i == 0) {
                if(startPoint.first == bx) {
                    startDirection = 3;
                }
                else {
                    startDirection = 1;
                }
            }
        }

        point.push_back(ii(bx, by));
        point.push_back(ii(ex, ey));

    }

    sort(xLine.begin(), xLine.end());
    sort(yLine.begin(), yLine.end());

    for(int i = 0 ; i < xLine.size() ; i++) {
        int x = xLine[i].eq;
        int yMin = xLine[i].min;
        int yMax = xLine[i].max;
        for(int j = 0 ; j < yLine.size() ; j++) {
            int y = yLine[j].eq;
            int xMin = yLine[j].min;
            int xMax = yLine[j].max;
            if(xMin <= x && x <= xMax && yMin <= y && y <= yMax) {
                point.push_back(ii(x, y));
            }
        }
    }

    sort(point.begin(), point.end());
    for(int i = 0 ; i < point.size() ; i++) {
        dualPoint.push_back(ii(point[i].second, point[i].first));
    }
    sort(dualPoint.begin(), dualPoint.end());

    for(int i = 0 ; i < point.size() - 1; i++) {
        if(point[i].first == point[i + 1].first) {
            if(isSameLine(xLine, point[i].first, point[i].second, point[i + 1].second)) {
                nextPointInex[i][0] = i + 1;
                nextPointInex[i + 1][2] = i;
            }
        }
    }

    for(int i = 0 ; i < dualPoint.size() - 1; i++) {
        if(dualPoint[i].first == dualPoint[i + 1].first) {
            if(isSameLine(yLine, dualPoint[i].first, dualPoint[i].second, dualPoint[i + 1].second)) {
                int j = lower_bound(point.begin(), point.end(), ii(dualPoint[i].second, dualPoint[i].first)) - point.begin();
                int k = lower_bound(point.begin(), point.end(), ii(dualPoint[i + 1].second, dualPoint[i + 1].first)) - point.begin();
                nextPointInex[j][3] = k;
                nextPointInex[k][1] = j;
            }
        }
    }

    int startPointIndex = lower_bound(point.begin(), point.end(), startPoint) - point.begin();
    long long cycleLength = getCycleLength(startPointIndex, startDirection);
    t %= cycleLength;
    simulation(startPointIndex, t, startDirection);
}