/* """Make a Queue class using a list!
Hint: You can use any Python list method
you'd like! Try to write each one in as 
few lines as possible.
Make sure you pass the test cases too!"""*/

#include <iostream>

class Element{
    public:
    	int value;
    	Element * next;
    	Element * previous;

    	// constructor
    	Element(int n){
        	value = n;
        	next = NULL;
        	previous = NULL;
        }
};

class DoubleLinkedList{
	public:
		Element * pHead;
		Element * pTail;

		// constructor
    	DoubleLinkedList(Element * pElement=NULL){
    		pHead = pElement;
    		pTail = pHead;	
    		pHead->next = NULL;
    		pHead->previous = NULL;
    	}
    	
        void append(Element* pElement){
        	if( (pHead == NULL) || (pTail == NULL) || (pElement == NULL)){
        		std::cout << "Impossible to append : one of the elements involved is NULL" << std::endl;
        		return;	
        	}
        	pTail->next = pElement;
        	pElement->previous = pTail;
        	pTail = pElement;
        	pTail->next = NULL;
        }

        void print(){
        	Element * pCurrent = pHead;

        	std::cout << "list content = ";
        	while(pCurrent != NULL){
        		std::cout << pCurrent->value << ";" ;
        		pCurrent = pCurrent->next;
        	}
        	std::cout << std::endl;
        }

        /* 
        get_position(self, position):
        """Get an element from a particular position.
        Assume the first position is "1".
        Return "None" if position is not in the list."""
        */

        Element * get_position(int position){
        	int i = 1;
        	Element* pCurrent = pHead;
        	if(pCurrent == NULL){
        		return NULL;
        	}
        	while((i != position) && (pCurrent->next != NULL)){
        		pCurrent = pCurrent->next;
        		i++;
        	}
        	if (i == position){
        		return pCurrent;
        	}
        	else{
        		return NULL;
        	}
        }

        /* def insert(self, new_element, position):
        """Insert a new node at the given position.
        Assume the first position is "1".
        Inserting at position 3 means between
        the 2nd and 3rd elements.""" */
        void insert(Element* p, int position){
        	Element * pCurrent = pHead;
        	int i = 1;
         	if((pCurrent == NULL) || (pHead == NULL) || (pTail == NULL)){
        		std::cout << "Impossible to insert : one of the elements involved is NULL" << std::endl;
        		return;
        	}       	
        	while ((i != position -1) && (pCurrent->next != NULL)){
        		i += 1;
        		pCurrent = pCurrent->next;
			}
			if(i == position -1){
				Element* pNext = pCurrent->next;
				pCurrent->next = p;
				p->previous = pCurrent;
				p->next = pNext;
				if(pNext == NULL){
					pTail = p;
				}
				else{
					pNext->previous =  p;
				}
			}
			else{
				std::cout << "Impossible to insert at position " << position << std::endl;
			}
        }

        /* def delete(self, value):
        """Delete the first node with a given value.""" */
        // note : could optimize with introduction of field previous but did not yet
        void delete_elem(int value){
        	Element* p = pHead;
        	Element* previous = NULL;
        	Element* toDelete;
        	if((pHead == NULL) || (pTail == NULL)){
        		std::cout << "Impossible to delete : one of the elements involved is NULL" << std::endl;
        		return;
        	}
        	while((p->value != value) && (p->next != NULL)){
        		previous = p;
        		p = p->next;
        	}
        	if (p->value == value){
        		if(previous == NULL){
        			toDelete = pHead;
        			pHead = pHead->next;
        			delete toDelete;
        			if (pHead == NULL){
        				pTail == NULL;
        			}
        		}
        		else{
        			toDelete = p;
        			previous->next = p->next;
        			if (previous->next == NULL){
        				pTail = previous;
        			}
        			delete toDelete;
        		}

        	}
        }

        /* "Insert new element as the head of the LinkedList"*/
        void insert_first(Element* new_element){
        	if(pHead == NULL){
        		pHead = new_element;
        		pHead->next = NULL;
        		pHead->previous = NULL;
        		pTail = pHead;
        		return;
        	}
        	new_element->next = pHead;
        	pHead = new_element;
        }
        

    	/*"Delete the first (head) element in the LinkedList as return it"*/
        Element* delete_first(){
        	Element* pFirst;
        	if(pHead == NULL){
        		return NULL;
        	}
        	pFirst = pHead ;
        	pHead = pHead->next;
        	if(pHead == NULL){
        		pTail == NULL;
        	}
        	else {
        		pHead->previous = NULL;
        	}
        	return pFirst;
        }

		Element* delete_last(){
        	Element* pFirst;
        	if((pHead == NULL) || (pTail == NULL)){
        		std::cout << "Impossible to delete : no Head or Tail element" << std::endl;
         		return NULL;
        	}
        	pFirst = pHead;
        	pHead = pHead->next;
        	if(pHead == NULL){
        		pTail = NULL;
        	}
        	return pFirst;
        }

}; // End DoubleLinkedList

/*
class Queue:
    def __init__(self, head=None):
        self.storage = [head]

    def enqueue(self, new_element):
        pass

    def peek(self):
        pass 

    def dequeue(self):
        pass
*/

class Queue{
	public:
		DoubleLinkedList ll;
		Queue(Element* head=NULL){
			//std::cout << "ll = DoubleLinkedList(head);" << std::endl;
			//ll = DoubleLinkedList(head);
		}

		// def enqueue(self, new_element):
		void enqueue(Element* e){
			if(e != NULL){
				ll.append(e);				
			}
		}

		// "def peek(self):
		// Peek : look at element but do not actually remove it.
		Element* peek(){
			return ll.get_position(1);
		}

		// def dequeue(self):
		Element* dequeue(){
			return ll.delete_first();

		}

};


int main() {
	Element * e1 = new Element(1);
	Element * e2 = new Element(2);
	Element * e3 = new Element(3);
	Element * e4 = new Element(4);
	Element * e5 = new Element(5);

	/* To do : 
	# Setup
	q = Queue(1)
	q.enqueue(2)
	q.enqueue(3)
	*/

	std::cout << "Start" << std::endl;

	Queue q = Queue(e1);
#if 0	
	q.enqueue(e2);
	q.enqueue(e3);

	/*# Test peek
	# Should be 1
	print q.peek()
	*/

	std::cout << "should be 1 : " << q.peek()->value << std::endl;

	/*# Test dequeue
	# Should be 1
	print q.dequeue()*/
	std::cout << "should be 1 : " << q.dequeue()->value << std::endl;

	/*# Test enqueue
	q.enqueue(4)
	# Should be 2
	print q.dequeue()
	# Should be 3
	print q.dequeue()
	# Should be 4
	print q.dequeue()
	*/
	q.enqueue(e4);
	std::cout << "should be 2 : " << q.dequeue()->value << std::endl;
	std::cout << "should be 3 : " << q.dequeue()->value << std::endl;
	std::cout << "should be 4 : " << q.dequeue()->value << std::endl;

	q.enqueue(e5);
	// # Should be 5
	std::cout << "should be 5 : ";
	q.peek();

#endif
	return 0;
}

// g++ .h .cpp -o main.exe