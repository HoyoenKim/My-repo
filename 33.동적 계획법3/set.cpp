#include <iostream>
#include <vector>

class customSet {
    unsigned long long set;
    public:
    void add(int x);
    void remove(int x);
    void check(int x);
    void toggle(int x);
    void all();
    void empty();
    customSet() {
        set = 0;
    }
};

void customSet::add(int x) {
    set = set | ((unsigned long long)1 << x);
}

void customSet::remove(int x) {
     if((set & ((unsigned long long)1 << x)) == (unsigned long long)1 << x) {
        set = set ^ ((unsigned long long)1 << x);
    }
}

void customSet::toggle(int x) {
    set = set ^ ((unsigned long long)1 << x);
}

void customSet::check(int x) {
    if((set & ((unsigned long long)1 << x)) == (unsigned long long)1 << x) {
        std::cout << 1 << "\n";
    }
    else {
        std::cout << 0 << "\n";
    }
}

void customSet::all() {
    for(int i = 1 ; i <= 20 ; i++) {
        set = set | ((unsigned long long)1 << i);
    }
}

void customSet::empty() {
    set = set & 0;
}

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    customSet cs;
    for(int i = 0 ; i < n ; i++) {
        std::string order;
        std::cin >> order;
        
        if(order == "add") {
            int x;
            std::cin >> x;
            cs.add(x);
        }
        else if(order == "remove") {
            int x;
            std::cin >> x;
            cs.remove(x);
        }
        else if(order == "check") {
            int x;
            std::cin >> x;
            cs.check(x);
        }
        else if(order == "toggle") {
            int x;
            std::cin >> x;
            cs.toggle(x);
        }
        else if(order == "all") {
            cs.all();
        }
        else if(order == "empty") {
            cs.empty();
        }
    }
}