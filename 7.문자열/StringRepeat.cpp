#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;

    for (int i = 0 ; i < N ; i++) {
        int n;
        std::cin >> n;

        std::string repeat;
        std::cin >> repeat;
        for(int j = 0 ; j < repeat.length() ; j++) {
            for (int k = 0 ; k < n ; k++) {
                std::cout << repeat[j];
            }
        }
        std::cout << "\n";
    }
}