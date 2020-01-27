import java.util.*;

/* Description : 
*/

public class LinkedList {

	Node head ;
	
	public class Node{
		Node next = null ;
		int data ;

		public Node(int d){
			data = d ;
		}

		void appendToTail(int d){
			Node n = this ;
			Node end = new Node(d) ;

			while (n.next != Null){
				n = n.next ;
			}

			n.next = end ;
		}

		// delete node from singly linked list
		// return head
		Node deleteNode(Node head, int d){
			Node n = head;

			if (head.data == d) {
				return(head.next) ;
			}

			while (n.next != null){
				if (n.next.data == d){
					n.next = n.next.next;
					return(head);
				}
				n = n.next ;
			}
			// if did not find node, return head
			return(head);
		}

		public static void main(String[] args){
		}
	}

}


/* javac ....java
	java ...

*/