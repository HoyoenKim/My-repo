#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int n,m,k;
std::vector<int> results;
bool visited[11][11];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool isVisited(int index) {
    for(int k = 0; k < 4; k++){
        int ni = index / m + dx[k];
        int nj = index % m + dy[k];
        if(ni >= 0 && ni < n && nj >= 0 && nj < m && visited[ni][nj] == true){
            return true;
        }
    }
    return false;
}
int answer = INT32_MIN;
void n_m_k(std::vector<std::vector<int>>& board,int index, int now, int sum){
    if(now == k){
        //std::cout << sum << "\n";
        answer = std::max(answer, sum);
        return;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!isVisited(i*m+j) && visited[i][j] == false) {
                visited[i][j] = true;
                n_m_k(board,i*m+j,now+1,sum+board[i][j]);
                visited[i][j] = false;
            }
        }
    }
}

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    std::cin>>n>>m>>k;
    std::vector<std::vector<int>> board(n,std::vector<int> (m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            std::cin>>x;
            board[i][j] = x;
        }
    }
    n_m_k(board, 0, 0, 0);
    std::cout<<answer<<'\n';
    return 0;
}