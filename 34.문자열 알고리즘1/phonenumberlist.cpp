#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int pointerNum = 10;
struct Trie {
    Trie* child[pointerNum];
    int isEnd;
    int isChild;

    Trie() {
        fill(child, child + pointerNum, nullptr);
        isEnd = 0;
        isChild = 0;
    }

    ~Trie() {
        for(int i = 0 ; i < pointerNum ; i++) {
            if(child[i]) {
                delete child[i];
            }
        }
    }

    void insert (const char* key) {
        if(*key == '\0') {
            isEnd = 1;
        }
        else {
            int next = *key - '0';
            if(!child[next]) {
               child[next] = new Trie;
            } 
            isChild = 1;
            child[next]->insert(key + 1);
        }
    }

    bool isConsisence() {
        if(isChild && isEnd) {
            return false;
        }

        for(int i = 0 ; i < pointerNum ; i++) {
            if(child[i] && !child[i]->isConsisence()) {
                return false;
            }
        }

        return true;
    }
};


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        Trie *root = new Trie;
        for(int i = 0 ; i < n ; i++) {
            char phonenum[11];
            cin >> phonenum;
            root->insert(phonenum);
        }
        if(root->isConsisence()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        delete root;
    }
}