#include <iostream>
#include <vector>
#include <algorithm>

bool compare (std::vector<int> &a, std::vector<int> &b) {
    return a[0] < b[0];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n, std::vector<int> (2, 0));
    for(int i = 0 ; i < n ; i++) {
        int x, y;
        std::cin >> x >> y;
        graph[i] = {x, y};
    }

    std::sort(graph.begin(), graph.end(), &compare);

    int rangeStart = 0;
    int rangeEnd = 0;
    int isInit = 1;
    int len = 0;

    for(int i = 0 ; i < n ; i++) {
        int left = graph[i][0];
        int right = graph[i][1];

        if(isInit) {
            isInit = 0;
            rangeStart = left;
            rangeEnd = right; 
        }
        else {
            if(left <= rangeEnd) {
                if(rangeEnd < right) {
                    rangeEnd = right;
                }
            }
            else {
                len += rangeEnd - rangeStart;
                rangeStart = left;
                rangeEnd = right;
            }
        }
    }
    len += rangeEnd - rangeStart;
    std::cout << len << "\n";
}