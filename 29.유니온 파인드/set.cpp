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

bool isInset(std::vector<int> &set, int a, int b) {
    a = findParent(set, a);
    b = findParent(set, b);
    if(a == b) {
        return true;
    }
    return false;

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> set(n + 1, 0);
    for(int i = 0 ; i <= n ; i++) {
        set[i] = i;
    }

    for(int i = 0 ; i < m ; i++) {
        int order, x, y;
        std::cin >> order >> x >> y;
        if(order == 0) {
            unionParent(set, x, y);
        }
        else if(order == 1) {
            if(isInset(set, x, y)) {
                std::cout << "YES\n";
            }
            else {
                std::cout << "NO\n";
            }
        }
    }
}