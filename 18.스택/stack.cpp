#include <iostream>
#include <vector>
#include <string>

class CustomStack{
    int stk_index;
    std::vector<int> stk;

    public:
    void push(int x);
    void pop();
    void size();
    void empty();
    void top();

    CustomStack() {
        stk_index = -1;
    }
};

void CustomStack::push(int x) {
    stk.push_back(x);
    stk_index++;
}

void CustomStack::pop() {
    if(stk_index == -1) {
        std::cout << - 1 << "\n";
    }
    else {
        std::cout << stk[stk_index] << "\n";
        stk.erase(stk.begin() + stk_index);
        stk_index--;
    }
}

void CustomStack::size() {
    std::cout << stk_index + 1 << "\n";
}

void CustomStack::empty() {
    if(stk_index == -1) {
        std::cout << 1 << "\n";
    }
    else {
        std::cout << 0 << "\n";
    }
}

void CustomStack::top() {
    if(stk_index == -1) {
        std::cout << -1 << "\n";
    }
    else {
        std::cout << stk[stk_index] << "\n";
    }
}

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;

    CustomStack cs;
    for(int i = 0 ; i < n ; i++) {
        std::string order;
        std::cin >> order;
        if(order == "push") {
            int x;
            std::cin >> x;
            cs.push(x);
        }
        else if(order == "pop") {
            cs.pop();
        }
        else if(order == "size") {
            cs.size();
        }
        else if(order == "empty") {
            cs.empty();
        }
        else if(order == "top") {
            cs.top();
        }
    }
}