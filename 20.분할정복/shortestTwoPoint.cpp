#include <iostream>
#include <vector>
#include <algorithm>

bool compareY(std::vector<int> &a, std::vector<int> &b) {
    return a[1] < b[1];
}

bool compareX(std::vector<int> &a, std::vector<int> &b) {
    return a[0] < b[0];
}

int pointDist(std::vector<int> &a, std::vector<int> &b) {
    int dist = (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    return dist;
}
int count = 0;

std::vector<std::vector<int>> minCand;
std::vector<std::vector<int>> cord;
int findMinDist(int start, int end) {
    //std::cout << count << " start and end : " << start << " " << end << "\n";
    count ++;
    int num = end - start + 1;
    if(num == 2) {
        int dist = pointDist(cord[start], cord[end]);
        //std::cout << "dist : " << dist << "\n";
        return dist;
    }
    else if(num == 3) {
        int dist = std::min(pointDist(cord[start], cord[start + 1]), pointDist(cord[start + 1], cord[end]));
        //std::cout << "dist : " << dist << "\n";
        return dist;
    }
    else {
        int mid = (end + start) / 2;
        int d = std::min(findMinDist(mid + 1, end), findMinDist(start, mid));
        int i = 1;
        
        while(1) {
            int upper = mid + i;
            if(upper > end) {
                break;
            }
            if((cord[upper][0] - cord[mid][0])*(cord[upper][0] - cord[mid][0]) >= d) {
                break;
            }
            minCand.push_back(cord[upper]);
            i++;
        }

        i = 1;
        while(1) {
            int lower = mid - i;
            if(lower < start) {
                break;
            }
            if((cord[mid][0] - cord[lower][0])*(cord[mid][0] - cord[lower][0]) >= d) {
                break;
            }
            minCand.push_back(cord[lower]);
            i++;
        }
        minCand.push_back(cord[mid]);
        if(minCand.size() > 1) {
            std::sort(minCand.begin(), minCand.end(), &compareY);
            for(int j = 0 ; j < minCand.size() - 1; j++) {
                for(int k = j + 1 ; k < minCand.size(); k++) {
                    if((minCand[k][1] - minCand[j][1])*(minCand[k][1] - minCand[j][1])  < d) {
                        int dCand = pointDist(minCand[j], minCand[k]);
                        if(dCand < d) {
                            d = dCand;
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }
        //std::cout << "d: " << d << "\n";
        minCand.clear();
        return d;
    }
    
}

int main() {
    std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    
    int n;
    std::cin >> n;

    for(int i = 0 ; i < n ; i++) {
        int x, y;
        std::cin >> x >> y;
        cord.push_back({x, y});
    }
    std::sort(cord.begin(), cord.end(), &compareX);
    std::cout << findMinDist(0, n - 1) << "\n";
    //findMinDistWithSweeping(cord, n);    
}