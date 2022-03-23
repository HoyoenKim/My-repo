#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;

    std::vector<int> isCroatia(s.length(), 1);
    int count = 0;

    for (int i = 0 ; i < s.length() - 1 ; i++) {
        if((s[i] == 'c')&&(s[i+1] == '=' || s[i+1] == '-')) {
            count++;
            isCroatia[i] = 0;
            isCroatia[i+1] = 0;
        }

        if(s[i] == 'd') {
            if (s[i+1] == '-') {
                count++;
                isCroatia[i] = 0;
                isCroatia[i+1] = 0;
            }

            if (s[i+1] == 'z' && i+2 < s.length()) {
                if (s[i+2] == '=') {
                    count++;
                    isCroatia[i] = 0;
                    isCroatia[i+1] = 0;
                    isCroatia[i+2] = 0;
                }
            }
        }

        if((s[i] == 'l' || s[i] == 'n') && s[i+1] == 'j') {
            count++;
            isCroatia[i] = 0;
            isCroatia[i+1] = 0;
        }
        
        if(isCroatia[i] != 0 && (s[i] == 's' || s[i] == 'z') && s[i+1] == '=') {
            count++;
            isCroatia[i] = 0;
            isCroatia[i+1] = 0;
        }
    }

    for (int i = 0 ; i < isCroatia.size() ; i++) {
        if (isCroatia[i] == 1) {
            count++;
        }
    }

    std::cout << count << "\n";
}