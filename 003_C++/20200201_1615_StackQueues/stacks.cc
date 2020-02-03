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
			data = d;
			next = nullptr ;
		}
};

template <class T> class Stack {
	
	private : 
		Node<T> * top ;
	public : 
		//constructor
		Stack(T d){
			top = new Node<T>(d) ;
		}

		T pop(){
			if (top == nullptr){ return NULL ;}
			T item = top->data ;
			top = top->next ;
			return item ;
		}

		void push(T item){
			Node<T> * n = new Node<T>(item) ;
			n->next = top ;
			top = n ;
		}	

		T peek(){ // return top item of stack
			if( top == nullptr) {return NULL ; }
			return top->data ;
		}

		bool isEmpty(){
			return(top == nullptr);
		}
};

int main(){

	return 0;
}
/* g++ sortFile.cpp -o sortFile

*/