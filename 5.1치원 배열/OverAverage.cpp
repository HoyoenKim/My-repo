#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    for(int i = 0 ; i < N ; i++) {
        int n;
        std::cin >> n;

        std::vector<int> score(n);
        double sum = 0;
        for(int j = 0 ; j < n ; j++) {
            int s;
            std::cin >> s;
            score[j] = s;
            sum += (double) s;
        }

        double average = sum / (double) n;
        int count = 0;
        for(int j = 0 ; j < n ; j++) {
            if ((double)score[j] > average) {
                count ++;
            }
        }

        double rate = ((double) count / (double) n) * (double) 100;
        std::cout << std::fixed;
        std::cout.precision(3);
        std::cout << rate << "%\n";
    }
}