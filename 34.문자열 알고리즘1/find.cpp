#include <iostream>
#include <vector>
#include <string>

// Knuth-Morris-Pratt 접두사와 접미사를 이용해 매칭할 문자열을 빠르게 점프한다.
// (aba)ca(aba)
//  prefix suffix

// 접두사와 접미사가 일치하는 최대 길이를 구한다.
// abacaaba
// a 0
// ab 0
// (a)b(a) 1
// abac 0
// (a)bac(a) 1
// (a)baca(a) 1
// (ab)aca(ab) 2
// (aba)ca(aba) 3

// abacaaba -> [0, 0, 1, 0, 1, 1, 2, 3]

std::vector<int> makeTable(std::string p) {
    int pSize = p.length();
    std::vector<int> ret(pSize, 0);
    int j = 0;

    for(int i = 1 ; i < pSize ; i++) {
        while(j > 0 && p[i] != p[j]) {
            j = ret[j - 1];
        }
        if(p[i] == p[j]) {
            j += 1;
            ret[i] = j;
        }
    }

    return ret;
}

int main() {
    std::string T, P;
    std::getline(std::cin, T);
    std::getline(std::cin, P);
    
    int Tsize = T.size();
    int Psize = P.size();

    std::vector<int> table = makeTable(P);
    int j = 0;
    int count = 0;
    std::vector<int> index;
    for(int i = 0 ; i < Tsize ; i++) {
        while(j > 0 && T[i] != P[j]) {
            j = table[j - 1];
        }
        if(T[i] == P[j]) {
            if(j == Psize - 1) {
                index.push_back(i - Psize + 2);
                count += 1;
                j = table[j];
            }
            else {
                j++;
            }
        }
    }

    std::cout << count << "\n";
    for(int i = 0 ; i < index.size() ; i++) {
        std::cout << index[i] << " ";
    }
    std::cout << "\n";
}