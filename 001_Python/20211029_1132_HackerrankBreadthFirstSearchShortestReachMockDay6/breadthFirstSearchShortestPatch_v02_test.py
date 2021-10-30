#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'bfs' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER n (number of nodes)
#  2. INTEGER m (number of edges)
#  3. 2D_INTEGER_ARRAY edges
#  4. INTEGER s (starting node)
#

class Node:
    def __init__(self, value):
        self.value = value
        self.edges = []

    def add_edge(self, number):
        self.edges.append(number)
        
class Graph:
    def __init__(self):
        self.nodes = [Node(0)]

# start = start node number (1 to n)
# target = searched node number (1 to n)
def find_bfs(start, target, g):
    curr = g.nodes[start]
    links = []
    if target == curr.value:
        return 0
    #print(f'node {start} current edges {curr.edges}')
    for e in curr.edges:
        if g.nodes[e].value != start:
            # dist += find_bfs(g.nodes[e].value, target, g)
            # stack the neighbors
            links.append(g.nodes[e].value)
    for l in links:
        print(f"find_bfs({l}, {target}, g)")
        d = find_bfs(l, target, g)
        print(f"{d} = find_bfs({l}, {target}, g)")
        if d != -1:
            return 6 + d
    return -1


def bfs(n, m, edges, s):
    # Write your code here
    #returns int[n-1] distances to nodes in increasing node number order,
    # not including the start node
    g = Graph()
    # create nodes, add them to the graph
    for i in range(1,n+1):
        g.nodes.append(Node(i))
    # fill list of edges on the nodes
    for e in edges:
        g.nodes[e[0]].add_edge(e[1])
        #g.nodes[e[1]].add_edge(e[0])
    # Now the Graph is filled.
    # We should now be able to implement BFS ...
    # build a list of distances from node s
    output = []
    for i in range(1, n+1):
        if i != s:
            output.append(find_bfs(s, i, g))
    print(output)
    
    #print(f"Display graph nodes : {g.nodes}")
    '''
    for no in g.nodes:
        print(f"value : {no.value}, edges : {no.edges}")
    print("bfs searches : ")
    print(find_bfs(1, 2, g))
    print(find_bfs(1, 3, g))
    print(find_bfs(1, 4, g))
    print(find_bfs(1, 5, g))
    '''
    
bfs(5,3,[[1,2],[1,3],[3,4]],1)

'''
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        first_multiple_input = input().rstrip().split()

        n = int(first_multiple_input[0])

        m = int(first_multiple_input[1])

        edges = []

        for _ in range(m):
            edges.append(list(map(int, input().rstrip().split())))

        s = int(input().strip())

        result = bfs(n, m, edges, s)

        fptr.write(' '.join(map(str, result)))
        fptr.write('\n')

    fptr.close()
'''