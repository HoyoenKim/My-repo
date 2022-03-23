#include <iostream>
#include <vector>

int n, m;
int findParent(std::vector<int> &set, int a) {
    if(set[a] == a) {
        return a;
    }
    else {
        return set[a] = findParent(set, set[a]);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    
    std::vector<int> set(n + 1);
    for(int i = 0 ; i <= n ; i++) {
        set[i] = i;
    }

    for(int i = 0 ; i < m ; i++){
        int order, a, b;
        std::cin >> order >> a >> b;

        int pA = findParent(set, a);
        int pB = findParent(set, b);
        if(order == 0) {    
            if(pA > pB) {
                set[pA] = pB;
            }
            else{
                set[pB] = pA;
            }
        }
        else if(order == 1) {
            if(pA == pB) {
                std::cout << "YES\n";
            }
            else {
                std::cout << "NO\n";
            }
        }
    }
}