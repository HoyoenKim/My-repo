#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> cord(n);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> cord[i];
    }

    std::vector<int> cordSort(cord);
    std::sort(cordSort.begin(), cordSort.end());
    cordSort.erase(std::unique(cordSort.begin(), cordSort.end()), cordSort.end());

    for(int i = 0 ; i < n ; i++) {
        auto j = std::lower_bound(cordSort.begin(), cordSort.end(), cord[i]);
        std::cout << j - cordSort.begin() << " ";
    }
    std::cout << "\n";
}