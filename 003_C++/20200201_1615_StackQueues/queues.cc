/* Description :
	Stack = LIFO Last In First Out
	pop()
	push(item)
	peek()
	isEmpty()	

	Queue = FIFO
	add() item at the end
	remove() first item of the list
	peek() returns the top of the queue
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
			data = d;
			next = nullptr ;
		}
};

template <class T> class Queue {
	
	private : 
		Node<T> * top ;
		Node<T> * bottom ;
		
	public : 
		//constructor
		Queue(T d){
			top = new Node<T>(d) ;
			bottom = top ;
		}

		void add(T item){
			Node<T> * n = new Node<T>(item);
			if (bottom == nullptr){ 
				top = n ;
			}
			else {
				bottom->next = n ;
			}
			bottom = n ;
			n->next = nullptr ;		
		}

		T remove(){
			T item ;
			if( top == nullptr){
				cout << "remove() impossible, Queue empty." << endl ;
				return NULL ;
			}
			item = top->data ;
			Node<T> * toRemove(top) ;
			top = top->next ;
			if (top == nullptr) { bottom = nullptr ;}
			free(toRemove);
			return item ;
		}	

		T peek(){ // return top item of stack
			if( top == nullptr) {return NULL ; }
			return top->data ;
		}

		bool isEmpty(){
			return (top == nullptr) ;
		}
};

int main(){

	return 0;
}
/* g++ sortFile.cpp -o sortFile

*/