#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

class Node{
public:
    int value;
    vector<Node *> edges;
    bool seen;
    int dist;
    
    Node(int v) : value(v), seen(false), dist(0){    
    }


    void add_edge(Node * node){
        edges.push_back(node);
    }

    void reset_seen_dist_attributes();
};

class Graph{
public:
    vector<Node *> nodes;
    
    void add_node(Node * node){
        nodes.push_back(node);
    }

    // constructors Destructors
    //Graph(){}
    ~Graph(){
        for(auto n: nodes){
            delete n;
        }
    }

    void reset_seen_dist_attributes();

    void print_nodes_dist();
};

void Graph::reset_seen_dist_attributes(){
    for(auto n: nodes){
        n->reset_seen_dist_attributes();
    }
}

void Node::reset_seen_dist_attributes(){
     seen = false;
     dist = 0;
}

void Graph::print_nodes_dist(){
    for(auto n: nodes){
        cout << n->dist << ", ";
    }
    cout << endl;
}

// n : number of nodes
// m : number of edges
// edges : start and end nodes for edges
// s : node to start traversals
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<int> output;
    Graph g;
    Node * curr(nullptr);

    // nodes creations in g.
    for(int i=1; i <= n; ++i){
        g.add_node(new Node(i));
    }
    // edges creations
    for(auto e: edges){
        g.nodes[e[0]-1]->edges.push_back(g.nodes[e[1]-1]);
    }

    // now, can implement BFS

    for(int i = 1; i <= n; ++i){
        if(i == s) continue;
        // reset nodes seen and dist attributes
        g.reset_seen_dist_attributes();
        // will start from node # s --> s-1 in indexes.
        curr = g.nodes[s-1];
        if(curr->value == i){
            output.push_back(curr->dist);
            continue;
        }
        // otherwise store all the edges in a queue
        // and set them as seen .... + increment dist
        vector<Node*> queue;
        for(auto& e: curr->edges){
            e->seen = true;
            e->dist = curr->dist + 6;
            queue.push_back(e);
        }
        //queue
        // Now, while queue not empty : 
        //   now dequeue each one, check if target.
        //      if target, output.push_back(curr->dist) and continue 
        //   if not target, queue edges if not seen yet 
        //      (mark them as seen + increment dist)
        bool found = false;
        while(queue.size() != 0){
            //   now dequeue each one, check if target.
            curr = queue.front();
            // erase front
            queue.erase(queue.begin());
            //      if target, output.push_back(curr->dist) and continue 
            if(curr->value == i){
                output.push_back(curr->dist);
                found = true;
                break;
            }
            //   if not target, queue edges if not seen yet 
            for(auto& e: curr->edges){
                if(!e->seen){
                    e->seen = true;
                    e->dist = curr->dist + 6;
                    queue.push_back(e);
                }
            }
        }
        // if reached here, did not find target --> push back -1.
        if(found == false) 
            output.push_back(-1);
    }  // end for
    return output;
}

/*
Input (stdin)
2
4 2
1 2
1 3
1
3 1
2 3
2
Your Output (stdout)
6 6 -1 -1
-1 6 -1 -1
Expected Output
6 6 -1
-1 6

*/

int main(){
    vector<int> results;
    vector<vector<int>> edges({{1,2},{1,3},{3,4}});
    //cout << typeid(edges).name() << endl;
    results = bfs(5,3,edges,1);
    for(auto i: results){
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}

/*
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}
*/

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
