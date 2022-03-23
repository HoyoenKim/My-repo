#include <iostream>
#include <vector>
#include <string>

class CustomQueue {
    int q_front;
    int q_rear;
    int q_size;
    std::vector<int> q;
    public:
    void push(int x);
    void pop();
    void size();
    void empty();
    void front();
    void back();
    CustomQueue() {
        q_front = 0;
        q_rear = 0;
        q_size = 0;
    }
};

void CustomQueue::push (int x) {
    q.push_back(x);
    q_rear++;
    q_size++;
}

void CustomQueue::pop () {
    if(q_size == 0) {
        std::cout << -1 << "\n";
    }
    else {
        std::cout << q[q_front] << "\n";
        q_front++;
        q_size--;
    }
}

void CustomQueue::size () {
    std::cout << q_size << "\n";
}

void CustomQueue::empty () {
    if(q_size == 0) {
        std::cout << 1 << "\n";
    }
    else {
        std::cout << 0 << "\n";
    }
}

void CustomQueue::front () {
    if(q_size == 0) {
        std::cout << -1 << "\n";
    }
    else {
        std::cout << q[q_front] << "\n";
    }
}

void CustomQueue::back () {
    if(q_size == 0) {
        std::cout << -1 << "\n";
    }
    else {
        std::cout << q[q_rear - 1] << "\n";
    }
}


int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;

    CustomQueue cq;
    for(int i = 0 ; i < n ; i++) {
        std::string order;
        std::cin >> order;

        if(order == "push") {
            int x;
            std::cin >> x;
            cq.push(x);
        }
        else if(order == "pop") {
            cq.pop();
        }
        else if(order == "size") {
            cq.size();
        }
        else if(order == "empty") {
            cq.empty();
        }
        else if(order == "front") {
            cq.front();
        }
        else if(order == "back") {
            cq.back();
        }
    }
}