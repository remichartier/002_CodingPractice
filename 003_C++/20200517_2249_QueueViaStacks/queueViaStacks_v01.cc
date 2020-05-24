/* implement a MyQueue class which implements a queue using two stacks

Hints : #98, #114
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

		// Destructor
		~Node(){
			cout << "Node destructor called" << endl ;
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
		//int size ; // here in this exercise, we will not use this parameter.
	public : 
		//Constructor
		Stack(T d){
			cout << "Stack constructor called" << endl ;
			top = new Node<T>(d) ;
			//size = 1 ;
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
				cout << "Can not pop() : Stack is empty !!! " << endl ;
			}
			else {
				T item = top->getData() ;
				Node<T> * n = top ;
				top = top->getNext() ;
				delete n ;
				n = nullptr ;
				//--size;
				return item ;	
			}
		}

		void push(T item){
			Node<T> * n = new Node<T>(item) ;
			n->setNext(top) ;
			top = n ;
			//++ size ;
		}	

		T peek(){ // return top item of stack
			if(isEmpty()) {
				cout << "Can not peek() : Stack is empty !!!" << endl ; 
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

		/*int getSize(){
			return(size) ;
		}
		*/
};

/* implement a MyQueue class which implements a queue using two stacks

Hints : #98, #114
*/

enum LastAction {PUSH,POP} ;

template <class T> class MyQueue{
	private : 
		Stack<T> * mainStack;
		Stack<T> * pullStack;
		LastAction lastAction;
		
	public : 
		// constructor
		MyQueue(T data){
			 mainStack = new Stack<T>(data);
			 pullStack = new Stack<T>(data); 
			 pullStack->pop();
			 lastAction = PUSH ;
		}

		// destructor
		~MyQueue(){
			cout << "listOfStacks destructor called" << endl;
			if(mainStack != nullptr){
				mainStack->~Stack();
				mainStack = nullptr;
			}
			if(pullStack != nullptr){
				pullStack->~Stack();
				pullStack = nullptr;
			}
		}

		// Methods
		void push(T data){
			
			if(lastAction == POP){
				// need to rebuild mainStack from pullStack
				reverseStack(pullStack,mainStack);
			}
			mainStack->push(data);
			lastAction = PUSH ;
		}

		T pop(){
			// test if there is something to pop !!!!
			if((lastAction == POP) && (pullStack->isEmpty())){
				cout << "Sorry, Queue already empty, can not pop anything, return 0 as default !" << endl ;
				return 0;
			}

			if(lastAction == PUSH){
				// need to rebuild pullStack from mainStack
				reverseStack(mainStack,pullStack);
			}	
			
			lastAction = POP ;
			return(pullStack->pop());
		}

		void reverseStack(Stack<T> * pSource, Stack<T> * pTarget){
			// remove target stack and create it again
			if (pSource->isEmpty()){
				//cout << "reverseStack() : source stack is empty" << endl ;
				return;
			}

			//cout << "Empty pTarget" << endl ;
			while(!pTarget->isEmpty()){
				pTarget->pop();
			}
			
			while(!pSource->isEmpty()){
				//cout << "while(!pSource->isEmpty())" << endl ;
				//cout << "T data = pSource->pop() ;" << endl ;
				T data = pSource->pop() ;
				//cout << "pTarget->push(data);" << endl ;
				pTarget->push(data);	
			}
		}


		void print(){
			if(lastAction == POP){
				// only need to print pull stack ...
				cout << "last action == POP --> pullStack->print()" << endl;
				pullStack->print();
			}
			else{ // lastAction == PUSH
				// Then need to reverse mainStack, print pull stack, and reverse it back to mainStack ...
				cout << "last action == PUSH --> reverse, pullStack-> print(), reverse" << endl;
				cout << "reverseStack(mainStack,pullStack);" << endl;
				reverseStack(mainStack,pullStack);
				cout << "pullStack->print();" << endl;
				pullStack->print();
				cout << "reverseStack(pullStack,mainStack);" << endl;
				reverseStack(pullStack,mainStack);
			}
		}

};

// NOTE : Now fully compile, + tested... Working


int main(){

	int i;
	cout << "setOfStacks push(0)" << endl ;
	
	MyQueue<int> * s = new MyQueue<int>(0) ;
	for(i=1;i<10;++i){
		s->push(i) ;
	}
	cout << "s->print()" << endl ;
	s->print() ;
	cout << "s->pop()" << endl ;
	s->pop();
	cout << "s->print()" << endl ;
	s->print() ;


	cout << "s->push(++1)" << endl ;
	s->push(++i);
	cout << "s->print()" << endl ;
	s->print() ;

	cout << "s->pop()" << endl ;
	s->pop() ;
	cout << "s->print()" << endl ;
	s->print() ;
	cout << "s->pop()" << endl ;
	s->pop() ;
	cout << "s->print()" << endl ;
	s->print() ;
	cout << "s->pop()" << endl ;
	s->pop() ;
	cout << "s->print()" << endl ;
	s->print() ;
	cout << "s->pop()" << endl ;
	s->pop() ;
	cout << "s->print()" << endl ;
	s->print() ;

	cout << "s->push(++1)" << endl ;
	s->push(++i);
	cout << "s->print()" << endl ;
	s->print() ;



	cout << "s->pop()" << endl ;
	s->pop() ;
	cout << "s->print()" << endl ;
	s->print() ;
	cout << "s->pop()" << endl ;
	s->pop() ;
	cout << "s->print()" << endl ;
	s->print() ;
	

	cout << "s->push(++1)" << endl ;
	s->push(++i);
	cout << "s->print()" << endl ;
	s->print() ;


	cout << "s->pop()" << endl ;
	s->pop() ;
	cout << "s->print()" << endl ;
	s->print() ;
	cout << "s->pop()" << endl ;
	s->pop() ;
	cout << "s->print()" << endl ;
	s->print() ;
	cout << "s->pop()" << endl ;
	s->pop() ;
	cout << "s->print()" << endl ;
	s->print() ;
	
	cout << "s->push(++1)" << endl ;
	s->push(++i);
	cout << "s->print()" << endl ;
	s->print() ;

	cout << "s->push(++1)" << endl ;
	s->push(++i);
	cout << "s->print()" << endl ;
	s->print() ;

	cout << "s->pop()" << endl ;
	s->pop() ;
	cout << "s->print()" << endl ;
	s->print() ;
	
	cout << "s->~MyQueue()" << endl ;
	s->~MyQueue() ;
	

	return 0;
}
/* g++ sortFile.cpp -o sortFile

*/
