/* Description :
	
	Given a circular linked list, implement an algorthm that returns the node at the beginning of 
	the loop.
	Definition : Circular linked list : a corrupt linked list in which a nodeś next pointer 
	points to an earlier node, so as to make a loop in the linked list.
	
	Example : 
	Input : 	A / B / C / D / E / C (same C as earlier)
	Output : 	C

	Hints :  #50, #69, #83, #90
	
*/

/* reflexion on algorithm :
	- use a set to record references of 1st linked list.
	- Then take 2nd linked list and check if each node appear int the set,
	- if appears, return this reference.
*/

/* Note : TO BE DONE.

	THE free() OF NODES SHOULD BE REPLACECED BY "delete ptr ; ptr = nullptr ;"	+ CLASS DESTRUCTORS SHOULD BE IMPLEMENTED !


	AND ALL POINTERS SHOULD BE "deleted" AT THE END + SET TO nullptr

	+ CLASS DESTRUCTORS SHOULD BE IMPLEMENTED !
*/


#include <string>
#include <iostream>
#include <set>
using namespace std;

template <class dataType> class Node {
	public : 
		dataType data;
		Node *next;

		// Constructor
		Node(dataType d){
			data = d;
			next = NULL;
		}
};

template <class dataType> class LinkedList {
	

	public  :
		Node<dataType> *head;
		// constructor
		LinkedList<dataType>(Node<dataType> *p){
			head = p ;
		}

		// deleteNode() : return head pointer
		Node<dataType> * deleteNode(dataType d){
			
			if (head->data == d){
				// remove head
				Node<dataType> * previous = head ;
				head = head->next ;
				// free previous head memory
				free(previous);
			}
			else { // need to scroll all list to find the corresponding node
				Node<dataType> * pNode = head ;
				while(pNode->next != NULL){
					if (pNode->next->data != d){
						pNode = pNode->next ;
					}
					else {
						Node<dataType> * pCurrent = pNode->next ;
						pNode->next = pNode->next->next;
						free(pCurrent);
					}
				}
			}
			return head;
		}

		Node<dataType> * getTail(){
			if(head == nullptr) { return nullptr ;}

			Node<dataType> * p(head) ;
			while(p->next != nullptr){
				p = p->next ;
			}
			return p ;
		}

		// appendToTail()
		Node<dataType> * appendToTail(int d){
			Node<dataType> * n = new Node<dataType>(d) ;
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
				Node<dataType> * p = getTail() ;				
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
			set<dataType> memorySet ;
			pair<set<int>::iterator,bool> ret;
			if(head != NULL){
				Node<dataType> * p = head;
				Node<dataType> * previous = NULL;
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
			Node<dataType> * p1(NULL),* p2(NULL), * previous(NULL) ;
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
			Node<dataType> * n = head ;
			while (n != NULL){
				cout << n->data << " ; " ;
				n = n->next;
			}
			cout << "\n" ;
		}

		// Kth to last element of a singly list
		Node<dataType> * kthToLastBuffer(int k){
			Node<dataType> * nodesTable[k+1];
			int sizeList(0);
			int modulo(0) ;
			// scroll list if existing
			if(head != NULL){
				Node<dataType> * p = head ;
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

		bool printKth2LastRecursive(Node<dataType> * pnode, int k, int& counter){
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

		Node<dataType> * kthToLast2Pointers(int k){
		
			Node<dataType> * p1(head), * p2(head) ;
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

	void deleteMiddleNode(Node<dataType> * n){
		// case list is empty
		// case node to delete is actually the head
		// case node to delete is actually the tail 
		if((head == nullptr) || (n == head) || (n->next == nullptr) ){ 
			return ; 
		}
	
		// scroll list until finds this node pointer n
		// if reaches end of list, return or do nothing, will exit method

		Node<dataType> * p = head ;

		while(p->next != nullptr){
			if(p->next == n){
				p->next = n->next ;
				free(n) ;
			}
			p = p-> next ;
		} 
	}

	void partitionList(dataType partition){
		if(head == nullptr) { return ;}
		Node<dataType> * ppivot(nullptr), * p(head), * ptail(nullptr) ;

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
				Node<dataType> * pToDelete = p->next ;
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

	Node<dataType> * addNodeTop(dataType value){
		//cout << "entered method addNodeTop(value)" << endl ;		
		//if ( head == nullptr ){
			//cout << "return nullptr from method padNodestop(value)" << endl ;		
		//	return nullptr ;
		//}
		Node<dataType> * n = new Node<dataType>(value);
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
			Node<dataType> * n = head ;
			int counter(1) ;
			while (n != nullptr){
				n = n->next ;
				++counter ;
			}
			return counter ;
		}
	}

	void padNodesTop(dataType value) {
		//cout << "entered method padNodestop(value)" << endl ;			
		if(value <=0) { return ; }
		for(int i(0);i<value;++i){
			addNodeTop(0) ;
		}
		//cout << "exit method padNodestop(value)" << endl ;	
	}
};



template <class dataType> void testAddNodeTail(dataType value, LinkedList<dataType>& lst){
	cout << "lst.appendToTail(" << value << ") ;" << endl ;
	lst.appendToTail(value) ;
	lst.printLinkedList() ;
}


template <class dataType> void buildTopList(LinkedList<dataType>& newList){
	Node<dataType> * n = new Node<dataType>(3) ;
	
	newList = LinkedList<dataType>(n);
	//newList.printLinkedList() ;
	newList.appendToTail(5) ;
}



template <class dataType> void buildBottomList(LinkedList<dataType>& newList){
	if(newList.head == nullptr){
		return;
	}
	newList.appendToTail(8) ;
	newList.appendToTail(5) ;
	newList.appendToTail(10) ;
	newList.appendToTail(2) ;
	newList.appendToTail(1) ;
}


template <class dataType> void buildList(LinkedList<dataType>& newList){
	buildTopList(newList);
	buildBottomList(newList);	
}

template <class dataType> void testRemoveNodes(LinkedList<dataType>& lst,dataType value){
	
	cout << "lst.deleteNode(1) ;" << "\n" ;
	lst.deleteNode(value) ;
	lst.printLinkedList() ;
}


template <class dataType> void testRemoveDuplicates(LinkedList<dataType>& lst){
	
	cout << "l.removeDuplicates() ;" << "\n" ;
	lst.removeDuplicates02();
	lst.printLinkedList() ;
}

template <class dataType> void testKthToLastBuffer(LinkedList<dataType> lst){
	Node<dataType> * k ;
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


template <class dataType> void testDeleteMiddleNode(LinkedList<dataType> &lst){
	Node<dataType> * n(nullptr) ;

	buildTopList(lst);
	n = lst.appendToTail(56);
	buildBottomList(lst);
	lst.printLinkedList();
	lst.deleteMiddleNode(n);
	lst.printLinkedList();
}

void testPartitionList(LinkedList<int> &lst, int value){
	lst.partitionList(value);
	lst.printLinkedList();
}

void testSumList(){
	LinkedList<int> l1 = LinkedList<int>(nullptr);
	LinkedList<int> l2 = LinkedList<int>(nullptr);
	LinkedList<int> t = LinkedList<int>(nullptr);

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

	Node<int> * p1(l1.head) ;
	Node<int> * p2(l2.head) ;
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

int sumNodesForward(Node<int> * p1,Node<int> * p2, Node<int> * pt){

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
		pt->next = new Node<int>(0);
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

void equalizeListLengthForForwardListSum(LinkedList<int> & l1,LinkedList<int> & l2) {

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
	LinkedList<int> l1 = LinkedList<int>(nullptr);
	LinkedList<int> l2 = LinkedList<int>(nullptr);
	LinkedList<int> t = LinkedList<int>(nullptr);

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

	
	t.head = new Node<int>(0) ;
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

	Node<int> * p1(l1.head) ;
	Node<int> * p2(l2.head) ;

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



void testPalindrome(){
	LinkedList<char> l1 = LinkedList<char>(nullptr);
	LinkedList<char> l2 = LinkedList<char>(nullptr);
	int nbChar(0),middle(0);

	// exemples of palindrome : Taco cat, atco cta
	// not a palindrome : Tact Coa
	
	// Build l1 
	l1.appendToTail('a');
	l1.appendToTail('t');
	l1.appendToTail('c');
	l1.appendToTail('o');
	l1.appendToTail(' ');
	l1.appendToTail('c');
	l1.appendToTail('t');
	l1.appendToTail('a');
	
	l1.printLinkedList();
	
	/* reflexion on algorithm :

		- Scroll Linked List and construct new one adding new node read on head of the new linked list.
		- Count # of Characters.
		- Then start comparing characters while skipping spaces to check if palindrome or not.
	*/

	// - Scroll Linked List and construct new one adding new node read on head of the new linked list.
	// - Count # of Characters.
		
	Node<char> * p1(l1.head) ;
	Node<char> * p2(nullptr) ;

	while( p1 != nullptr){
		// count character if not a space
		if( p1->data != ' '){
			++nbChar ;
			l2.head = l2.addNodeTop(p1->data) ;
			//cout << "l2 = " ;
			//l2.printLinkedList();
		}
		p1 = p1->next ;
	}

	//cout << "After reading l1, nbChar = " << nbChar << endl ;
	cout << "l2 = " ;
	l2.printLinkedList();

	// calculate middle : 
	if( nbChar%2 == 0){
		middle = nbChar / 2 ;
	}
	else{
		middle = (int)(nbChar / 2) + 1 ;
	}

	int i(0);
	p1 = l1.head ;
	p2 = l2.head ;
	while( i < middle ){
		// scroll both Linked list.
		// skip spaces (only in l1/p1)
		while(p1->data == ' '){ p1 = p1->next ;}
		if (p1->data != p2->data){
			cout << p1->data << " != " << p2->data << " ---> This is NOT a palindrome" << endl ;
			return ;
		}
		p1 = p1->next ;
		p2 = p2->next ;
		++i ;
	}

	// if out of while, means all chars until middle are identical
	// meaning it is a palindrome.

	cout << "This IS a palindrome" << endl ;

	// now according to book : 
	// #29 : assume you have the length of the linked list : can you implement this recursively ?
}


/* reflexion on algorithm :

	- use a set to record references of 1st linked list.
	- Then take 2nd linked list and check if each node appear int the set,
	- if appears, return this reference.
*/

void build2NONIntersectingLists(LinkedList<int> &l1,LinkedList<int> &l2){
	// will use 	Node<dataType> * addNodeTop(dataType value){
	// will use 	l1.appendToTail('a');

	// create l2 first.
	l2.appendToTail(0);
	l2.appendToTail(2);
	l2.appendToTail(4);
	l2.appendToTail(6);
	l2.appendToTail(8);
	l2.appendToTail(10);
	l2.appendToTail(12);
	l2.appendToTail(14);
	l2.appendToTail(16);
	l2.appendToTail(18);

	/* 
	// create l1 top nodes intersecting with l2.
	l1.head = l2.head ;
	l1.addNodeTop(-1);
	l1.addNodeTop(-2);
	l1.addNodeTop(-3);
	l1.addNodeTop(-4);
	l1.addNodeTop(-5);
	l1.addNodeTop(-6);
	l1.addNodeTop(-7);
	l1.addNodeTop(-8);
	*/

	// create l1 top nodes NOT intersecting with l2.
	l1.appendToTail(0);
	l1.appendToTail(2);
	l1.appendToTail(4);
	l1.appendToTail(6);
	l1.appendToTail(8);
	l1.appendToTail(10);
	l1.appendToTail(12);
	l1.appendToTail(14);
	l1.appendToTail(16);
	l1.appendToTail(18);
	

	l1.printLinkedList();
	l2.printLinkedList();
}

void build2IntersectingLists(LinkedList<int> &l1,LinkedList<int> &l2){
	// will use 	Node<dataType> * addNodeTop(dataType value){
	// will use 	l1.appendToTail('a');

	// create l2 first.
	l2.appendToTail(0);
	l2.appendToTail(2);
	l2.appendToTail(4);
	l2.appendToTail(6);
	l2.appendToTail(8);
	l2.appendToTail(10);
	l2.appendToTail(12);
	l2.appendToTail(14);
	l2.appendToTail(16);
	l2.appendToTail(18);
 
	// create l1 top nodes intersecting with l2.
	l1.head = l2.head ;
	l1.addNodeTop(-1);
	l1.addNodeTop(-2);
	l1.addNodeTop(-3);
	l1.addNodeTop(-4);
	l1.addNodeTop(-5);
	l1.addNodeTop(-6);
	l1.addNodeTop(-7);
	l1.addNodeTop(-8);
		

	l1.printLinkedList();
	l2.printLinkedList();
}

void testIntersection(){ // not working, issue with set<> but not goal of this study so I'll pass
	LinkedList<int> l1 = LinkedList<int>(nullptr);
	LinkedList<int> l2 = LinkedList<int>(nullptr);

	//build2IntersectingLists(l1,l2) ;
	build2NONIntersectingLists(l1,l2) ;

	Node<int> * p1(l1.head);
	Node<int> * p2(l2.head);

	//- use a set to record references of 1st linked list.
	set<Node<int> *> memorySet ;
	//pair<Node<int> *>::iterator,bool> ret;
	// take value, insert into set.
	//ret = memorySet.insert(p->data);

	while(p1 != nullptr){
		memorySet.insert(p1);
		p1 = p1->next ;
	}

	auto posEnd = memorySet.end(); // Returns an iterator to the theoretical element that follows 
	// last element in the set.
	// Now for each node in l2, check if node exists in l1.
	// if exists --> return/print Intersection.
	// if reach end of l2 --> return / print No Intersection.

	// sets find :  If the element is not found, then the iterator 
	//	points to the position just after the last element in the set.

	while( (p2 != nullptr) && (memorySet.find(p2) != posEnd ) ) {
		p2 = p2->next ;
	}

	if (p2 == nullptr){
		cout << "No intersection found between the 2 linked list" << endl ;
	}
	else { // in this case p2 in memorySet
		cout << "1 intersection found between the 2 linked list at node value " << p2->data << endl ;
	}

}

/* Idea that onces one node is intersecting between the 2 lists, rest of the nodes are the same.
	--> if 2 lists have same size, compare nodes by nodes, and if at some point of time one node 
	is equal between the 2 lists --> intersecting lists.

	--> if 2 lists are different length, only start comparing at node where rest of list starts
	to have the same length.

	--> need a method to compute linked list length

	--> then scroll extra nodes before comparing them.
*/

void testIntersection02(){ // not yet compiled ...
	LinkedList<int> l1 = LinkedList<int>(nullptr);
	LinkedList<int> l2 = LinkedList<int>(nullptr);
	
	//build2IntersectingLists(l1,l2) ;
	build2NONIntersectingLists(l1,l2) ;

	Node<int> * p1(l1.head);
	Node<int> * p2(l2.head);
	int count(0) ;

	// compute length of each list :
	int lengthDiff = l1.getLength() - l2.getLength() ;

	// if (lengthDiff == 0) --> everything is already set to start
	
	if (lengthDiff > 0){ // l1 longuer than l2
		// discard extra first nodes from l1.
		while(count < lengthDiff){
			p1 = p1->next ;
			++count ;
		}
	}
	if (lengthDiff <0){
		// discard extra first nodes from l1.
		while(count > lengthDiff){
			p2 = p2->next ;
			--count ;
		}	
	}

	// At this point, p1 and p2 point to list of same length.
	// we just need now to scroll list until p1/2->next == null.
	// As soon as one node address equal the other --> intersecting lists.

	while( (p1 != p2) && (p1!=nullptr) && (p2 != nullptr)){
		p1 = p1->next ;
		p2 = p2->next ;
	}

	// Now need to test conditions of while exit.
	if ((p1 == nullptr) || (p2 == nullptr)){
		cout << "2 lists did NOT intersect" << endl ;
		return ;
	}
	if (p1 == p2){
		cout << "2 lists DID intersect starting at node value : " << p1->data << endl ;	
		return ;
	}
}

/* Description :
	
	Given a circular linked list, implement an algorthm that returns the node at the beginning of 
	the loop.
	Definition : Circular linked list : a corrupt linked list in which a nodeś next pointer 
	points to an earlier node, so as to make a loop in the linked list.
	
	Example : 
	Input : 	A / B / C / D / E / C (same C as earlier)
	Output : 	C

	Hints :  #50, #69, #83, #90
	
*/

void buildCircularLinkedList(LinkedList<char> & l1){
	// will use 	Node<dataType> * addNodeTop(dataType value){
	// will use 	l1.appendToTail('a');
	Node<char> * pc(nullptr), * p(nullptr) ;

	l1.appendToTail('a');
	l1.appendToTail('b');
	pc = l1.appendToTail('c');
	l1.appendToTail('d');
	l1.appendToTail('e');
	
	// now set tail to point to 'c'

	p = l1.head ;
	while(p->next != nullptr){
		p = p->next ;
	}
	// now p->next == nullptr --> will set it to pc
	p->next = pc ;

	// And now the circular linkedlist is done and circulation node is 'c'
}

void buildNonCircularCharLinkedList(LinkedList<char> & l1){
		// Build l1 
	l1.appendToTail('a');
	l1.appendToTail('t');
	l1.appendToTail('c');
	l1.appendToTail('o');
	l1.appendToTail(' ');
	l1.appendToTail('c');
	l1.appendToTail('t');
	l1.appendToTail('a');
}

void detectCircularLinkedList(LinkedList<char> l){
	Node<char> * p1(nullptr), * p2(nullptr) ;
	
	cout << "Enter detectCircularLinkedList()" << endl ;

	cout << "Testing l.head == nullptr" << endl ;
	if (l.head == nullptr) {return ;}
	cout << "Testing l.head->next == nullptr" << endl ;
	if (l.head->next == nullptr) {return ;}

	p1 = l.head ;
	p2 = p1->next ;
	
	// test 2nd node
	if (p2 == p1) {
		cout << "Found circular linkedList at node : " << p2->data << endl ;
		return ;	
	}

	// test 3rd node and further
	p2 = p2->next ;

	// for each node p2, scrolls previous nodes via p1 and check
	// p2->next != p1
	while(p2 != nullptr){
		cout << "p2 : " << p2->data << " p1 : " << p1->data << endl ; 
		while( (p2->next != p1) && (p1->next != p2) ){
			p1 = p1->next ;
			cout << "p2 : " << p2->data << " p1 : " << p1->data << endl ; 
		}
		if(p2->next == p1){ // found p2 circuled back to p1
			cout << "Found circular linkedList at node : " << p1->data << endl ;
			return ;
		}
		// otherwise the loop terminated due to p1->next == p2 --> switch to p2->next ;
		cout << "p2 = p2->next and p1 = l.head" << endl ;
		p2 = p2->next ;
		p1 = l.head ;
	}
	if( p2 == nullptr){
		cout << "This LinkedList is NON circular." << endl ;
	}

	return ;
}



void testDetectCircularLinkedList(){

	LinkedList<char> l1 = LinkedList<char>(nullptr) ;

	// need to build a circularLinkedList ...
	// will use 	Node<dataType> * addNodeTop(dataType value){
	// will use 	l1.appendToTail('a');

	//buildCircularLinkedList(l1) ;
	//cout << "Circular list built" << endl ;

	buildNonCircularCharLinkedList(l1) ;
	cout << "NON circular list built" << endl ;	

	// now need to detect if circular linkedlist or not
	detectCircularLinkedList(l1) ;
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
	//testSumListForwardOrder();
	//testPalindrome() ;
	//testIntersection() ;
	//testIntersection02() ;
	testDetectCircularLinkedList() ;	

	return 0;
}
/* g++ sortFile.cpp -o sortFile

*/