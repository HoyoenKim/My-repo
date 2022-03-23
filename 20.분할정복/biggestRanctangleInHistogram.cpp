#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

unsigned long long getMaxArea(std::vector<int> array, int start, int end) {
    //std::cout << start << " " << end << "\n";
    //세그먼트 트리 없이는 최악의 경우 시간 복잡도가 n^2이 된다. 평균은 nlogn
    int minIndex = std::min_element(array.begin() + start, array.begin() + end + 1) - array.begin();
    int localMin = array[minIndex];

    unsigned long long maxArea = (unsigned long long) (end - start + 1) * (unsigned long long) localMin;
    if(start <= minIndex - 1) {
        maxArea = std::max(maxArea, getMaxArea(array, start, minIndex - 1));
    }
    
    if(end >= minIndex + 1) {
        maxArea = std::max(maxArea, getMaxArea(array, minIndex + 1, end));
    }
    return maxArea;
}

unsigned long long getMaxArea2(std::vector<int> array, int n) {
    std::stack<int> st;
    unsigned long long maxArea = 0;
    
    for(int i = 0 ; i < n ; i++) {
        while(!st.empty() && array[st.top()] > array[i]) {
            unsigned long long h = (unsigned long long) array[st.top()];
            st.pop();
            unsigned long long w = (unsigned long long) i;
            if(!st.empty()) {
                w = (unsigned long long) (i - st.top() - 1);
            }
            unsigned long long area = h * w;
            //std::cout << area << "\n";
            if(area > maxArea) {
                maxArea = area;
            }
                
        }
        st.push(i);
    }

    while(!st.empty()) {
        unsigned long long h = (unsigned long long) array[st.top()];
        st.pop();
        unsigned long long w = (unsigned long long) n;
        if(!st.empty()) {
            w = (unsigned long long) (n - st.top() - 1);
        }
        unsigned long long area = h * w;
        //std::cout << area << "\n";
        if(area > maxArea) {
            maxArea = area;
        }
    }

    return maxArea;
} 

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    while(1) {
        int n;
        std::cin >> n;
        if(n == 0) {
            break;
        }

        std::vector<int> array(n, 0);
        for(int i = 0 ; i < n ; i++) {
            std::cin >> array[i];
        }

        unsigned long long maxArea = getMaxArea2(array, n);
        std::cout << maxArea << "\n";
    }
}