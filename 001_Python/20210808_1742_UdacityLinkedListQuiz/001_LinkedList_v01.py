"""The LinkedList code from before is provided below.
Add three functions to the LinkedList.
"get_position" returns the element at a certain position.
The "insert" function will add an element to a particular
spot in the list.
"delete" will delete the first element with that
particular value.
Then, use "Test Run" and "Submit" to run the test cases
at the bottom."""

class Element(object):
    def __init__(self, value):
        self.value = value
        self.next = None
        
class LinkedList(object):
    def __init__(self, head=None):
        self.head = head
        
    def append(self, new_element):
        current = self.head
        if self.head:
            while current.next:
                current = current.next
            current.next = new_element
        else:
            self.head = new_element
            
    def get_position(self, position):
        """Get an element from a particular position.
        Assume the first position is "1".
        Return "None" if position is not in the list."""
        i = 1
        if self.head == None:
        	return None
        current = self.head
        while current:
        	if i == position:
        		return current
        	i += 1
        	current = current.next
        return None
    
    def insert(self, new_element, position):
        """Insert a new node at the given position.
        Assume the first position is "1".
        Inserting at position 3 means between
        the 2nd and 3rd elements."""
        if (new_element==None) or (position < 1) or (self.head == None):
        	return
        previous = None
        current = self.head
        i = 0
        while (position -1 != i) and (current != None):
        	previous = current
        	current = current.next
        	i += 1
        if current == None:
        	return
        if previous == None: # meaning replace position 1 in head ....
        	next = current.next
        	self.head = new_element
        	self.head.next = next
       	else:
       		# need to replace at position i+1 ...
       		#next = current.next
       		next = current
       		previous.next = new_element
       		previous.next.next = next

    
    def delete(self, value):
        """Delete the first node with a given value."""
        if self.head == None:
        	return
        previous = None
        current = self.head
        while (value != current.value) and (current.next != None):
        	previous = current
        	current = current.next
        if (value == current.value):
        	# we can delete current element
        	# 2 cases : previous = None ie current = head
        	# or previous != None.
        	if previous == None: # we need to delete the head
        		self.head = self.head.next
        		del current
        	else: 
        		previous.next = current.next
        		del current
        # else: # in this case : (current.next == None) and value not found
        	# --> we have nothing to do.

    def print(self):
    	if self.head == None:
    		return
    	current = self.head
    	list = []
    	while (current != None):
    		list.append(current.value)
    		current = current.next
    	print(list)

# Test cases
# Set up some Elements
e1 = Element(1)
e2 = Element(2)
e3 = Element(3)
e4 = Element(4)

# Start setting up a LinkedList
ll = LinkedList(e1)
ll.append(e2)
ll.append(e3)

# Test get_position
# Should print 3
print(ll.head.next.next.value)
# Should also print 3
print(ll.get_position(3).value)


# Test insert
ll.insert(e4,3)
# Should print 4 now
print(ll.get_position(3).value)

ll.print()

# Test delete
ll.delete(1)
ll.print()
# Should print 2 now
print(ll.get_position(1).value)
# Should print 4 now
print(ll.get_position(2).value)
# Should print 3 now
print(ll.get_position(3).value)
