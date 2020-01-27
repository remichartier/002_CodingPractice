/* Description : 

Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed ...

*/

public class Node{
	Node next;
	int data;

	Node(int d){
		data=d;
	}

	public Node nodeDeletion(Node head,int d){
		// return head of list
		if (head == Null) return(Null);
		Node n = head;
		if(n.data == d){
			return(n.next);
		}
		while(n.next != Null){
			if (n.next.data == d){
				n.next = n.next.next;
				return(head);
			}
			n= n.next;
		}
		return(head)
	}

	public void RemoveDups(Node head){
		Node n;
		HashMap<Integer,Integer> h = new HashMap(); //HashSet<integer> more appropriate here...

		if (head != Null){
			// initialize with first node
			n = head;
			h.put(n.data,1); // if HashSet --> .add()

			// now need to scroll all the list, detect if duplicates, remove duplicates.
			while(n.next != Null){
				if (h.containsKey(n.next.data)){
					n.next = nodeDeletion(n.next,n.next.data);
				}
				else{
					n = n.next;
					h.put(n.data,1);					
				}
			}
		}
	}

	// FOLLOW UP : How would you solve this problem if a temporary buffer is not allowed ...

	// Apparently need 2 pointers. One one source node, one scrolling futher nodes to search duplicates and remove them for each source node

	public void RemoveDups2(Node head){
		Node n1;
		Node n2;

		if (head != Null){
			// initialize with first node
			n1 = head;
			while(n1 != Null){
				n2 = n1;
				while(n2 != Null){
					if (n2.next.data = n1.data){
						n2 = nodeDeletion(n2,n1.data);
					}
					n2 = n2.next;
				}
				n1 = n1.next;
			}
		}
	}





}






/* javac RemoveDups.java
	java RemoveDups

*/