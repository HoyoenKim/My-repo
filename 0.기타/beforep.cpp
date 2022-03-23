#include <iostream>
#include <vector>

using namespace std;

vector<int> seq(10001, 0);
vector<int> visitied(10001, 0);
vector<int> answer;

int n;
int isFind = 0;
int isFinish = 0;

void findP(int t, int isSame) {
    if(isFinish) {
        return;
    }

    if(t == n) {
        if(isFind == 1) {
            isFinish = 1;
            for(int i = 0 ; i < n ; i++) {
                cout << answer[i] << " ";
            }
            cout << "\n";
        }

        if(isSame == 1) {
            isFind = 1;
        }
        return;
    }

    for(int i = n - 1 ; i >= 0 ; i--) {
        if(visitied[i] == 0) {
            visitied[i] = 1;
            answer.push_back(i + 1);
            if(seq[t] == i + 1 && (t == 0 || isSame == 1)) {
                findP(t + 1, 1);
            }
            else {
                if(isFind == 1) {
                    findP(t + 1, 0);
                }
            }
            visitied[i] = 0;
            answer.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> seq[i];
    }

    findP(0, 0);

    if(isFinish == 0) {
        cout << "-1\n";
    }
}