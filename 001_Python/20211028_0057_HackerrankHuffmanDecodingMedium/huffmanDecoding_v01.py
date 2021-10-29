import queue as Queue

cntr = 0

class Node:
    def __init__(self, freq, data):
        self.freq = freq
        self.data = data
        self.left = None
        self.right = None
        global cntr
        self._count = cntr
        cntr = cntr + 1
        
    def __lt__(self, other):
        if self.freq != other.freq:
            return self.freq < other.freq
        return self._count < other._count

def huffman_hidden():#builds the tree and returns root
    q = Queue.PriorityQueue()

    
    for key in freq:
        q.put((freq[key], key, Node(freq[key], key) ))
    
    while q.qsize() != 1:
        a = q.get()
        b = q.get()
        obj = Node(a[0] + b[0], '\0' )
        obj.left = a[2]
        obj.right = b[2]
        q.put((obj.freq, obj.data, obj ))
        
    root = q.get()
    root = root[2]#contains root object
    return root

def dfs_hidden(obj, already):
    if(obj == None):
        return
    elif(obj.data != '\0'):
        code_hidden[obj.data] = already
        
    dfs_hidden(obj.right, already + "1")
    dfs_hidden(obj.left, already + "0")

"""class Node:
    def __init__(self, freq,data):
        self.freq= freq
        self.data=data
        self.left = None
        self.right = None
"""        

# Enter your code here. Read input from STDIN. Print output to STDOUT
def helper(node, s, i, decoded, root):
    current = node
    index = i
    if current.data == '\0':
        #print("current node = \0")        
        if index < len(s):
            if s[i] == '0':
                #print(f"s[i={i}] == 0 --> take left child")
                current = node.left
            else:
                #print(f"s[i={i}] == 1 --> take right child")
                current = node.right
            #print(f"Call decoded, i = helper(current, s,{i}, {decoded})")
            if current != root:
                i += 1
            decoded, i = helper(current, s,i, decoded,root)
        else:
            #print(f"index < len(s) -1  --> return decoded{decoded}, i {i}")
            return decoded, i
    else: # in case node.data not Null --> contains letter and it is a leaf
        decoded += node.data
        i -= 1
        #print(f"current node != \0 --> decoded += node.data --> return decoded {decoded}, i {i}")

        return decoded, i
    #print(f"Exit helper(node, s, i, decoded) with decoded {decoded}, i {i}")
    return decoded, i

def decodeHuff(root, s):
    #Enter Your Code Here
    #print(f"s = {s}")
    decoded = ""
    i = 0
    current = None
    while i < len(s):
        #print(f"loop while i < len(s), decoded {decoded}, i {i}")
        decoded, i = helper(root, s,i, decoded, root)
        i += 1
    print(decoded)
    

ip = input()
freq = {}#maps each character to its frequency

cntr = 0

for ch in ip:
    if(freq.get(ch) == None):
        freq[ch] = 1
    else:
        freq[ch]+=1

root = huffman_hidden()#contains root of huffman tree

code_hidden = {}#contains code for each object

dfs_hidden(root, "")

if len(code_hidden) == 1:#if there is only one character in the i/p
    for key in code_hidden:
        code_hidden[key] = "0"

toBeDecoded = ""

for ch in ip:
   toBeDecoded += code_hidden[ch]

decodeHuff(root, toBeDecoded)


S="1001011"

Input (stdin)

Download
ABACA
Your Output (stdout)
current node = 
s[i] == 1 --> take right child
current node !=  --> decoded += node.data --> return decoded A, i 2
Exit helper(node, s, i, decoded) with decoded A, i 2
current node = 
s[i] == 1 --> take right child
current node !=  --> decoded += node.data --> return decoded AA, i 5
Exit helper(node, s, i, decoded) with decoded AA, i 5
current node = 
index < len(s) -1  --> return decoded{decoded}, i {i}
AA