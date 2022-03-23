#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

double dist(int i, int j, std::vector<std::vector<double>> &point) {
    double x = point[i][0] - point[j][0];
    double y = point[i][1] - point[j][1];
    return std::sqrt(x*x + y*y);
}

bool compare(std::vector<double> a, std::vector<double> b) {
    return a[2] < b[2];
}

int findParent(int a, std::vector<int> &set) {
    if (a == set[a]) {
        return set[a];
    }
    return set[a] = findParent(set[a], set);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<double>> point(n, std::vector<double>(2, 0));
    for(int i = 0 ; i < n ; i++) {
        double x, y;
        std::cin >> x >> y;
        point[i][0] = x;
        point[i][1] = y;
    }

    std::vector<std::vector<double>> graph;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < i ; j++) {
            graph.push_back({(double) i, (double) j, dist(i, j, point)});
        }
    }

    std::sort(graph.begin(), graph.end(), &compare);

    std::vector<int> set(n, 0);
    for(int i = 0 ; i < n ; i++) {
        set[i] = i;
    }

    double mst = 0;
    for(int i = 0 ; i < graph.size() ; i++) {
        int u = graph[i][0];
        int v = graph[i][1];

        u = findParent(u, set);
        v = findParent(v, set);
        if(u != v) {
            mst += graph[i][2];
            if(u > v) {
                set[u] = v;
            }
            else {
                set[v] = u;
            }
        }
    }

    std::cout << mst << "\n";
}