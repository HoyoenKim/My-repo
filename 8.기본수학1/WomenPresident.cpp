#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    for (int i = 0 ; i < N ; i++) {
        int a, b;
        std::cin >> a;
        std::cin >> b;
        std::vector<int> apartP(b, 0);

        for(int i = 0 ; i <= a ; i++) {
            std::vector<int> tempApartP(b, 0);
            if (i == 0) {
                for(int j = 0 ; j < b ; j++) {
                    tempApartP[j] = j + 1;
                }
            }
            else {
                for(int j = 0 ; j < b ; j++) {
                    for(int k = 0 ; k < j + 1 ; k++) {
                        tempApartP[j] += apartP[k];
                    }
                }
            }
            std::copy(tempApartP.begin(), tempApartP.end(), apartP.begin());
        }

        std::cout << apartP[b-1] << "\n";
    }
}