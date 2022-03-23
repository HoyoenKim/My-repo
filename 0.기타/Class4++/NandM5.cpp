#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> visited(9, 0);
std::vector<int> answer;
int n, m;
void permutation(int index, std::vector<int> &array) {
    if(index == m) {
        for(int i = 0 ; i < m ; i++) {
            std::cout << answer[i] << " ";
        }
        std::cout << "\n";
    }
    else{
        for(int i = 0 ; i < n ; i++) {
            if(visited[i] == 0) {
                visited[i] = 1;
                answer.push_back(array[i]);
                permutation(index + 1, array);
                visited[i] = 0;
                answer.pop_back();
            }
        }
    }
}

int main() {
    std::cin >> n >> m;
    std::vector<int> array(n, 0);
    for(int i = 0 ; i < n ; i++) {
        std::cin >> array[i];
    }

    std::sort(array.begin(), array.end());
    permutation(0, array);
}