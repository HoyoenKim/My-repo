#include <iostream>
#include <vector>

int getNum(int now, std::vector<std::vector<int>> &tree, std::vector<int> &number) {
    number[now] = 1;
    int ret = 1;
    for(int i = 0 ; i < tree[now].size() ; i++) {
        int next = tree[now][i];
        if(number[next] == 0) {
            ret += getNum(next, tree, number);
        }
    }
    number[now] = ret;
    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int n, r, q;
    std::cin >> n >> r >> q;

    std::vector<std::vector<int>> tree(n + 1);
    for(int i = 0 ; i < n - 1 ; i++) {
        int u, v;
        std::cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    std::vector<int> number(n + 1, 0);
    number[r] = getNum(r, tree, number);

    for(int i = 0 ; i < q ; i++) {
        int u;
        std::cin >> u;
        std::cout << number[u] << "\n";
    }
}