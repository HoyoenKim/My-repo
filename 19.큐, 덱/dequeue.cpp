#include <iostream>
#include <vector>
#include <string>

class Dequeue {
    int dq_front;
    int dq_rear;
    std::vector<int> dq;

    public:
    void push_front(int x);
    void push_back(int x);
    void pop_front();
    void pop_back();
    void size();
    void empty();
    void front();
    void back();

    Dequeue() {
        dq_front = 10000;
        dq_rear = 10000;
        std::vector<int> temp(20000, 0);
        dq = temp;
    }
};

void Dequeue::push_front(int x) {
    dq_front--;
    dq[dq_front] = x;
    //std::cout << dq_front << "\n";
}

void Dequeue::push_back(int x) {
    dq[dq_rear] = x;
    dq_rear++;
    //std::cout << dq_rear << "\n";
}

void Dequeue::pop_front() {
    if(dq_front < dq_rear) {
        std::cout << dq[dq_front] << "\n";
        dq_front++;
    }
    else {
        std::cout << -1 << "\n";
    }
}

void Dequeue::pop_back() {
    if(dq_front < dq_rear) {
        std::cout << dq[dq_rear - 1] << "\n";
        dq_rear--;
    }
    else {
        std::cout << -1 << "\n";
    }
}

void Dequeue::size() {
    std::cout << dq_rear - dq_front << "\n";
}

void Dequeue::empty() {
    if(dq_front == dq_rear) {
        std::cout << 1 << "\n";
    }
    else {
        std::cout << 0 << "\n";
    }
}

void Dequeue::front() {
    //std::cout << dq_front << " " << dq_rear;
    if(dq_front < dq_rear) {
        std::cout << dq[dq_front] << "\n";
    }
    else {
        std::cout << -1 << "\n";
    }

}

void Dequeue::back() {
    if(dq_front < dq_rear) {
        std::cout << dq[dq_rear - 1] << "\n";
    }
    else {
        std::cout << -1 << "\n";
    }
}

int main() {
    int n;
    std::cin >> n;
    Dequeue Dequeue;
    for(int i = 0 ; i < n ; i++) {
        std::string order;
        std::cin >> order;
        if(order == "push_front") {
            int x;
            std::cin >> x;
            Dequeue.push_front(x);
        }
        else if(order == "push_back")  {
            int x;
            std::cin >> x;
            Dequeue.push_back(x);
        }
        else if(order == "pop_front") {
            Dequeue.pop_front();
        }
        else if(order == "pop_back") {
            Dequeue.pop_back();
        }
        else if(order == "size") {
            Dequeue.size();
        }
        else if(order == "empty") {
            Dequeue.empty();
        }
        else if(order == "front") {
            Dequeue.front();
        }
        else if(order == "back") {
            Dequeue.back();
        }
    }
}

