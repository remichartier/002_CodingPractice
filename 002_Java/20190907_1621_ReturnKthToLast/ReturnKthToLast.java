/* Description : 

Implement an algorithm to find the Kth to last element of a singly linked list

My own solution : 
Use ArrayList to store pointers to all the nodes scrolled.

Once all nodes scrolled, can figure out Kth element to last.

hints : 
#8 what if you knew the linked list size ?  what is the difference between finding the Kth to last element and finding the Xth element ?
#25 if you do not know the linked list size, can you compute it ? How does this impact the runtime ?
#41 try implementing it recursively. If you could find the k-1 th to last element, can you find the Kth element ? 
#67 you might find it useful to return multiple values. workarounds to support it. What are those workarounds ?
#126 Can you do iteratively ? imagine you had 2 pointers to adjacent nodes and they were moving at the same speed 
      through the linked list. When one hits the end of the linked list, where will the other one be ?

#41 --> if found the K-1 element
*/

class Node{
	Node next ;
	int data ;
}

Node getKthToLastElement(Node head,int k){

	ArrayList<Node> list = new ArrayList<Node>();
	Node n = head;
	int nb = 0;

	if(head == Null) return(Null);
	if(k<0) return(Null);
	if(k=0) return(head);

	while(n!=Null){
		list.add(n);
		nb++;
		n = n.next;
	}

	if(k>=nb) return(Null);
	
	return(list[nb-k]);
	
}

// solution with 2 pointers and without an ArrayList.

Node getKthToLastElement_02(Node head,int k){
	Node p1 = head;
	Node p2 = head;
	int i=0;

	if (head==Null) return Null;

	// make P1 progress until p1 -k = p2
	while (p1.next != Null) && (i<k){
		p1 = p1.next;
		i++;
	}

	// if i!= k --> could not find k elements --> need to return(Null)
	if (i!≃k) return(Null);

	while(p1.next !=Null){
		p1=p1.next;
		p2=p2.next;
	}

	return(p2);
}

// Now need to implement recursive solution.

int getKthToLastElement_03(Node head,int k){

	if (head==Null) return(0);

	int index = getKthToLastElement_03(head.next,k) +1;
	if (index==k) {system.out.println("Found the Kth to last element : " + head.data);}

	return(index);

}


/* javac RemoveDupgetKthToLastElement_03(Node head,int k,int index)s.java
	java RemoveDups

*/