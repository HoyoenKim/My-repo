#include <iostream>
#include <string>

int main() {
    int sec[26] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
    
    std::string s;
    std::cin >> s;

    int time = 0;
    for (int i = 0 ; i < s.length() ; i++) {
        time += sec[s[i] - 'A'];
    }
    std::cout << time << "\n";
}