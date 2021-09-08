
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
    	LinkedList(Element * pElement){
    		pHead = pElement;	
    	}
};


int main() {
	Element * e1 = new Element(1);
	Element * e2 = new Element(2);
	LinkedList * list = new LinkedList(e1);

	std::cout << "element e1 value : " << e1->value << std::endl;
	std::cout << "list 1st element value : " << list->pHead->value << std::endl;

	e1->next = e2;

	std::cout << "list 2nd element value : " << list->pHead->next->value << std::endl;


	return 0;
}

// g++ .h .cpp -o main.exe