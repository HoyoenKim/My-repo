#include <iostream>
#include <vector>

class CustomHeap {
    // 부모 > 왼쪽 자식, 오른쪽 자식 or < ...
    // 부모 i -> 왼쪽 자식: 2*i + 1, 오른쪽 자식: 2*i + 2;
    // 자식 i -> 부모: (i - 1) / 2;
    int h_size;
    std::vector<int> ct_heap;
    public:
    void heap_push(int x);
    void heap_pop();
    void heap_top();
    bool heap_empty();
    CustomHeap() {
        h_size = -1;
        std::vector<int> temp(100000, 0);
        ct_heap = temp;
    }
};

bool compare(int parent, int child) {
    return parent < child;
}

bool CustomHeap::heap_empty() {
    if(h_size < 0) {
        return true;
    }
    else {
        return false;
    }
}

void CustomHeap::heap_top() {
    if(h_size >= 0) {
        std::cout << ct_heap[0] << "\n";
    }
}

void CustomHeap::heap_push(int x) {
    h_size += 1;
    ct_heap[h_size] = x;

    // 맨 아래에 새로운 원소를 삽입, 부모와의 비교를 통해서 더 크면 교환 아니면 종료
    int start = h_size;
    while(start > 0) {
        int parent = (start - 1) / 2;
        if(compare(ct_heap[parent], ct_heap[start])) {
            int temp = ct_heap[start];
            ct_heap[start] = ct_heap[parent];
            ct_heap[parent] = temp;
            start = parent;
        }
        else {
            break;
        }
    }
}

void CustomHeap::heap_pop() {
    ct_heap[0] = ct_heap[h_size];
    h_size -= 1;

    // 맨 위 원소를 삭제 후 맨 아래 원소를 맨 위로 올림. 자식과의 비교를 통해서 더 작으면 교환 아니면 종료
    int start = 0;
    while(start <= (h_size - 1) / 2) {
        int childLeft = start * 2 + 1;
        int childRight = start * 2 + 2;
        int child = childLeft;
        if(childRight <= h_size) {
            if(compare(ct_heap[childLeft], ct_heap[childRight])) {
                child = childRight;
            }
        }
        if(compare(ct_heap[start], ct_heap[child])) {
            int temp = ct_heap[start];
            ct_heap[start] = ct_heap[child];
            ct_heap[child] = temp;
            start = child;
        }
        else {
            break;
        }
    }
}

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    CustomHeap ch;

    for(int i = 0 ; i < n ; i++) {
        int j;
        std::cin >> j;
        if(j == 0) {
            if(ch.heap_empty()) {
                std::cout << 0 << "\n";
            }
            else {
                ch.heap_top();
                ch.heap_pop();
            }
        }
        else {
            ch.heap_push(j);
        }
    }
}