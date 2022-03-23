#include <iostream>
#include <vector>
#include <algorithm>

int n, c;
std::vector<int> t1;
std::vector<int> t1Flag;
int t1Size;

std::vector<int> t2;
std::vector<int> t2Flag;
int t2Size;

unsigned long long count = 0;
std::vector<int> cnt1;
std::vector<int> cnt2;

void findT1(int beforeIndex, int beforeW, int beforeBitIndex) {
    for(int i = beforeIndex ; i < t1Size ; i++) {
        if(t1Flag[i] == 0) {
            if(beforeW + t1[i] <= c) {
                cnt1.push_back(beforeW + t1[i]);
                count += 1;
                t1Flag[i] = 1;
                findT1(i, beforeW + t1[i], beforeBitIndex + (1 << i));
                t1Flag[i] = 0;
            }
        }
    }
}

void findT2(int beforeIndex, int beforeW, int beforeBitindex) {
    for(int i = beforeIndex ; i < t2Size ; i++) {
        if(t2Flag[i] == 0) {
            if(beforeW + t2[i] <= c) {
                cnt2.push_back(beforeW + t2[i]);
                count += 1;
                t2Flag[i] = 1;
                findT2(i, beforeW + t2[i], beforeBitindex + (1 << i));
                t2Flag[i] = 0;
            }
        }
    }
}

int main() {
    std::cin >> n >> c;

    for(int i = 0 ; i < n / 2 ; i++) {
        int t;
        std::cin >> t;
        t1.push_back(t);
        t1Flag.push_back(0);
    }
    t1Size = t1.size();

    for(int i = n / 2 ; i < n ; i++) {
        int t;
        std::cin >> t;
        t2.push_back(t);
        t2Flag.push_back(0);
    }
    t2Size = t2.size();
    
    findT1(0, 0, 0);
    findT2(0, 0, 0);

    std::sort(cnt1.begin(), cnt1.end());
    std::sort(cnt2.begin(), cnt2.end());
    for(int i = 0 ; i < cnt1.size() ; i++) {
        for(int j = 0 ; j < cnt2.size() ; j++) {
            if(cnt1[i] != 0 && cnt2[j] != 0) {
                if(cnt1[i] + cnt2[j] <= c) {
                    count += 1;
                }
                else {
                    break; 
                }
            }
        }
    }   
    std::cout << count + 1<< "\n";
}