#include <iostream>
#include <vector>

int initMinTree(int start, int end, int node, std::vector<int> &array, std::vector<int> &minTree) {
    if(start == end) {
        return minTree[node] = array[start];
    }
    int mid = (start + end) / 2;
    int leftChild = initMinTree(start, mid, node * 2, array, minTree);
    int rightChild = initMinTree(mid + 1, end, node * 2 + 1, array, minTree);

    return minTree[node] = std::min(leftChild, rightChild);
}

int queryMinTree(int start, int end, int node, int left, int right, std::vector<int> &minTree) {
    if(right < start || end < left) {
        return INT32_MAX;
    }
    else if(left <= start && end <= right) {
        return minTree[node];
    }

    int mid = (start + end) / 2;
    int leftChild = queryMinTree(start, mid, node * 2, left, right, minTree);
    int rightChild = queryMinTree(mid + 1, end, node * 2 + 1, left, right, minTree);

    return std::min(leftChild, rightChild);
}

int initMaxTree(int start, int end, int node, std::vector<int> &array, std::vector<int> &maxTree) {
     if(start == end) {
        return maxTree[node] = array[start];
    }
    int mid = (start + end) / 2;
    int leftChild = initMaxTree(start, mid, node * 2, array, maxTree);
    int rightChild = initMaxTree(mid + 1, end, node * 2 + 1, array, maxTree);

    return maxTree[node] = std::max(leftChild, rightChild);
}

int queryMaxTree(int start, int end, int node, int left, int right, std::vector<int> &maxTree) {
    if(right < start || end < left) {
        return 0;
    }
    else if(left <= start && end <= right) {
        return maxTree[node];
    }

    int mid = (start + end) / 2;
    int leftChild = queryMaxTree(start, mid, node * 2, left, right, maxTree);
    int rightChild = queryMaxTree(mid + 1, end, node * 2 + 1, left, right, maxTree);

    return std::max(leftChild, rightChild);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> array(n, 0);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i]; 
    }

    std::vector<int> minTree(4 * n + 1, 0);
    std::vector<int> maxTree(4 * n + 1, 0);

    initMinTree(0, n - 1, 1, array, minTree);
    initMaxTree(0, n - 1, 1, array, maxTree);

    for(int i = 0 ; i < m ; i++) {
        int left, right;
        std::cin >> left >> right;

        int minValue = queryMinTree(0, n - 1, 1, left - 1, right - 1, minTree);
        int maxValue = queryMaxTree(0, n - 1, 1, left - 1, right - 1, maxTree);

        std::cout << minValue << " " << maxValue << "\n";
    }

}