
/* write a method :
	- takes a pointer to a Node structure.
	- returns complete copy of the passed in data structure
	- data structure contains 2 pointers to other nodes.
*/

struct Node {
	Node* p1;
	Node* p2;
}

Node * copy(Node * src) {
	Node * dest = malloc(struct Node);
	dest->p1 = copy(src->p1);
	dest->p2 = copy(src->p2);
	return(dest);
}

in the main(), we should free the dest memory space at the end of the program ...

