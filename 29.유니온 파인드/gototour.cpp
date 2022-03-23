#include <iostream>
#include <vector>

int findParent(int i, std::vector<int> &set) {
    if(set[i] == i) {
        return set[i];
    }
    return set[i] = findParent(set[i], set);
}

void unionParent(int i, int j, std::vector<int> &set) {
    i = findParent(i, set);
    j = findParent(j, set);
    if(i < j) {
        set[j] = i;
    }
    else {
        set[i] = j;
    }
}

int main() {
    int n; // 도시의 수
    std::vector<int> set(n + 1, 0);
    for(int i = 1 ; i <= n ; i++) {
        set[i] = i;
    }
    int m; // 여행 계획에 속한 도시의 수
    std::cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            int isLinked;
            std::cin >> isLinked;
            if(isLinked == 1) {
                unionParent(i, j, set);
            }
        }
    }
    int beforeCity = -1;
    int isPossible = 1;
    for(int i = 0 ; i < m ; i++) {
        int currentCity;
        std::cin >> currentCity;
        if(beforeCity > 0) {
            int a = findParent(beforeCity, set);
            int b = findParent(currentCity, set);
            if(a != b) {
                isPossible = 0;
            }
        }
        beforeCity = currentCity;
    }

    if(isPossible) {
        std::cout << "YES\n";
    }
    else {
        std::cout << "NO\n";
    }

}