/* Animal shelter, holds only dogs and cats, operates strictly "first in, first out"basis. 

People must adopt either the "oldest" ()based on arrival time), of all animals at the shelter,
or they can select whether they would prefer a dog or a cat (and will receive the oldest animal 
of that type)

They cannot select which specific animal they would like.

Create the data structures to maintain this system and implement operations such as enqueue, 
dequeueAny, dequeueDog, and dequeueCat.

You may usethe built-in LinkedList data structure.

Hints : #22, #56, #63
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

/* Animal shelter, holds only dogs and cats, operates strictly "first in, first out"basis. 

People must adopt either the "oldest" ()based on arrival time), of all animals at the shelter,
or they can select whether they would prefer a dog or a cat (and will receive the oldest animal 
of that type)

They cannot select which specific animal they would like.

Create the data structures to maintain this system and implement operations such as enqueue, 
dequeueAny, dequeueDog, and dequeueCat.

You may usethe built-in LinkedList data structure.

Hints : #22, #56, #63
*/



// Progress : Not yet implemented.


int main(){

	int mem;
	
	Stack<int> * s = new Stack<int>(0) ;

	s->~Stack() ;
	return 0;
}
/* g++ sortFile.cpp -o sortFile

*/
