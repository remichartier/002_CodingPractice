"""BST Practice
Now try implementing a BST on your own. You'll use the same Node class as before:
class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
This time, you'll implement search() and insert(). You should rewrite search() and not use your code from the last exercise so it takes advantage of BST properties. Feel free to make any helper functions you feel like you need, including the print_tree() function from earlier for debugging. You can assume that two nodes with the same value won't be inserted into the tree.
Beware of all the complications discussed in the videos!
Start Quiz
Provided :
"""

class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BST(object):
    def __init__(self, root):
        self.root = Node(root)

    def insert(self, new_val):
        if not self.root:
            return
        self.insert_recurse(self.root,new_val)

    def insert_recurse(self,start,new_val):
        if new_val < start.value : 
            if not start.left:
                start.left = Node(new_val)
            else:
                self.insert_recurse(start.left,new_val)
        else:
            if not start.right:
                start.right = Node(new_val)
            else:
                self.insert_recurse(start.right,new_val)


    def search(self, find_val):
        if not self.root: 
            return False
        return self.bst_search(self.root,find_val)

    def bst_search(self, start, find_val):
        if not start:
            return False
        if start.value == find_val:
            return True
        if find_val < start.value:
            return self.bst_search(start.left, find_val)
        else:
            return self.bst_search(start.right, find_val)

    def print_tree(self):
        """Print out all tree nodes
        as they are visited in
        a pre-order traversal."""
         # pre-order traversal

        if self.root == None:
            return ""
        return self.preorder_print( self.root, "")

    def preorder_print(self, start, traversal):
        """Helper method - use this to create a 
        recursive print solution."""

        # pre-order traversal
        if start == None:
            return traversal
        traversal += str(start.value)
        if start.left:
            traversal = self.preorder_print(start.left, traversal + "-")
        if start.right:
            traversal = self.preorder_print(start.right, traversal + "-")
        return traversal

    
# Set up tree
tree = BST(4)
# Insert elements
tree.insert(2)
tree.insert(1)
tree.insert(3)
tree.insert(5)

# Check search
# Should be True
print(tree.search(4))


# Should be False
print(tree.search(6))
