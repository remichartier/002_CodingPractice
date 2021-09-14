/* Binary Tree Practice
Now, it's your turn! Your goal is to create your own binary tree. You should start with the most basic building block:
class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
Every node has some value, and pointers to left and right children.
You'll need to implement two methods: search(), which searches for the presence of a node in the tree, and print_tree(), which prints out the values of tree nodes in a pre-order traversal. You should attempt to use the helper methods provided to create recursive solutions to these functions.
Let's get started!
Start Quiz
*/

#include <iostream>
#include <vector>

class Node{
    public:
        int value;
        Node * left;
        Node * right;

        // Constructor
        Node(int v){
            value = v;
            left = nullptr;
            right = nullptr;
        }

        // Destructor
        //~Node(){
        //    delete left;
        //    delete right;
        //}
};

class BinaryTree{
    public:
        Node * root;

        // Constructor
        BinaryTree(int v){
            root = new Node(v);
        }

        // Destructor
        //~BinaryTree(){
            // delete will delete recursively ...
            //delete root;
        //}

        bool search(int v){
            /* Return True if the value is in the tree, return False otherwise */
            return preorder_search(root, v);
        }

        void print_tree(){
            /* Print out all tree nodes as they are visited in a pre-order traversal */
        }

        bool preorder_search(Node * start, int v){
            /* Helper method - use this to create a recursive search solution */
            bool ret = false;

            if(start == nullptr) return false;
            
            if(start->value == v) return true;
            
            if(start->left != nullptr) ret = preorder_search(start->left, v);
            
            if(ret) return true;

            if(start->right != nullptr) ret = preorder_search(start->right, v);
            
            return ret;
        }

        bool preorder_print(Node * start, int v, std::vector<int> & traversal){
            /* Helper method - use this to create a recursive print solution */

            return false;
        }
};


int main(){
    // Set up tree
    BinaryTree tree = BinaryTree(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->right->left = new Node(5);

    // # Test search
    // # Should be True
    std::cout << "tree.search(4) should return true (1) : " << tree.search(4) << std::endl;
    // # Should be False
    std::cout << "tree.search(6) should return false (0) : " << tree.search(6) << std::endl;
    //tree.~BinaryTree();

    return 0;
}

// g++ main.cpp -o main.exe