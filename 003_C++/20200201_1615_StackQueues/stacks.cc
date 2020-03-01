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