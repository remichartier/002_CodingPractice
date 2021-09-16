#include <iostream>
#include <vector>

class Node{
public:
    int value;
    std::vector<Edge *> edges;

    // Constructeur
    Node(int v){
        value = v;
    }
};

class Edge{
public:
    int value;
    Node * node_from;
    Node * node_to;

    // Constructeur
    Edge(int v, Node * from, Node * to){
        value = v;
        node_from = from;
        node_to = to;
    }
};

class Graph{
public:
    std::vector<Node *> nodes;
    std::vector<Edge *> edges;    

    void insert_node(int v){
        Node * new_node = new Node(v);
        nodes.push_back(new_node);
    }

    void insert_edge(int new_edge_val, int node_from_val, int node_to_val){
        Node * from_found = nullptr;
        Node * to_found = nullptr;
        Edge * new_edge;
        for(auto node: nodes){
            if(node_from_val == node->value) from_found = node;
            if(node_to_val == node->value) to_found = node;
        }
        if(from_found == nullptr){
            from_found = new Node(node_from_val);
            nodes.push_back(from_found);
        }
        if(to_found == nullptr){
            to_found = new Node(node_to_val);
            nodes.push_back(to_found);
        }
        new_edge = new Edge(new_edge_val, from_found, to_found);
        from_found->edges.push_back(new_edge);
        to_found->edges.push_back(new_edge);
        edges.push_back(new_edge);
    }
};


int main(){ 

    return 0;
}

// g++ main.cpp -o main.exe
