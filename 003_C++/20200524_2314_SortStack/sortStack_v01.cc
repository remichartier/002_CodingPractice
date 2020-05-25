/* write a program to sort a stack such that the smallest items are on the tops.
You can use an additional temporary stack, but you may not copy the elementes 
into any other data structure (such as an array). 
The stack supports the following operations : push, pop, peek, and isEmpty.

Hints : #15, #32, #43
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
#include <stdlib.h>     /* srand, rand */

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
		Stack(){
			cout << "Stack constructor called" << endl ;
			top = nullptr ;
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

/* write a program to sort a stack such that the smallest items are on the tops.
You can use an additional temporary stack, but you may not copy the elementes 
into any other data structure (such as an array). 
The stack supports the following operations : push, pop, peek, and isEmpty.

Hints : #15, #32, #43
*/



// Progress : still under work, not compiling yet, not runable yet


int main(){

	int mem;
	
	Stack<int> * s = new Stack<int>(0) ;

	// create empty sorted stack
	Stack<int> * sorted = new Stack<int>() ;

	// fill s stack with random numbers
	for(int i=1;i<10;++i){
		s->push(rand()) ;
	}

	// print s stack to check
	cout << "s->print()" << endl ;
	s->print() ;
	
	// Algorithm : 
	// pull top of s stack, push to sorted stack.
	// then while s not empty
		// pull top of s stack.
		// if <= top sorted stack
			// push to sorted stack
		// if > top sorted stack
			// keep it in mem variable.
			// while (sorted not empty) and mem > sorted.peek()
				//s.push(sorted.pull())
			// if mem < sorted.peek()
				//sorted.push(mem)
	// end while	
	// at the end, we have a sorted stack in sorted
	// print sorted.


	// Algorithm implementation : 
	// pull top of s stack, push to sorted stack.
	sorted->push(s->pop()) ;
	// then while s not empty
	while(!s->isEmpty()){
		// pull top of s stack.
		mem = s->pop();
		// if <= top sorted stack
		if(mem <= sorted->peek()){
			// push to sorted stack
			sorted->push(mem);
		}
		// if > top sorted stack
		else {
			// keep it in mem variable.
			// while (sorted not empty) and mem > sorted.peek()
			while((!sorted->isEmpty()) && (mem > sorted->peek()) ){
				//s.push(sorted.pull())
				s->push(sorted->pop()) ;
			}
			// if mem < sorted.peek()
			if(mem < sorted->peek()){
				//sorted.push(mem)
				sorted->push(mem) ;
			}
			
		}
	// end while
	}
			
	// at the end, we have a sorted stack in sorted
	// print sorted.	

	cout << "s->print()" << endl ;
	s->print() ;
	cout << "sorted->print()" << endl ;
	sorted->print() ;


	// terminate program, release resources
	s->~Stack() ;
	sorted->~Stack() ;
	return 0;
}
/* g++ sortFile.cpp -o sortFile

*/
