#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
        Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void helper(Node *node, string& s){
        if(node == NULL) return;
        if(s.size() == 0){
            s += to_string(node->data);  
            // cout << s << endl;    
        }
        else{
            s += " " + to_string(node->data);
            // cout << s << endl;    
        }
        if(node->left != NULL) helper(node->left, s);
        if(node->right != NULL) helper(node->right, s);
    }
    
    void preOrder(Node *root) {
        string s("");
        helper(root, s);
        cout << s << endl;    
    }

}; //End of Solution