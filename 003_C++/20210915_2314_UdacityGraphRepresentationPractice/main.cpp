#include <iostream>
#include <vector>
#include<tuple> 

class Edge{
public:
    int value;
    int node_from;
    int node_to;

    // Constructeur
    Edge(int v, int from, int to){
        value = v;
        node_from = from;
        node_to = to;
    }
};

class Node{
public:
    int value;
    std::vector<Edge *> edges;

    // Constructeur
    Node(int v){
        value = v;
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
        new_edge = new Edge(new_edge_val, from_found->value, to_found->value);
        from_found->edges.push_back(new_edge);
        to_found->edges.push_back(new_edge);
        edges.push_back(new_edge);
    }

    std::vector<std::tuple<int, int, int>> get_edge_list(){
        /* """Don't return a list of edge objects!
        Return a list of triples that looks like this:
        (Edge Value, From Node Value, To Node Value)""" */
        
        std::vector<std::tuple<int, int, int>> list;
        for(Edge * e: edges){
            list.push_back(std::make_tuple(e->value, e->node_from, e->node_to));
        }
        return list;
        }

    void print_edge_list(){
        std::vector<std::tuple<int, int, int>> list = get_edge_list();
        std::cout << "Edge List = {" ;
        for(auto tup:list){
            std::cout << "(" << std::get<0>(tup) << ", " << std::get<1>(tup) << ", " \
            << std::get<2>(tup) << "),";
        }
        std::cout << "}" << std::endl;
    }

    void get_adjacency_list(){
        /*"""Don't return any Node or Edge objects!
        You'll return a list of lists.
        The indecies of the outer list represent
        "from" nodes.
        Each section in the list will store a list
        of tuples that looks like this:
        (To Node, Edge Value)"""
        return []*/

    }
};


int main(){ 
    Graph graph = Graph();
    graph.insert_edge(100, 1, 2);
    graph.insert_edge(101, 1, 3);
    graph.insert_edge(102, 1, 4);
    graph.insert_edge(103, 3, 4);
    std::cout << \
    "Should be something like [(100, 1, 2), (101, 1, 3), (102, 1, 4), (103, 3, 4)]"\
     << std::endl;
    //print graph.get_edge_list()
    graph.print_edge_list();
    // print graph.get_adjacency_list()
    // # Should be [[0, 0, 0, 0, 0], [0, 0, 100, 101, 102], [0, 0, 0, 0, 0], [0, 0, 0, 0, 103], [0, 0, 0, 0, 0]]


    return 0;
}

// g++ main.cpp -o main.exe
