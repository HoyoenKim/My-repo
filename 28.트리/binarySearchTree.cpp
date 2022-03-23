#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> preorder;
std::vector<int> inorder;
std::vector<int> postorder;
void getPostOrder(int preStart, int preEnd, int inStart, int inEnd) {
    if(preStart <= preEnd && inStart <= inEnd) {
        //std::cout << preStart << " " << preEnd << " " << inStart << " " << inEnd << "\n";
        int root = preorder[preStart];
        postorder.push_back(root);
        int idx = 0;
        for(int i = inStart ; i <= inEnd ; i++) {
            if(inorder[i] == root) {
                idx = i;
                break;
            }
        }
        //std::cout << root << "\n";
        getPostOrder(preStart + 1 + idx - inStart, preEnd, idx + 1, inEnd);
        getPostOrder(preStart + 1, preStart + idx - inStart, inStart, idx - 1);
    }
}

int main() {
    int x;
    while(std::cin >> x) {
        preorder.push_back(x);
        inorder.push_back(x);
    }
    std::sort(inorder.begin(), inorder.end());

    int n = preorder.size();
    getPostOrder(0, n - 1 , 0, n - 1);

    for(int i = n - 1 ; i >= 0 ; i--) {
        std::cout << postorder[i] << "\n";
    }
}