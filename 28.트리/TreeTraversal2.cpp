#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> inorder;
std::vector<int> postorder;
void getpreorder(int startIn, int endIn, int startPost, int endPost) {
    
    if(startIn <= endIn && startPost <= endPost) {
        //std::cout << startIn << " " << endIn <<  " " << startPost << " " << endPost << "\n";
        int root = postorder[endPost];
        std::cout << root << " ";
        int idx = -1;
        for(int i = startIn ; i <= endIn ; i++) {
            if(root == inorder[i]) {
                idx = i;
                break;
            }
        }
         //std::cout << idx << "\n";
        getpreorder(startIn,  idx - 1, startPost, startPost +  idx - startIn - 1);
        getpreorder(idx + 1, endIn, startPost + idx - startIn, endPost - 1);
    }

    
}
int main() {
    int n;
    std::cin >> n;

    for(int i = 0 ; i < n ; i++) {
        int x;
        std::cin >> x;
        inorder.push_back(x);
    }

    for(int i = 0 ; i < n ; i++) {
        int x;
        std::cin >> x;
        postorder.push_back(x);
    }

    getpreorder(0, n - 1, 0, n - 1);
    std::cout << "\n";
} 
