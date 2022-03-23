#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

bool compare(std::vector<int> &a, std::vector<int> &b) {
    return a[2] < b[2];
}

int getParent(int a, std::vector<int> &set) {
    if(set[a] == a) {
        return set[a];
    }
    else {
        return set[a] = getParent(set[a], set);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> map(n, std::vector<int> (m, 0));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            std::cin >> map[i][j];
        }
    }

    std::vector<std::vector<int>> mapIndex(n, std::vector<int> (m, 0));
    std::vector<std::vector<int>> visited(n, std::vector<int> (m, 0));
    std::vector<int> dx = {1, -1, 0, 0};
    std::vector<int> dy = {0, 0, 1, -1};

    int cityIndex = 1;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(visited[i][j] == 0 && map[i][j] == 1) {
                std::queue<std::vector<int>> q;
                mapIndex[i][j] = cityIndex;
                visited[i][j] = 1;
                q.push({i, j});
                
                while(!q.empty()) {
                    int x = q.front()[0];
                    int y = q.front()[1];
                    q.pop();

                    for(int k = 0 ; k < 4 ; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if(nx >= 0 && ny >= 0 && nx <= n - 1 && ny <= m - 1 && visited[nx][ny] == 0) {
                            if(map[nx][ny] == 1) {
                                mapIndex[nx][ny] = cityIndex;
                                visited[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }
                }

                cityIndex += 1;
            }
        }
    }

    /*
    std::cout << "\n";
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++){
            std::cout << mapIndex[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << cityIndex << "\n";
    */
   
    int INF = 10000;
    std::vector<std::vector<int>> graph(cityIndex, std::vector<int> (cityIndex, INF));
    for(int i = 0 ; i < n ; i++) {
        int beforeCity = -1;
        int beforeCityIndex = -1;
        int currentCity = -1;
        for(int j = 0 ; j < m ; j++) {
            if(mapIndex[i][j] != 0) {
                if(beforeCity == -1) {
                    beforeCity = mapIndex[i][j];
                    beforeCityIndex = j;
                }
                else {
                    if(mapIndex[i][j] == beforeCity) {
                        beforeCityIndex = j;
                    }
                    else if (mapIndex[i][j] != 0) {
                        currentCity = mapIndex[i][j];
                        //std::cout << beforeCity << " " << currentCity << " " << j - beforeCityIndex - 1 << "\n";
                        if(j - beforeCityIndex - 1 >= 2) {
                            graph[beforeCity][currentCity] = std::min(graph[beforeCity][currentCity], j - beforeCityIndex - 1);
                            //graph[currentCity][beforeCity] = std::min(graph[currentCity][beforeCity], j - beforeCityIndex - 1);
                        }
                        beforeCity = currentCity;
                        beforeCityIndex = j;
                    }
                }
            }
        }
    }


    for(int j = 0 ; j < m ; j++) {
        int beforeCity = -1;
        int beforeCityIndex = -1;
        int currentCity = -1;
        for(int i = 0 ; i < n ; i++) {
            if(mapIndex[i][j] != 0) {
                if(beforeCity == -1) {
                    beforeCity = mapIndex[i][j];
                    beforeCityIndex = i;
                }
                else {
                    if(mapIndex[i][j] == beforeCity) {
                        beforeCityIndex = i;
                    }
                    else if (mapIndex[i][j] != 0) {
                        currentCity = mapIndex[i][j];
                        //std::cout << beforeCity << " " << currentCity << " " << i - beforeCityIndex - 1 << "\n";
                        if(i - beforeCityIndex - 1 >= 2) {
                            graph[beforeCity][currentCity] = std::min(graph[beforeCity][currentCity], i - beforeCityIndex - 1);
                            //graph[currentCity][beforeCity] = std::min(graph[currentCity][beforeCity], i - beforeCityIndex - 1);
                        }
                        beforeCity = currentCity;
                        beforeCityIndex = i;
                    }
                }
            }
        }
    }

    std::vector<std::vector<int>> dist;
    for(int i = 0 ; i < cityIndex ; i++) {
        for(int j = 0 ; j < cityIndex ; j++) {
            if(graph[i][j] != INF && graph[i][j] >= 2) {
                //std::cout << i << " " << j << " " << graph[i][j] << "\n"; 
                dist.push_back({i, j, graph[i][j]});
            }
            //std::cout << graph[i][j] << " ";
        }
        //std::cout << "\n";
    }

    std::sort(dist.begin(), dist.end(), &compare);
    std::vector<int> set(cityIndex, 0);
    for(int i = 0 ; i < cityIndex ; i++) {
        set[i] = i;
    }

    int answer = 0;
    int count = 0;
    for(int i = 0 ; i < dist.size() ; i++) {
        int a = dist[i][0];
        int b = dist[i][1];
        //std::cout << a << " " << b << " " << dist[i][2] << "\n"; 

        a = getParent(a, set);
        b = getParent(b, set);

        if(a != b) {
            count += 1;
            answer += dist[i][2];
            if(a < b) {
                set[b] = a;
            }
            else {
                set[a] = b;
            }
        }
    }

    if(count == cityIndex - 2) {
        std::cout << answer << "\n";
    }
    else {
        std::cout << "-1\n";
    }

}