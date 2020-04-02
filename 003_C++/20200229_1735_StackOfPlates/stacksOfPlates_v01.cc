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
	public : 
		//Constructor
		Stack(T d){
			cout << "Stack constructor called" << endl ;
			top = new Node<T>(d) ;
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
				return item ;	
			}
		}

		void push(T item){
			Node<T> * n = new Node<T>(item) ;
			n->setNext(top) ;
			top = n ;
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

# define MAX_TAX_SIZE = 10

template <class T> SetOfStacks{
	private : 
		vector<Stacks> listOfStacks ;
		unsigned int nbStack ;

		
	public : 
		// constructor
		SetOfStacks(){
			nbStack = 0 ;
		}

		void push<T>(T data){
			if(nbStack == 0){
				// need to create stack, add it to list of stacks, increment nbStack
				listOfStacks.push_back(new Stack<T>(data));
				++nbStack ;
			}
			else {
				//test size latest stack.
				// depending of size, add to current stack or create new stack.
				
			}
		}

};




int main(){

	cout << "Stack creation with 0" << endl ;
	Stack<int> stck = Stack<int>(0) ;
	stck.print();

	cout << "Add to stack 1" << endl ;
	stck.push(1) ;
	stck.print();

	cout << "Add to stack 2" << endl ;
	stck.push(2) ;
	stck.print();

	cout << "Add to stack 3" << endl ;
	stck.push(3) ;
	stck.print();

	cout << "Add to stack 4" << endl ;
	stck.push(4) ;
	stck.print();

	cout << "Add to stack 5" << endl ;
	stck.push(5) ;
	stck.print();

	cout << "Add to stack 6" << endl ;
	stck.push(6) ;
	stck.print();

	cout << "TOP OF STACK : " << stck.peek() << endl ;

	cout << "pop() !!!!" << endl ;
	stck.pop() ;
	stck.print();

	cout << "pop() !!!!" << endl ;
	stck.pop() ;
	stck.print();

	cout << "pop() !!!!" << endl ;
	stck.pop() ;
	stck.print();

	cout << "pop() !!!!" << endl ;
	stck.pop() ;
	stck.print();

	cout << "pop() !!!!" << endl ;
	stck.pop() ;
	stck.print();

	cout << "pop() !!!!" << endl ;
	stck.pop() ;
	stck.print();

	cout << "pop() !!!!" << endl ;
	stck.pop() ;
	stck.print();

	cout << "pop() !!!!" << endl ;
	stck.pop() ;
	stck.print();

	cout << "pop() !!!!" << endl ;
	stck.pop() ;
	stck.print();

	cout << "TOP OF STACK : " << stck.peek() << endl ;


	return 0;
}
/* g++ sortFile.cpp -o sortFile

*/
