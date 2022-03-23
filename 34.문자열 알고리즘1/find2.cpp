#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

int main() {
    string t, p;
    getline(cin, t);
    getline(cin, p);
    
    int psize = p.size();
    vector<int> failtable(psize, 0); 
    int j = 0;
    for(int i = 1 ; i < psize ; i++) {
        while(j > 0 && p[i] != p[j]) {
            j = failtable[j - 1];
        }
        if(p[i] == p[j]) {
            j += 1;
            failtable[i] = j;
        }
    }

    for(int i = 0 ; i < psize ; i++) {
        cout << i << " " << failtable[i] << "\n";
    }
}