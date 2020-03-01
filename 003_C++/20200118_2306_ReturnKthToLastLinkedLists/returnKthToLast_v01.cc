/* Description :
Implement an algorithm to find the Kth to last element of a singly linked list

	Hints :  #8, #25, 41, 67, 126

*/

/*
Have array of size K to store the latest K elements read. 
Use rotational array / with modulos to store the elements read.
scroll list until the end. if l is the index of the latest element, (l+1)%k is the kth element...
*/

/* Note : TO BE DONE.

	THE free() OF NODES SHOULD BE REPLACECED BY "delete ptr ; ptr = nullptr ;"	+ CLASS DESTRUCTORS SHOULD BE IMPLEMENTED !


	AND ALL POINTERS SHOULD BE "deleted" AT THE END + SET TO nullptr

	+ CLASS DESTRUCTORS SHOULD BE IMPLEMENTED !
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

		// appendToTail()
		void appendToTail(int d){
			Node * n = new Node(d) ;
			if (head == NULL){
				// ie linked list is empty
				// --> create head node.
				head = n ;
			}
			else {
				// scroll head to last node.
				// add node and link it to last node.
				Node * p = head;
				while (p->next != NULL){
					p = p->next ;
				}				
				p->next = n ;
			}
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

};

int main(){
	//create linkedList with nodes, then print the nodes
	Node * n = new Node(0) ;
	Node * k ;

	LinkedList l = LinkedList(n);
	l.printLinkedList() ;
	cout << "l.appendToTail(1) ;" << "\n" ;
	l.appendToTail(1) ;
	l.printLinkedList() ;
	cout << "l.appendToTail(2) ;" << "\n" ;
	l.appendToTail(2) ;
	l.printLinkedList() ;
	cout << "l.appendToTail(3) ;" << "\n" ;
	l.appendToTail(3) ;
	l.printLinkedList() ;
	cout << "l.appendToTail(2) ;" << "\n" ;
	l.appendToTail(2) ;
	l.printLinkedList() ;
	cout << "l.appendToTail(1) ;" << "\n" ;
	l.appendToTail(1) ;
	l.printLinkedList() ;
	cout << "l.appendToTail(0) ;" << "\n" ;
	l.appendToTail(0) ;
	l.printLinkedList() ;
	l.printLinkedList() ;
	cout << "l.appendToTail(1) ;" << "\n" ;
	l.appendToTail(1) ;
	l.printLinkedList() ;
	cout << "l.appendToTail(2) ;" << "\n" ;
	l.appendToTail(2) ;
	l.printLinkedList() ;
	cout << "l.appendToTail(3) ;" << "\n" ;
	l.appendToTail(3) ;
	l.printLinkedList() ;
	cout << "l.appendToTail(2) ;" << "\n" ;
	l.appendToTail(2) ;
	l.printLinkedList() ;
	cout << "l.appendToTail(1) ;" << "\n" ;
	l.appendToTail(1) ;
	l.printLinkedList() ;
	cout << "l.appendToTail(0) ;" << "\n" ;
	l.appendToTail(0) ;
	l.printLinkedList() ;
	/*
	cout << "l.deleteNode(1) ;" << "\n" ;
	l.deleteNode(1) ;
	l.printLinkedList() ;
	*/
	/*cout << "l.removeDuplicates() ;" << "\n" ;
	l.removeDuplicates02() ;
	l.printLinkedList() ;
	*/

	int number(3);
	k = l.kthToLastBuffer(number);
	if(k != NULL){
		cout << "l.kthToLase(" << number <<") =" << k->data << "\n" ;
	}
	else {
		cout << "Impossible to find " << number << " To Last : " << number << " > sizeList " << "\n" ;	
	}
	/*k = l.kthToLast(2);
	cout << "l.kthToLase(2) =" << k->data << "\n" ;
	k = l.kthToLast(1);
	cout << "l.kthToLase(1) =" << k->data << "\n" ;
	*/

	int counter;
	bool result ;
	result = l.printKth2LastRecursive(l.head,number, counter);
	if (!result) {
		cout << "Impossible to find " << number << " to LAST value\n" ;
	}

	k = l.kthToLast2Pointers(number) ;
	if(k != NULL){
		cout << "l.kthToLase(" << number <<") =" << k->data << "\n" ;
	}
	else {
		cout << "Impossible to find " << number << " To Last : " << number << " > sizeList " << "\n" ;	
	}
	return 0;
}
/* g++ sortFile.cpp -o sortFile

*/