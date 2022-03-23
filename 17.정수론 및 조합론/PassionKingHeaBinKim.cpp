#include <iostream>
#include <string>
#include <map>

int main() {
    int n;
    std::cin >> n;

    for(int i = 0 ; i < n ; i++) {
        int k;
        std::cin >> k;
        std::map<std::string, int> m;
        for(int j = 0 ; j < k ; j++) {
            std::string s1, s2;
            std::cin >> s1 >> s2;

            if(m.size() == 0) {
               m[s2] = 1;
            }
            else {
                if(m.find(s2) != m.end()) {
                    m[s2] += 1;
                } else{
                    m[s2] = 1;
                }
            }
        }

        int num = 1;
        for(const auto &item : m) {
            num *= item.second + 1;
        }

        std::cout << num - 1 << "\n";
    }
    

}
