/* 14. BST Practice
Now try implementing a BST on your own. You'll use the same Node class as before:
class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
This time, you'll implement search() and insert(). You should rewrite search() and not use your code from the last exercise so it takes advantage of BST properties. Feel free to make any helper functions you feel like you need, including the print_tree() function from earlier for debugging. You can assume that two nodes with the same value won't be inserted into the tree.
Beware of all the complications discussed in the videos!
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
        ~Node(){
            // std::cout << "Node Destructor is called" << std::endl;
            delete left;
            delete right;
        }
};

class BST{
    public:
        Node * root;

        // Constructor
        BST(int v){
            root = new Node(v);
        }

        // Destructor
        ~BST(){
            // delete will delete recursively ...
            // std::cout << "Tree Destructor is called" << std::endl;
            delete root;
        }

        bool preorder_search(Node * node, int v){
        	if(node == nullptr) return false;
        	if(node->value == v) return true;
        	if(node->value > v) return preorder_search(node->left, v);
        	if(node->value < v) return preorder_search(node->right, v);
            return false;
        }

        bool search(int v){
            /* Return True if the value is in the tree, return False otherwise */
            return preorder_search(root, v);
        }

        void insert_helper(Node * start, int v){
            Node ** ptrptr;
            if(start == nullptr){
                std::cout << "Insert failure : Can not insert on an empty node" << std::endl;
                return;
            }

            if(start->value > v) ptrptr = &start->left;
            else ptrptr = &start->right;
            if(*ptrptr == nullptr){
                *ptrptr = new Node(v);
                std::cout << "Node value " << v << " inserted successfully" << std::endl;
            }
            else{
                insert_helper(*ptrptr, v);
            }    
            
            /*
            if(start->value > v){
                if(start->left == nullptr){
                    start->left = new Node(v);
                    std::cout << "Node value " << v << " inserted successfully" << std::endl;
                }
                else{
                    insert_helper(start->left, v);
                }    
            }
            else{ // start->value < v
                if(start->right == nullptr){
                    start->right = new Node(v);
                    std::cout << "Node value " << v << " inserted successfully" << std::endl;
                }
                else{
                    insert_helper(start->right, v);
                }    
            }
            */
        }


        void insert(int v){
            /* Return True if the value is in the tree, return False otherwise */
            insert_helper(root,v);
        }        

        void preorder_print(Node * start, std::vector<int> & traversal){
            /* Helper method - use this to create a recursive print solution */
            if(start == nullptr) return;
            traversal.push_back(start->value);
            if(start->left != nullptr) preorder_print(start->left, traversal);
            if(start->right != nullptr) preorder_print(start->right, traversal);
        }

        void print_tree(){
            /* Print out all tree nodes as they are visited in a pre-order traversal */
            std::vector<int> traversal;
            preorder_print(root, traversal);
            for(size_t i = 0; i < traversal.size(); i++){
                if(i == 0) std::cout << "tree = " << traversal[i] ;
                if ((i != 0) && (i < traversal.size())){
                    std::cout << "; " << traversal[i];
                }
                if(i == traversal.size() -1) std::cout << std::endl;
            }
        }
};

int main(){ 
	// # Set up tree
    BST tree = BST(4);

    //# Insert elements
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);

    // # Check search
    // # Should be True
    std::cout << "tree.search(4) should be true : " << tree.search(4) << std::endl;

    // # Should be False
    std::cout << "tree.search(6) should be false : " << tree.search(6) << std::endl;

    return 0;
}

// g++ main.cpp -o main.exe
