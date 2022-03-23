#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;

    for (int i = 0 ; i < N ; i++) {
        std::string answer;
        std::cin >> answer;

        int scoreSum = 0;
        int score = 0;
        for(int j = 0 ; j < answer.length() ; j++) {
            if (answer[j] == 'O') {
                score ++;
            }
            else {
                score = 0;
            }
            scoreSum += score;
        }
        std::cout << scoreSum << "\n";
    }
}