#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int n;
    std::cin >> n;

    for(int i = 0 ; i < n ; i++) {
        int m, index;
        std::cin >> m >> index;
        std::vector<int> array(m);
        std::vector<std::vector<int>> arrayWithIndex(m, std::vector<int>(2, 0));
        std::queue<std::vector<int>> q;
        
        for(int j = 0 ; j < m ; j++) {
            std::cin >> array[j];
            arrayWithIndex[j][0] = array[j];
            arrayWithIndex[j][1] = j;
            q.push(arrayWithIndex[j]);
        }

        std::sort(array.begin(), array.end(), &compare);
        int startIndex = 0;
        int printNum = 0;
        while(1) {
            //std::cout << "find : " << array[startIndex] << " / " << q.front()[0] << " " << q.front()[1] << "\n";
            if(q.front()[0] == array[startIndex]) {
                printNum++;
                startIndex++;
                if(q.front()[1] == index) {
                    break;
                }
                q.pop();
            }
            else {
                q.push(q.front());
                q.pop();
            }
        }

        std::cout << printNum << "\n";
    }
}