#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

void preorder(std::vector<std::vector<std::vector<int>>> &graph, int parent, std::string &s) {
    s += (char) (parent + 'A');
    if(graph[parent].size() == 1) {
        preorder(graph, graph[parent][0][0], s);
    }
    else if(graph[parent].size() == 2) {
        preorder(graph, graph[parent][0][0], s);
        preorder(graph, graph[parent][1][0], s);
    }
}

void inorder(std::vector<std::vector<std::vector<int>>> &graph, int parent, std::string &s) {
    
    if(graph[parent].size() == 1) {
        if(graph[parent][0][1] == 0) {
            inorder(graph, graph[parent][0][0], s);
            s += (char) (parent + 'A');
        }
        else {
            s += (char) (parent + 'A');
            inorder(graph, graph[parent][0][0], s);
        }
        
    }
    else if(graph[parent].size() == 2) {
        inorder(graph, graph[parent][0][0], s);
        s += (char) (parent + 'A');
        inorder(graph, graph[parent][1][0], s);
    }
    else {
        s += (char) (parent + 'A');
    }
}

void postorder(std::vector<std::vector<std::vector<int>>> &graph, int parent, std::string &s) {
    if(graph[parent].size() == 1) {
        postorder(graph, graph[parent][0][0], s);
    }
    else if(graph[parent].size() == 2) {
        postorder(graph, graph[parent][0][0], s);
        postorder(graph, graph[parent][1][0], s);
    }
    s += (char) (parent + 'A');
}

int main() {

    int n;
    std::cin >> n;
    std::vector<std::vector<std::vector<int>>> graph(n + 1);

    for(int i = 0 ; i < n ; i++) {
        char p, cl, cr;
        std::cin >> p >> cl >> cr;

        if(cl != '.') {
            graph[p - 'A'].push_back({cl - 'A', 0});        
        }

        if(cr != '.') {
            graph[p - 'A'].push_back({cr - 'A', 1});        
        }

        //std::cout << p << " : ";
        for(int j = 0 ; j < graph[p].size() ; j++) {
            //std::cout << graph[p][j][0] << " "; 
        }
        //std::cout << "\n";
    }

    std::string pre = "";
    preorder(graph, 0, pre);
    std::cout << pre << "\n";

    std::string in = "";
    inorder(graph, 0, in);
    std::cout << in << "\n";

    std::string post = "";
    postorder(graph, 0, post);
    std::cout << post << "\n";
}