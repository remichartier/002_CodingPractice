/* implement a data structure SetOfStacks that mimics : 

"imagine a stack of plates. If the stack gets too high, 
it might topple, therefore in real life, we would likely 
start a new stack when the previous stack exceeds some threshold"

SetOfStacks should be composed of several stacks
and should create a new stack once the previous one 
exceeds capacity.
its method push() and pop() should behave identically to a single stack
(ie pop should return the same value as it would if there were just a single 
stack)

FOLLOW UP : 
Implement a function popAt(int index) which performs a pop operation on a 
specific sub-stack.

Hints : #64, #81
*/

/* Description :
	Stack = LIFO Last In First Out
	pop()
	push(item)
	peek()
	isEmpty()	
	
*/
#include<iostream>
#include<vector>

using namespace std;

template <class T> class Node {
	private : 
		T data;
		Node<T> * next;

	public : 
		// Constructor
		Node<T> (T d){
			cout << "Node constructor called" << endl ;
			data = d;
			next = nullptr ;
		}

		T getData(){
			return data ;
		}
		void setNext(Node<T> * p){
			next = p ;
		}
		Node<T> * getNext(){
			return next ;
		}
};

template <class T> class Stack {
	
	private : 
		Node<T> * top ;
		int size ;
	public : 
		//Constructor
		Stack(T d){
			cout << "Stack constructor called" << endl ;
			top = new Node<T>(d) ;
			size = 1 ;
		}
		//Destructor
		~Stack(){
			cout << "Stack destructor called" << endl ;
			while(!isEmpty()){
				pop();
			}
		}

		T pop(){
			if (isEmpty()){ 
				cout << "Stack is empty !!! ";
			}
			else {
				T item = top->getData() ;
				Node<T> * n = top ;
				top = top->getNext() ;
				delete n ;
				n = nullptr ;
				-- size;
				return item ;	
			}
		}

		void push(T item){
			Node<T> * n = new Node<T>(item) ;
			n->setNext(top) ;
			top = n ;
			++ size ;
		}	

		T peek(){ // return top item of stack
			if(isEmpty()) {
				cout << "Stack is empty !!!" ; 
			}
			else{
				return top->getData() ;	
			}			
		}

		bool isEmpty(){
			return(top == nullptr);
		}

		void print(){
			if(isEmpty()){
				cout << "Stack is empty !!!" << endl ;
				return ;
			}
			cout << "Stack content : " ;
			Node<T> * p(top) ;
			while( p != nullptr){
				cout << p->getData() << " | " ;
				p = p->getNext() ;
			}
			cout << endl ;
		}

		int getSize(){
			return(size) ;
		}
};


/* implement a data structure SetOfStacks that mimics : 

"imagine a stack of plates. If the stack gets too high, 
it might topple, therefore in real life, we would likely 
start a new stack when the previous stack exceeds some threshold"

SetOfStacks should be composed of several stacks
and should create a new stack once the previous one 
exceeds capacity.
its method push() and pop() should behave identically to a single stack
(ie pop should return the same value as it would if there were just a single 
stack)

FOLLOW UP : 
Implement a function popAt(int index) which performs a pop operation on a 
specific sub-stack.

Hints : #64, #81
*/

/* reflexion :
should also have methods : 

	pop()
	push(item)	

	- Needs to have a threshold parameter or constant.

	- Suggest a dynamic table/vector of stacks
	- attribute number of stacks.
	- definition of threshold.

*/

# define MAX_STACK_SIZE  3

template <class T> class SetOfStacks{
	private : 
		vector<Stack<T> *> listOfStacks ;
		unsigned int nbStack ;

		
	public : 
		// constructor
		SetOfStacks(){
			nbStack = 0 ;
		}

		// destructor
		~SetOfStacks(){
			cout << "listOfStacks destructor called" << endl;
			while (nbStack > 0){
				pop() ;
			}
			
		}

		void push(T data){
			if(nbStack == 0){
				// need to create stack, add it to list of stacks, increment nbStack
				listOfStacks.push_back(new Stack<T>(data));
				++nbStack ;
			}
			else {
				//test size latest stack.
				// depending of size, add to current stack or create new stack.
				
				// get current stack : 
				Stack<T> * currentStack = listOfStacks.back() ;
				// if stack not yet full
				if (currentStack->getSize() < MAX_STACK_SIZE){
					// we can push on current stack
					currentStack->push(data) ;
				}
				else {
					// need to create a new stack with this new data, 
					// and add it to list
					Stack<T> * currentStack = new Stack<T>(data) ;
					listOfStacks.push_back(currentStack);
					++nbStack ;
				}

			}
		}

		T pop(){
			// test that setOfStacks not empty, otherwise raise exception ....

			// get current stack.
			Stack<T> * currentStack = listOfStacks.back() ;
			// pop() from current stack.
			T data = currentStack->pop() ;
			// if current stack is empty, remove stack from setOfStacks.
			if (currentStack->getSize() == 0){
				listOfStacks.pop_back() ;
				--nbStack ;
				// free currentStack...
				currentStack->~Stack();
			}
			//return data popped
			return data ;
		}

		void print(){
			if(nbStack == 0){
				// need to create stack, add it to list of stacks, increment nbStack
				cout << "ListOfStacks is empty ...." << endl ;
			}
			else {
				cout << "Content of ListOfStacks : ...." << endl ;
				
				for(auto p : listOfStacks){
					p->print() ;
				}

			}	
		}

};




int main(){

	cout << "setOfStacks push(0)" << endl ;
	
	SetOfStacks<int> * s = new SetOfStacks<int>() ;
	for(int i=0;i<10;++i){
		s->push(i) ;
	}
	
	s->print() ;
	s->pop();
	s->print() ;
	s->pop() ;
	s->print() ;
	s->~SetOfStacks() ;
	s->print() ;



	return 0;
}
/* g++ sortFile.cpp -o sortFile

*/
