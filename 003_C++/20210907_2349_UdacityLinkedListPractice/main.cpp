
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
        	Element *pCurrent = pHead;
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
};


int main() {
	Element * e1 = new Element(1);
	Element * e2 = new Element(2);
	Element * e3 = new Element(3);
	Element * e4 = new Element(4);

	LinkedList * list = new LinkedList(e1);
	list->print();

	list->append(e2);
	list->print();
	list->append(e3);
	list->print();

	// Should also print 3
	// print ll.get_position(3).value
	std::cout << "Position 3 : " << list->get_position(3)->value << std::endl;

	// # Test insert
	list->insert(e4,3);
	// # Should print 4 now
	std::cout << "Position 3 : " << list->get_position(3)->value << std::endl;

	return 0;
}

// g++ .h .cpp -o main.exe