#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> m(n, std::vector<int>(n, 0));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            std::cin >> m[i][j];
        }
    }

    std::vector<std::vector<int>> v(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> mc(n, std::vector<int>(n, 0));
    std::vector<int> dx = {1, -1, 0, 0};
    std::vector<int> dy = {0, 0, 1, -1};

    int cityIndex = 1;
    for(int i = 0 ; i < n ; i++) {
        for(int j  = 0 ; j < n ; j++) {
            if(v[i][j] == 0 && m[i][j] == 1) {
                std::queue<std::vector<int>> q;
                v[i][j] = 1;
                mc[i][j] = cityIndex;
                q.push({i, j});
                while(!q.empty()) {
                    int x = q.front()[0];
                    int y = q.front()[1];
                    q.pop();

                    for(int k = 0 ; k < 4 ; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx >= 0 && ny >= 0 && nx <= n - 1 && ny <= n - 1 && v[nx][ny] == 0 && m[nx][ny] == 1) {
                            v[nx][ny] = 1;
                            mc[nx][ny] = cityIndex;
                            q.push({nx, ny});
                        }
                    }
                }                
                cityIndex += 1;
            }
        }
    }

    int minLength = 2 * n;
    for(int i = 0 ; i < n ; i++) {
        for(int j  = 0 ; j < n ; j++) {
            if(m[i][j] == 1) {
                int length = 2 * n;
                std::queue<std::vector<int>> q;
                std::vector<std::vector<int>> v3(n, std::vector<int>(n, 0));
                q.push({i, j, 0});
                while(!q.empty()) {
                    int x = q.front()[0];
                    int y = q.front()[1];
                    int l = q.front()[2];
                    q.pop();

                    for(int k = 0 ; k < 4 ; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx >= 0 && ny >= 0 && nx <= n - 1 && ny <= n - 1 && v3[nx][ny] == 0) {
                            v3[nx][ny] = 1;
                            if(mc[nx][ny] == 0) {
                                q.push({nx, ny, l + 1});
                            }
                            else if(mc[nx][ny] != mc[i][j] && mc[nx][ny] != 0) {
                                length = std::min(length, l);
                            }
                        }
                    }
                }
                minLength = std::min(minLength, length);                
            }
        }
    }
    std::cout << minLength << "\n";
}