"""Graph Representation Practice

You should become comfortable with various graph representations—graphs crop up often in interviews and in computer science in general, and you could need to represent it in any of it's forms.
In this exercise you'll need to add functions to a Graph class to return various representations of the same graph. Your graph will have two different components: Nodes and Edges.
class Node(object):
    def __init__(self, value):
        self.value = value
        self.edges = []
Nodes are pretty much the same as they were in trees. Instead of having a set number of children, each node has a list of Edges.
class Edge(object):
    def __init__(self, value, node_from, node_to):
        self.value = value
        self.node_from = node_from
        self.node_to = node_to
Here, we assume that edges have both a value and a direction. An edge points from one node to another—the node it starts at is the node_from and the node it ends at is the node_to. You can envision it as node_from -> node_to.
The base of the Graph class looks something like this:
class Graph(object):
    def __init__(self, nodes=[], edges=[]):
        self.nodes = nodes
        self.edges = edges
A Graph class contains a list of nodes and edges. You can sometimes get by with just a list of edges, since edges contain references to the nodes they connect to, or vice versa. However, our Graph class is built with both for the following reasons:
    • If you're storing a disconnected graph, not every node will be tied to an edge, so you should store a list of nodes.
    • We could probably leave it there, but storing an edge list will make our lives much easier when we're trying to print out different types of graph representations.
Unfortunately, having both makes insertion a bit complicated. We can assume that each value is unique, but we need to be careful about keeping both nodes and edges updated when either is inserted. You'll also be given these insertion functions to help you out:
...

Alright, time to code the rest!
Start Quiz
NEXT
Provided : 
"""

class Node(object):
    def __init__(self, value):
        self.value = value
        self.edges = []

class Edge(object):
    def __init__(self, value, node_from, node_to):
        self.value = value
        self.node_from = node_from
        self.node_to = node_to

class Graph(object):
    def __init__(self, nodes=[], edges=[]):
        self.nodes = nodes
        self.edges = edges

    def insert_node(self, new_node_val):
        new_node = Node(new_node_val)
        self.nodes.append(new_node)
        
    def insert_edge(self, new_edge_val, node_from_val, node_to_val):
        from_found = None
        to_found = None
        for node in self.nodes:
            if node_from_val == node.value:
                from_found = node
            if node_to_val == node.value:
                to_found = node
        if from_found == None:
            from_found = Node(node_from_val)
            self.nodes.append(from_found)
        if to_found == None:
            to_found = Node(node_to_val)
            self.nodes.append(to_found)
        new_edge = Edge(new_edge_val, from_found, to_found)
        from_found.edges.append(new_edge)
        to_found.edges.append(new_edge)
        self.edges.append(new_edge)

    def get_edge_list(self):
        """Don't return a list of edge objects!
        Return a list of triples that looks like this:
        (Edge Value, From Node Value, To Node Value)"""
        return []

    def get_adjacency_list(self):
        """Don't return any Node or Edge objects!
        You'll return a list of lists.
        The indecies of the outer list represent
        "from" nodes.
        Each section in the list will store a list
        of tuples that looks like this:
        (To Node, Edge Value)"""
        return []
    
    def get_adjacency_matrix(self):
        """Return a matrix, or 2D list.
        Row numbers represent from nodes,
        column numbers represent to nodes.
        Store the edge values in each spot,
        and a 0 if no edge exists."""
        return []

graph = Graph()
graph.insert_edge(100, 1, 2)
graph.insert_edge(101, 1, 3)
graph.insert_edge(102, 1, 4)
graph.insert_edge(103, 3, 4)
# Should be [(100, 1, 2), (101, 1, 3), (102, 1, 4), (103, 3, 4)]
print graph.get_edge_list()
# Should be [None, [(2, 100), (3, 101), (4, 102)], None, [(4, 103)], None]
print graph.get_adjacency_list()
# Should be [[0, 0, 0, 0, 0], [0, 0, 100, 101, 102], [0, 0, 0, 0, 0], [0, 0, 0, 0, 103], [0, 0, 0, 0, 0]]
print graph.get_adjacency_matrix()
