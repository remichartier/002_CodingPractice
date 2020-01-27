/* Description : 

Write code to partition linked list around a value x, such as all nodes less than x come before all nodes greater than or equal to x.
if x is contained withtin the list, teh values off x only need to be after the elements less than x.

The partition element x can appear anywhere in the "right partition, it does not need to appear between the left and the right partitions.
ex 

input 3 5 8 5 10 2 1 (partition 5)
output : 3 1 2 10 5 5 8

Hints
#3 : many solutions to this problem --> brainstorm
#24 : elements don't have to stay in the same relative order. 
      Only need to ensure elements less than the pivot must be before elements greater than the pivot. Does that help you come up with more solutions ?

Analysis :

scroll the list
if data < partition and left of partition partition border, do nothing, go to next.
if data < partition and right of partition border, swap with partition border, then partition border moves to next.

correction : 
- create one list < partition, another list >= partition and then merge them ...

*/

class Node{
	Node next ;
	int data ;

	Node(int d){
		data = d;
	}

	void partition(Node head, int partition){
	
		Node headLeft = Null;
		Node tailLeft = Null;
		boolean leftEmpty = true;
		Node headRight = Null;
		Node tailRight = Null;
		boolean rightEmpty = true;
		Node current = head;
		Node pointer = null;

		while(current != Null){
			if(current.data<partition){
				if (leftEmpty){
					headLeft = new Node(current.data);
					headLeft.next=Null;
					tailLeft=headLeft;
					leftEmpty = false;
				}
				else{
					tailLeft.next = new Node(current.data);
					tailLeft = taiLeft.next;
					tailLeft = Null;
				}
			}
			else{
				if(rightempty){
					headRight = new Node(current.data);
					headRight.next = Null;
					tailRight = headRight ;
					rightEmpty = false;
				}
				else{
					tailRight.next = new Node(current.data);
					tailRight = tailRight.next ;
					tailRight.next = Null;
				}
			}
			current = current.next ;
		}
		// From there we get 2 lists that we can now copy back to original list, Left list first and right list after.
		current = head ;
		pointer = headĹeft;
		while(pointer != Null){
			current.data = pointer.data;
			current = current.next;
			pointer=pointer.next;
		}
		pointer = headRight ;
		while(pointer != Null){
			current.data = pointer.data;
			current = current.next;
			pointer = pointer.next;	
		}
		//here the original list should be partitionned.
	}

	// implementation with left on top of list and right on tail of linked list
	//method called with giving the head as parameter
	Node partition02(Node node, int partition){
		Node head = Null;
		Node tail = Null;
		Node cursor = node;
		Node temp = Null;

		if (node == Null) return(Null);

		while(cursor != Null){
			if(cursor.data < partition){
				if (head == Null){
					head = new Node(cursor.data)
					tail = head;
					head.next = Null;
				}
				else {
					temp = new Node(cursor.data);
					temp.next = head;
					head = temp;
				}
			}
			else{ // cursor.data >= partition
				if(tail == Null){
					tail = new Node(cursor.data);
					tail.next = Null;
					head = tail;
				}
				else{ // tail != Null
					tail.next = new Node(cursor.data);
					tail = tail.next;
					tail.next = Null;
				}
			}
		}

		//Now need to return linkedlist
		return(head);
	}



}

/* javac RemoveDupgetKthToLastElement_03(Node head,int k,int index)s.java
	java RemoveDups

*/