#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

bool compare(std::tuple<int, int, std::string> a, std::tuple<int, int, std::string> b) {
    int a0 = std::get<0>(a);
    int b0 = std::get<0>(b);

    int a1 = std::get<1>(a);
    int b1 = std::get<1>(b);

    if(a0 != b0) {
        return a0 < b0;
    }
    else {
        return a1 < b1;
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::tuple<int, int, std::string>> array(n);
    for(int i = 0 ; i < n ; i++) {
        int old;
        std::string name;
        std::cin >> old >> name;
        array[i] = {old, i, name};
    }

    std::sort(array.begin(), array.end(), &compare);
    for(int i = 0 ; i < n ; i++) {
        std::cout << std::get<0>(array[i]) << " " << std::get<2>(array[i]) << "\n";
    }
}