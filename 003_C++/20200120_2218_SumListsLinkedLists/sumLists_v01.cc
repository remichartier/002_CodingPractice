/* Description :
	2 numbers represented by a linked list
	Each node contains a single digit.
	Digits stored in reverse order, 1ś are at the head of the list.
	Write a function that adds the 2 numbers and returns the sum as a linked list.

	Exemple : 
	Input ( 7 / 1 / 6 ) + ( 5 / 9 / 2 ), that is : 617 + 295

	Output : ( 2 / 1 / 9 ) ie 912

	FOLLOW-UP : suppose the digits are stored in forward order. Repeat the above problem.

	Input ( 6 / 1 / 7 ) + ( 2 / 9 / 5 ), that is : 617 + 295

	Output : ( 9 / 1 / 2 ) ie 912
	
	Hints :  #7, #30, #71, #95, #109

*/

/* reflexion on algorithm :

	scroll each list until the end to form each number.
	Then add the numbers.
	Then build a sumList based on the total.

	O(3n) = O(n)

	We could also Take 2 lists together and do the additions node by node --> it would take only O(n).

*/



/* 
- define Node class
- define linked list class
- define method deleteNode
- define method appendToTail
- define method removeDuplicates
*/

#include <string>
#include <iostream>
#include <set>
using namespace std;

class Node {
	public : 
		int data;
		Node *next;

		// Constructor
		Node(int d){
			data = d;
			next = NULL;
		}
};

class LinkedList {
	

	public  :
		Node *head;
		// constructor
		LinkedList(Node *p){
			head = p ;
		}

		// deleteNode() : return head pointer
		Node * deleteNode(int d){
			
			if (head->data == d){
				// remove head
				Node * previous = head ;
				head = head->next ;
				// free previous head memory
				free(previous);
			}
			else { // need to scroll all list to find the corresponding node
				Node * pNode = head ;
				while(pNode->next != NULL){
					if (pNode->next->data != d){
						pNode = pNode->next ;
					}
					else {
						Node * pCurrent = pNode->next ;
						pNode->next = pNode->next->next;
						free(pCurrent);
					}
				}
			}
			return head;
		}

		Node * getTail(){
			if(head == nullptr) { return nullptr ;}

			Node * p(head) ;
			while(p->next != nullptr){
				p = p->next ;
			}
			return p ;
		}

		// appendToTail()
		Node * appendToTail(int d){
			Node * n = new Node(d) ;
			//printLinkedList();
			if (head == NULL){
				//cout << "head = Null" << endl ;
				// ie linked list is empty
				// --> create head node.
				head = n ;
			}
			else {
				// scroll head to last node.
				// add node and link it to last node.
				/*Node * p = head;
				while (p->next != NULL){
					p = p->next ;
				}
				*/
				Node * p = getTail() ;				
				p->next = n ;
			}
			return n ;
		}

		// removeDuplicates()
		void removeDuplicates01(){
			/*
				1. if temporary buffer is allowed --> can use a hash table. However, bit complicated in C++ to implement ...

				2. 
				if temporary buffer is not allowed :
				- 2 pointers : one on current element, another one scrolling rest of list.
				- for each element, scroll end of list. Any similar element --> remove from list.
				- cost : if n element --> first need to scroll n-1, then n-2, until 1/0 --> O(n^2)
			*/
			// Implementation # 1 with C++ sets. http://www.cplusplus.com/reference/set/set/find/
			/*
			Define a set
			While scrolling linked list through nodes 1 by 1
			if value not in set --> add it to set.
			if value already in set --> remove node.
			*/
			set<int> memorySet ;
			pair<set<int>::iterator,bool> ret;
			if(head != NULL){
				Node * p = head;
				Node * previous = NULL;
				while (p != NULL){
					// take value, insert into set.
					ret = memorySet.insert(p->data);
					if (ret.second==false){
						// it means could no be inserted because alread exists in the set
						// --> it is a duplicate, we need to remove it ...
						previous->next = p->next ;
						free(p);
						p = previous->next;
					}
					else{ // switch to next node
						previous = p ;
						p = p->next ;
					} // end if else
				} // end while	
			} // end if heat null
		} // end method removeDuplicates

		// Now need to implement without extra memory space.
		// ie with 2 pointers.
		void removeDuplicates02(){
			Node * p1(NULL),* p2(NULL), * previous(NULL) ;
			if (head != NULL){
				p1 = head ;
				previous = p1 ;
				while(p1 != NULL){
					p2 = p1->next ;
					// cout << "p1 points on " << p1->data << "\n" ;
					while(p2 != NULL){
						// cout << "p2 points on " << p2->data << "\n" ;
						if (p2->data == p1->data){ // duplicate
							// remove the node pointed by p2
							// cout << "remove " << p2->data << "\n" ;
							previous->next = p2->next;
							free(p2);
							p2 = previous ;
						} // end if p2/p1 data different --> no duplicates
						previous = p2 ;
						p2 = p2->next ;
					} // end while p2 not NULL
					p1 = p1->next ;
					previous = p1 ;
				} // end while p1 not NULL
			} // end if head not NULL
		} // end removeDuplicates02()

		// NOW NEED TO IMPLEMENT A RECURSIVE VERSION OF removeDuplicates02() ....
		
		// print LinkedList
		void printLinkedList(){
			Node * n = head ;
			while (n != NULL){
				cout << n->data << " ; " ;
				n = n->next;
			}
			cout << "\n" ;
		}

		// Kth to last element of a singly list
		Node * kthToLastBuffer(int k){
			Node * nodesTable[k+1];
			int sizeList(0);
			int modulo(0) ;
			// scroll list if existing
			if(head != NULL){
				Node * p = head ;
				nodesTable[sizeList%(k+1)] = head ;
				//cout << "(sizeList) = " << (sizeList) << "\n" ;
				//cout << "nodesTable[" << (sizeList % k) << "] = " << nodesTable[sizeList%k]->data << "\n" ;
				sizeList += 1;
				p = head->next ;
				while (p != NULL){
					nodesTable[sizeList%(k+1)] = p ;
					modulo = sizeList % (k+1) ;
					//cout << "sizeList " << sizeList << "\n" ;
					//cout << "k+1 " << k+1 << "\n" ;
					//cout << "sizeList % (k+1) " <<  sizeList % (k+1) << "\n" ; 
					//cout << "(sizeList) = " << (sizeList) << " " << modulo << "\n" ;
					//cout << "nodesTable[" << sizeList % (k+1)<< "] = " << nodesTable[sizeList%(k+1)]->data << "\n" ;
					sizeList += 1;
					p = p->next ;
				}
				// list scrolled, array filed.
				// now have to extract good node if possible.

				if (k+1 > sizeList){
					return(NULL);
				}
				else {
					//cout << "nodesTable[(sizeList-1-k)%k] = " << nodesTable[(sizeList-1-k)%k]->data << "\n" ;
					return(nodesTable[((sizeList-1)%(k+1)+1)%(k+1)]) ;
				}

			}
			else{
				return NULL;
			}
		}

		bool printKth2LastRecursive(Node * pnode, int k, int& counter){
			//cout << "Enter printKth2LastRecursive() with node value : " << pnode->data << endl ;
			// case did not reach last element
			if(pnode->next != nullptr){
				//cout << "pnode->value = " << pnode->data << " | " << "Next node not a null ptr --> call printKth2LastRecursive" << endl;
				if(printKth2LastRecursive(pnode->next,k,counter)) {
					//cout << "pnode->value = " << pnode->data << " | " << "printKth2LastRecursive() returned true --> return true" << endl ;
					return true;
				}				
				// while out of recurse
				++counter ;
				//cout << "pnode->value = " << pnode->data << " | " << "--counter; counter == " << counter << endl;
			}
			// case reached last element
			else { //(pnode->next == nullptr){
				//cout << "pnode->value = " << pnode->data << " | " << "pnode->next == nullptr" << endl;
				//cout << "pnode->value = " << pnode->data << " | " << "counter = 0 ;" << endl;
				counter = 0 ;
			}
			if (counter == k){
				//cout << "pnode->value = " << pnode->data << " | " << "counter == k" << endl ;
				cout  << k << " ToLast = " << pnode->data << endl ;
				//cout << "pnode->value = " << pnode->data << " | " << "return true ;" << endl ;
				return true;
			}
			// cout <<  "pnode->value = " << pnode->data << " | " << "return false ;" << endl ;
			return false;
		}

		Node * kthToLast2Pointers(int k){
		
			Node * p1(head), * p2(head) ;
			int distance(0) ;
			while(p1->next != nullptr) {
				p1 = p1->next ;
				if (distance != k){	
					++distance ;
				}
				else {
					p2 = p2->next ;
				}
			}

			// here reached end of list
			// if distance == k, p2 should point on K To Last node
			// Otherwise k>sizelist --> impossible to find --> return NULL.
			if (distance == k){
				return(p2) ;
			}
			else{
				return nullptr ;
			}

			return nullptr ;
		}

	void deleteMiddleNode(Node * n){
		// case list is empty
		// case node to delete is actually the head
		// case node to delete is actually the tail 
		if((head == nullptr) || (n == head) || (n->next == nullptr) ){ 
			return ; 
		}
	
		// scroll list until finds this node pointer n
		// if reaches end of list, return or do nothing, will exit method

		Node * p = head ;

		while(p->next != nullptr){
			if(p->next == n){
				p->next = n->next ;
				free(n) ;
			}
			p = p-> next ;
		} 
	}

	void partitionList(int partition){
		if(head == nullptr) { return ;}
		Node * ppivot(nullptr), * p(head), * ptail(nullptr) ;

		ptail = getTail();
		while (p != ptail){
			if (p->data < partition){
				ppivot = p ;
				p = p->next ;
			}
			else { // p->data >= partition
				// then add p->data to tail
				appendToTail(p->data) ;
				// don't know the previous node - did not keep in memory.
				// but can copy data of next node to current node and
				// remove next node ...
				p->data = p->next->data ;
				Node * pToDelete = p->next ;
				p->next = p->next->next ;
				free(pToDelete) ;
			}
			// end of while, need to move p to next :
			if(ppivot == nullptr){
				p = head ;
			}
			else{
				p = ppivot->next ;
			}
		}
	}

	Node * addNodeTop(int value){
		//cout << "entered method addNodeTop(value)" << endl ;		
		if ( head == nullptr ){
			//cout << "return nullptr from method padNodestop(value)" << endl ;		
			return nullptr ;
		}
		Node * n = new Node(value);
		n->next = head ;
		head = n ;
		//cout << "return head from method padNodestop(value)" << endl ;					
		return head ;
	}

	int getLength() {
		if (head == NULL){
			return 0 ;
		}
		else {
			// scroll list to compute length
			Node * n = head ;
			int counter(1) ;
			while (n != nullptr){
				n = n->next ;
				++counter ;
			}
			return counter ;
		}
	}

	void padNodesTop(int value) {
		//cout << "entered method padNodestop(value)" << endl ;			
		if(value <=0) { return ; }
		for(int i(0);i<value;++i){
			addNodeTop(0) ;
		}
		//cout << "exit method padNodestop(value)" << endl ;	
	}
};

void testAddNodeTail(int value, LinkedList& lst){
	cout << "lst.appendToTail(" << value << ") ;" << endl ;
	lst.appendToTail(value) ;
	lst.printLinkedList() ;
}


void buildTopList(LinkedList& newList){
	Node * n = new Node(3) ;
	
	newList = LinkedList(n);
	//newList.printLinkedList() ;
	newList.appendToTail(5) ;
}

void buildBottomList(LinkedList& newList){
	if(newList.head == nullptr){
		return;
	}
	newList.appendToTail(8) ;
	newList.appendToTail(5) ;
	newList.appendToTail(10) ;
	newList.appendToTail(2) ;
	newList.appendToTail(1) ;
}


void buildList(LinkedList& newList){
	buildTopList(newList);
	buildBottomList(newList);	
}

void testRemoveNodes(LinkedList& lst,int value){
	
	cout << "lst.deleteNode(1) ;" << "\n" ;
	lst.deleteNode(value) ;
	lst.printLinkedList() ;
}

void testRemoveDuplicates(LinkedList& lst){
	
	cout << "l.removeDuplicates() ;" << "\n" ;
	lst.removeDuplicates02();
	lst.printLinkedList() ;
}

void testKthToLastBuffer(LinkedList lst){
	Node * k ;
	int number(3);
	k = lst.kthToLastBuffer(number);
	if(k != NULL){
		cout << "lst.kthToLase(" << number <<") =" << k->data << "\n" ;
	}
	else {
		cout << "Impossible to find " << number << " To Last : " << number << " > sizeList " << "\n" ;	
	}
	/*k = lst.kthToLast(2);
	cout << "lst.kthToLase(2) =" << k->data << "\n" ;
	k = lst.kthToLast(1);
	cout << "lst.kthToLase(1) =" << k->data << "\n" ;
	*/

	int counter;
	bool result ;
	result = lst.printKth2LastRecursive(lst.head,number, counter);
	if (!result) {
		cout << "Impossible to find " << number << " to LAST value\n" ;
	}

	k = lst.kthToLast2Pointers(number) ;
	if(k != NULL){
		cout << "lst.kthToLase(" << number <<") =" << k->data << "\n" ;
	}
	else {
		cout << "Impossible to find " << number << " To Last : " << number << " > sizeList " << "\n" ;	
	}
}

void testDeleteMiddleNode(LinkedList &lst){
	Node * n(nullptr) ;

	buildTopList(lst);
	n = lst.appendToTail(56);
	buildBottomList(lst);
	lst.printLinkedList();
	lst.deleteMiddleNode(n);
	lst.printLinkedList();
}

void testPartitionList(LinkedList &lst, int value){
	lst.partitionList(value);
	lst.printLinkedList();
}

void testSumList(){
	LinkedList l1 = LinkedList(nullptr);
	LinkedList l2 = LinkedList(nullptr);
	LinkedList t = LinkedList(nullptr);

	// Build l1 617
	l1.appendToTail(7);
	l1.appendToTail(1);
	l1.appendToTail(6);
	l1.printLinkedList();
	
	// Build l2 295
	l2.appendToTail(5);
	l2.appendToTail(9);
	l2.appendToTail(2);
	l2.printLinkedList();

	Node * p1(l1.head) ;
	Node * p2(l2.head) ;
	int carry(0);

	// start operation node by node
	while( (p1 != nullptr) || (p2 != nullptr) || (carry != 0) ) {

		int n(0);
		if(p1!=nullptr) { n = p1->data ;}
		if(p2!=nullptr) { n += p2->data ;}

		n += carry ;
		carry = 0 ;

		// write unit number to total list
		t.appendToTail(n%10) ;
		carry = (int)(n/10) ;

		// increment at the end for p1 and p2
		if( p1 != nullptr ){
			p1 = p1->next ;
		}
		if( p2 != nullptr ){
			p2 = p2->next ;
		}
	}

	// at this point, t list is built --> print it.
	t.printLinkedList() ;

}

int sumNodesForward(Node * p1,Node * p2, Node * pt){

	//cout << "enter function sumNodesForward()" << endl ; 
	int carry(0) ;

	//cout << "pt->data = 0" << endl ; 
	pt->data = 0;

	if(p1 != nullptr){
		//cout << "pt->data += p1->data ie " << p1->data << endl ; 
		pt->data += p1->data ;	
	}
	if(p2 != nullptr){
		//cout << "pt->data += p2->data ie " << p2->data << endl ; 
		pt->data += p2->data ;	
	}

	if (( p1->next != nullptr) && ( p2->next != nullptr) ){
		//cout << "pt->next = new Node(0);" << endl ; 
		pt->next = new Node(0);
		//cout << "pt->data += sumNodesForward(p1->next,p2->next, pt->next);" << endl ; 
		
		//if (p1->next == nullptr){cout << "p1->next == nullptr" << endl ;  }
		//if (p2->next == nullptr){cout << "p2->next == nullptr" << endl ;  }
		//if (pt->next == nullptr){cout << "pt->next == nullptr" << endl ;  }
		//cout << "we get segmentation fault (core dump) while calling next line..." << endl ;
		pt->data += sumNodesForward(p1->next,p2->next, pt->next);
		//cout << "pt->data += sumNodesForward(p1->next,p2->next, pt->next); -->" << pt->data << endl ; 
	}

	// keep in pt->data the unit part and return the carry on
	carry = (int) ( pt->data / 10 ) ;

	pt->data = pt->data % 10 ;

	//cout << "exit function sumNodesForward() and return carry " << carry << endl ;
	return carry ;
}

void equalizeListLengthForForwardListSum(LinkedList & l1,LinkedList & l2) {

	// compute lengths l1 and l2, do difference. Pad on top of shortest list number of 0s.
	//cout << "entered function equalizeListLengthForForwardListSum(l1,l2)" << endl ;
	int n1(l1.getLength()), n2(l2.getLength()), delta(n1-n2) ;

	if (delta > 0){ // need to pad l2
		l2.padNodesTop(delta) ;
	}
	if (delta < 0){ // need to pad l1
		l1.padNodesTop(delta) ;
	}
	//l1.printLinkedList();
	//l2.printLinkedList();
	//cout << "exit function equalizeListLengthForForwardListSum(l1,l2)" << endl ;
	// if delta = 0, do not need to do anything.

}

void testSumListForwardOrder(){
	LinkedList l1 = LinkedList(nullptr);
	LinkedList l2 = LinkedList(nullptr);
	LinkedList t = LinkedList(nullptr);

	// Build l1 617
	l1.appendToTail(6);
	l1.appendToTail(1);
	l1.appendToTail(7);
	l1.appendToTail(7);
	l1.appendToTail(7);
	l1.printLinkedList();
	
	// Build l2 295
	l2.appendToTail(2);
	l2.appendToTail(9);
	l2.appendToTail(5);
	l2.printLinkedList();

	
	t.head = new Node(0) ;
	/* if forward, need of a recursion ?
	Sum at node(n) need result of sum at node(n+1)
	And we would need to construct the list by adding number at top of the list instead of tail of the list ! 

	*/ 
	// start operation node by node
	
	// Does first with numbers of same length.
	// Later will had corrections for numbers of different lengths.

	equalizeListLengthForForwardListSum(l1,l2) ;

	cout << "2 list equalized : " << endl ;
	l1.printLinkedList();
	l2.printLinkedList();

	Node * p1(l1.head) ;
	Node * p2(l2.head) ;

	int carry = sumNodesForward(p1,p2,t.head) ;

	// if carry == 0, no need to add any additional node on top to complete the addition.

	// if carry != 0, need to add a new node on top of t to handle this new digit.

	if (carry != 0){
		t.head = t.addNodeTop(carry) ;
		carry = 0 ;
	}

	
	t.printLinkedList();
	
	
	// case left to be developped ...

}

int main(){
	//create linkedList with nodes, then print the nodes
	//LinkedList l = LinkedList(nullptr);
	//buildList(l);
	//l.printLinkedList();
	//testRemoveNodes(l,1);
	//testRemoveDuplicates() ;
	//testKthToLastBuffer(l) ;
	//testDeleteMiddleNode(l);
	//testPartitionList(l,5);	
	//testSumList();
	testSumListForwardOrder();
	return 0;
}
/* g++ sortFile.cpp -o sortFile

*/