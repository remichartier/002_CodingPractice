import java.util.*;

/* Description : 
*/

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

	public static void main(String[] args){
	}

}


/* javac ....java
	java ...

*/