#include <iostream>
#include <vector>
#include <stack>

int BuBBleSort(std::vector<int> &array, int size) {
    for(int i = 0 ; i < size ; i++) {
        for(int j = size - 1 ; j > i ; j--) {
            if(array[j] < array[j - 1]) {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }
    return 0;
}

int SelectSort(std::vector<int> &array, int size) {
    for (int i = 0 ; i < size ; i++) {
        int min = array[i];
        int swpIndex = i;
        for(int j = i ; j < size ; j++) {
            if(array[j] < min) {
                min = array[j];
                swpIndex = j;
            }
        }
        if(swpIndex != i) {
            array[swpIndex] = array[i];
            array[i] = min;
        }
    }
    return 0;
}

int InsertSort(std::vector<int> &array, int size) {
    for (int i = 1 ; i < size ; i++) {
        int temp = array[i];
        int shiftIndex = -1;
        for(int j = i; j > 0 ; j--) {
            if(temp < array[j - 1]) {
                array[j] = array[j - 1];
            }
            else {
                shiftIndex = j;
                break;
            }
        }

        if(shiftIndex > 0) {
            array[shiftIndex] = temp;
        }
        else {
            array[0] = temp;
        }
    }
    return 0;
}

int QuickSort(std::vector<int> &array, int start, int end) {
    int pl = start;
    int pr = end;
    int pivot = (end + start) / 2;
    int x = array[pivot];

    if(end == start) {
        return 0;
    }
    else {
        while(pl <= pr) {
            while(array[pl] < x) {
                pl++;
            }
            while(x < array[pr]) {
                pr--;
            }
            if(pl <= pr) {
                int temp = array[pl];
                array[pl] = array[pr];
                array[pr] = temp;
                pl++;
                pr--;
            }
        }
    }
    if(start < pr) {
        QuickSort(array, start, pr);
    }

    if(pl < end) {
        QuickSort(array, pl, end);
    }
    return 0;
}

int QuickSortWithStack(std::vector<int> &array, int start, int end) {
    std::stack<int> lstack;
    std::stack<int> rstack;
    
    lstack.push(start);
    rstack.push(end);

    while(!lstack.empty()) {
        int start = lstack.top();
        lstack.pop();
        int end = rstack.top();
        rstack.pop();

        int pl = start;
        int pr = end;

        int x = array[(start + end)/2];

        do{
            while(array[pl] < x) {
                pl++;
            }
            while(array[pr] > x) {
                pr--;
            }

            if(pl <= pr) {
                int temp = array[pl];
                array[pl] = array[pr];
                array[pr] = temp;
                pl++;
                pr--;
            }
        } while(pl <= pr);

        if(start < pr) {
            lstack.push(start);
            rstack.push(pr);
        }

        if(pl < end) {
            lstack.push(pl);
            rstack.push(end);
        }
    }
    return 0;
}


int MergeSort(std::vector<int> &array, int start, int end) {
    if(start >= end) {
        return 0;
    }
    int center = (start + end) / 2;
    MergeSort(array, start, center);
    MergeSort(array, center + 1, end);

    std::vector<int> buffer(center - start + 1, 0);
    int i;
    int p = 0;
    for(i = start ; i <= center ; i++) {
        buffer[p++] = array[i];
    }

    int j = 0;
    int k = start;
    while(i <= end && j < p) {
        array[k++] = (buffer[j] <= array[i]) ? buffer[j++] : array[i++];
    }

    while(j < p) {
        array[k++] = buffer[j++];
    }
    return 0;
}
void downheap(std::vector<int> &array, int start, int end) {
    int temp = array[start]; // root
    int child;
    int parent;
    for(parent = start; parent < (end + 1)/2; parent = child) {
        int cl = parent * 2 + 1;
        int cr = cl + 1;

        child = (cr <= end && array[cr]> array[cl]) ? cr : cl;
        if(temp >= array[child]) {
            break;
        }
        array[parent] = array[child];
    }
    array[parent] = temp;
}

int HeapSort(std::vector<int> &array, int size) {
    // Heap 
    // 부모와 자식 사이에 일정한 크기관계가 있는 이진 트리
    // 이진 트리에서 부모: (i - 1) / 2, 자식: i*2 + 1, i*2 + 2

    for(int i = (size - 1) / 2 ; i >= 0 ; i--) {
        downheap(array, i, size - 1);
    }

    for(int i = size - 1; i > 0 ; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        downheap(array, 0, i - 1);
    }
    return 0;
}

int main() {
    int n;
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> n;
    std::vector<int> array(n);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i];
    }

    //BuBBleSort(array, n);
    //SelectSort(array, n);
    //InsertSort(array, n);
    //QuickSort(array, 0, n - 1); <- 정렬, 역 정렬된 경우 n^2의 시간이 걸린다. 이를 위해서 pivot을 중앙값으로 혹은 배열을 랜덤하게 섞는 과정을 구현하면 된다.
    //QuickSortWithStack(array, 0 , n - 1);
    MergeSort(array, 0 , n - 1);
    //HeapSort(array, n);
    for(int i = 0 ; i < n ; i++) {
        std::cout << array[i] << "\n";
    }
    return 0;
}