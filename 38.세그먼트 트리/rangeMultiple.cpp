#include <iostream>
#include <vector>

int INTMAX = 1000000007;

long long initTree(int start, int end, int node, std::vector<long long> &array, std::vector<long long> &tree) {
    if(start == end) {
        return tree[node] = array[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = ( (initTree(start, mid, node * 2, array, tree) * initTree(mid + 1, end, node * 2 + 1, array, tree)) % INTMAX );
}

long long partialMultiple(int start, int end, int node, int min, int max, std::vector<long long> &tree) {
    if(max < start || end < min) {
        return 1;
    }
    else if(min <= start && end <= max) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return (partialMultiple(start, mid, node * 2, min, max, tree) * partialMultiple(mid + 1, end, node * 2 + 1, min, max, tree)) % INTMAX;

}

long long update(int start, int end, int node, int index, long long newN, std::vector<long long> &tree) {
    if(index < start || end < index) {
        return tree[node];
    }
    else if(start == end) {
        return tree[node] = newN;
    }
    
    int mid = (start + end) / 2;
    return tree[node] = ( (update(start, mid, node * 2, index, newN, tree) * update(mid + 1, end, node * 2 + 1, index, newN, tree)) % INTMAX );
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<long long> array(n, 0);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i];
    }

    std::vector<long long> tree(4 * n + 1, 0);
    initTree(0, n - 1, 1, array, tree);

    for(int i = 0 ; i < m + k ; i++) {
        long long a, b, c;
        std::cin >> a >> b >> c;

        if(a == 1) {
            update(0, n - 1, 1, b - 1, c, tree);
            array[b - 1] = c;
        }
        else if(a == 2) {
            std::cout << partialMultiple(0, n - 1, 1, b - 1, c - 1, tree) << "\n";
        }
    }
}