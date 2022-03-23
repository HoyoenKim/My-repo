#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> isPrime(2001, 1);
void findPrime() {
    isPrime[0] = 0;
    isPrime[1] = 0;
    
    for(int i = 2 ; i <= 2000 ; i++) {
        if(isPrime[i] == 1) {
            for(int j = 2 ; j <= (2000 / i) ; j++) {
                isPrime[i * j] = 0;
            }
        }
    }
}

vector<int> answer;
void printAnswer() {
    sort(answer.begin(), answer.end());
    if(answer.size() > 0) {
        for(int i = 0 ; i < answer.size() ; i++) {
            cout << answer[i] << " ";
        }
        cout << "\n";
    }
    else {
        cout << "-1\n";
    }
}

vector<int> odd;
vector<int> even;
int isStartOdd = 0;
int oddNum = 0;
int evenNum = 0;

bool findMatching(int current, vector<vector<int>> &graph, vector<int> &visited, vector<int> &matched) {
    visited[current] = 1;

    for(int i = 0 ; i < graph[current].size() ; i++) {
        int next = graph[current][i];

        if(matched[next] == -1 || visited[matched[next]] == 0 && findMatching(matched[next], graph, visited, matched)) {
            matched[next] = current;
            return true;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    if(n % 2 == 0) {
        findPrime();

        for(int i = 0 ; i < n ; i++) {
            int num;
            cin >> num;

            if(num % 2 == 0) {
                even.push_back(num);
            }
            else {
                odd.push_back(num);
                if(i == 0) {
                    isStartOdd = 1;
                }
            }
        }

        oddNum = odd.size();
        evenNum = even.size();

        /* cout << "isStartOdd : " << isStartOdd << "\nOdd: ";
        for(int i = 0 ; i < oddNum ; i++) {
            cout << odd[i] << " ";
        }

        cout << "\nEven: ";
        for(int i = 0 ; i < evenNum ; i++) {
            cout << even[i] << " ";
        }
        cout << "\n"; */

        if(isStartOdd) {
            vector<vector<int>> graph(oddNum);
            for(int i = 0 ; i < oddNum ; i++) {
                for(int j = 0 ; j < evenNum ; j++) {
                    int target = odd[i] + even[j];
                    if(isPrime[target]) {
                        graph[i].push_back(j);
                    }
                }
            }

            /* for(int i = 0 ; i < oddNum ; i++) {
                cout << i << " (" <<  odd[i] << ") -> ";
                for(int j = 0 ; j < graph[i].size() ; j++) {
                    cout << j << " (" << even[graph[i][j]] << ") ";
                }
                cout << "\n";
            } */

            for(int i = 0 ; i < graph[0].size() ; i++) {
                int matchedNumIndex = graph[0][i];
                
                int count = 1;
                vector<int> matched (evenNum, -1);
                matched[matchedNumIndex] = 0;

                for(int j = 1 ; j < oddNum ; j++) {
                    vector<int> visited (oddNum, 0);
                    visited[0] = 1;

                    if(findMatching(j, graph, visited, matched)) {
                        count += 1;
                    }
                }

                if(count == n / 2) {
                    answer.push_back(even[matchedNumIndex]);
                }
            }
        }
        else {
            vector<vector<int>> graph(evenNum);
            for(int i = 0 ; i < evenNum ; i++) {
                for(int j = 0 ; j < oddNum ; j++) {
                    int target = even[i] + odd[j];
                    if(isPrime[target]) {
                        graph[i].push_back(j);
                    }
                }
            }

            for(int i = 0 ; i < graph[0].size() ; i++) {
                int matchedNumIndex = graph[0][i];
                
                int count = 1;
                vector<int> matched (oddNum, -1);
                matched[matchedNumIndex] = 0;

                for(int j = 1 ; j < evenNum ; j++) {
                    vector<int> visited (evenNum, 0);
                    visited[0] = 1;

                    if(findMatching(j, graph, visited, matched)) {
                        count += 1;
                    }
                }

                if(count == n / 2) {
                    answer.push_back(odd[matchedNumIndex]);
                }
            }
        }


        printAnswer();
    }
    else {
        for(int i = 0 ; i < n ; i++) {
            int num;
            cin >> num;
        }
        cout << "-1\n";
    }
}