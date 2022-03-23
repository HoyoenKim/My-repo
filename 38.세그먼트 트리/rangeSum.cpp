#include <iostream>
#include <vector>

long long initTree(int start, int end, int node, std::vector<long long> &array, std::vector<long long> &tree) {
    if(start == end) {
        return tree[node] = array[start];
    }
        int mid = (start + end) / 2;
        long long leftChild = initTree(start, mid, node * 2, array, tree);
        long long rightChild = initTree(mid + 1, end, node * 2 + 1, array, tree);

        return tree[node] = leftChild + rightChild;
}

long long partSum(int start, int end, int node, int min, int max, std::vector<long long> &tree) {
    if(max < start || end < min) {
        return 0;
    }
    else if(min <= start && end <= max) {
        return tree[node];
    }
    else {
        int mid = (start + end) / 2;
        return partSum(start, mid, node * 2, min, max, tree) + partSum(mid + 1, end, node * 2 + 1, min, max, tree);
    }
}

void updateTree(int start, int end, int node, int index, long long diff, std::vector<long long> &tree) {
    if(index < start || end < index) {
        return;
    }

    tree[node] += diff;
    if(start == end) {
        return;
    }
    
    int mid = (start + end) / 2;
    updateTree(start, mid, node * 2, index, diff, tree);
    updateTree(mid + 1, end, node * 2 + 1, index, diff, tree);
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
            updateTree(0, n - 1, 1, b - 1, c - array[b - 1], tree);
            array[b - 1] = c;
        }
        else if(a == 2) {
            std::cout << partSum(0, n - 1, 1, b - 1, c - 1, tree) << "\n";
        }
    }

}