#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> binarySearch(std::vector<int> array, int find) {
    std::vector<int> ret(3, 0);
    int low = 0;
    int high = array.size() - 1;
    if(find <= array[low]) {
        if(array[low] == find) {
            ret[0] = 1;
            ret[1] = low;
            ret[2] = low;
        }
        else {
            ret[0] = 0;
            ret[1] = low;
            ret[2] = low -1;
        }
    }
    else if(find >= array[high]) {
        if(array[high] == find) {
            ret[0] = 1;
            ret[1] = high;
            ret[2] = high - 1;
        }
        else {
            ret[0] = 0;
            ret[1] = high;
            ret[2] = high - 1;
        }
    }
    else {
        while(low <= high) {
            int mid = (high + low)/2;
            if(array[mid] == find) {
                ret[0] = 1;
                ret[1] = mid;
                ret[2] = mid;
                break;
            }
            else if(array[mid] < find) {
                low = mid + 1;
                ret[1] = low;
                ret[2] = high;
            }
            else if(array[mid] > find) {
                high = mid - 1;
                ret[1] = low;
                ret[2] = high;

            }
        }
    }
    

    return ret;
}

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<int> array(n);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i];
    }
    std::sort(array.begin(), array.end());

    int m;
    std::cin >> m;
    for(int i = 0 ; i < m ; i++) {
        int find;
        std::cin >> find;
        //std::cout << binarySearch(array, find)[0] <<"\n";
        std::cout << (array[std::lower_bound(array.begin(), array.end(), find) - array.begin()] == find) << "\n";
        //std::cout << find << " : " << std::lower_bound(array.begin(), array.end(), find) - array.begin() << "\n";
    }


}