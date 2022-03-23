#include <iostream>
#include <vector>

int findParent(std::vector<int> &set, int a) {
    if(set[a] == a) {
        return a;
    }
    
    return set[a] = findParent(set, set[a]);
}

void unionParent(std::vector<int> &set, int a, int b) {
    a = findParent(set, a);
    b = findParent(set, b);
    if(a < b) {
        set[b] = a;
    }
    else {
        set[a] = b;
    }
}

bool isInSet(std::vector<int> &set, int a, int b) {
    a = findParent(set, a);
    b = findParent(set, b);
    if(a == b) {
        return true;
    }
    return false;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> set(n);
    for(int i = 0 ; i < n ; i++) {
        set[i] = i;
    }

    int answer = -1;
    for(int i = 0 ; i < m ; i++) {
        int x, y;
        std::cin >> x >> y;
        if(isInSet(set, x, y)) {
            answer = i;
        }

        unionParent(set, x, y);
    }

    std::cout << answer + 1<< "\n";

}