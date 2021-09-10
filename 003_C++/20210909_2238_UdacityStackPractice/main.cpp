/* Add a couple methods to our LinkedList class,
and use that to implement a Stack.
You have 4 functions below to fill in:
insert_first, delete_first, push, and pop.
Think about this while you're implementing:
why is it easier to add an "insert_first"
function than just use "append"?*/

#include <iostream>

class Element{
    public:
    	int value;
    	Element * next;

    	// constructor
    	Element(int n){
        	value = n;
        	next = NULL;
        }
};

class LinkedList{
	public:
		Element * pHead;

		// constructor
    	LinkedList(Element * pElement=NULL){
    		pHead = pElement;	
    	}

    	
        void append(Element* pElement){

        	Element * pCurrent = pHead;
        	if(pHead == NULL){
        		pHead = pElement;
        		pHead->next = NULL;
        		return;
        	}
        	while(pCurrent->next != NULL){
        		pCurrent = pCurrent->next;
        	}
        	pCurrent->next = pElement;
        	pElement->next = NULL;
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
         	if(pCurrent == NULL){
        		return;
        	}       	
        	while ((i != position -1) && (pCurrent->next != NULL)){
        		i += 1;
        		pCurrent = pCurrent->next;
			}
			if(i == position -1){
				Element * pNext = pCurrent->next;
				pCurrent->next = p;
				p->next = pNext;
			}
			else{
				std::cout << "Impossible to insert at position " << position << std::endl;
			}
        }

        /* def delete(self, value):
        """Delete the first node with a given value.""" */
        void delete_elem(int value){
        	Element* p = pHead;
        	Element* previous = NULL;
        	Element* toDelete;
        	if(p == NULL){
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
        		}
        		else{
        			toDelete = p;
        			previous->next = p->next;
        			delete toDelete;
        		}

        	}
        }

        /* "Insert new element as the head of the LinkedList"*/
        void insert_first(Element* new_element){
        	if(pHead == NULL){
        		pHead = new_element;
        		pHead->next = NULL;
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
        	return pFirst;
        }
        
};

class Stack{
	public:
		LinkedList ll;
		Stack(Element* top=NULL){
			ll = LinkedList(top);
		}

		// "Push (add) a new element onto the top of the stack"
		void push(Element* e){
			if(e != NULL){
				ll.insert_first(e);				
			}
		}

		// "Pop (remove) the first element off the top of the stack and return it"
		Element* pop(){
			return ll.delete_first();
		}

};


int main() {
	Element * e1 = new Element(1);
	Element * e2 = new Element(2);
	Element * e3 = new Element(3);
	Element * e4 = new Element(4);

	//# Start setting up a Stack
	Stack stack = Stack(e1);

	/*
	# Test stack functionality
	stack.push(e2)
	stack.push(e3)
	print stack.pop().value
	print stack.pop().value
	print stack.pop().value
	print stack.pop()
	stack.push(e4)
	print stack.pop().value
	*/

	stack.push(e2);
	stack.push(e3);
	std::cout << stack.pop()->value << std::endl;
	std::cout << stack.pop()->value << std::endl;
	std::cout << stack.pop()->value << std::endl;
	std::cout << stack.pop() << std::endl;
	stack.push(e4);
	std::cout << stack.pop()->value << std::endl;

	return 0;
}

// g++ .h .cpp -o main.exe