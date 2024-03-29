"""
Now, it's your turn! Your goal is to create your own binary tree. 
You should start with the most basic building block:
class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
Every node has some value, and pointers to left and right children.
You'll need to implement two methods: search(), which searches for the presence of 
a node in the tree, and print_tree(), 
which prints out the values of tree nodes in a pre-order traversal. 
You should attempt to use the helper methods provided to create recursive 
solutions to these functions.
Let's get started!
Start Quiz
Provided :
"""
 
class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinaryTree(object):
    def __init__(self, root):
        self.root = Node(root)

    def search(self, find_val):
        """Return True if the value
        is in the tree, return
        False otherwise."""
        return self.preorder_search(self.root, find_val)        
        #return False

    def print_tree(self):
        """Print out all tree nodes
        as they are visited in
        a pre-order traversal."""
         # pre-order traversal

        if self.root == None:
            return ""
        return self.preorder_print( self.root, "")

    def preorder_search(self, start, find_val):
        """Helper method - use this to create a 
        recursive search solution."""

        # pre-order traversal
        if start == None:
            return False
        if start.value == find_val:
            return True
        if start.left:
            if self.preorder_search(start.left, find_val):
                return True
        if start.right:
            if self.preorder_search(start.right, find_val):
                return True
        return False

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
tree = BinaryTree(1)
tree.root.left = Node(2)
tree.root.right = Node(3)
tree.root.left.left = Node(4)
tree.root.left.right = Node(5)

# Test search
# Should be True
print(tree.search(4))
# Should be False
print(tree.search(6))

# Test print_tree
# Should be 1-2-4-5-3
print(tree.print_tree())
