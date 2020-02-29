/* Description :

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
			cout << "Node constructor called" << endl ;
			data = d;
			next = nullptr ;
		}

		T getData(){
			return data;
		}

		Node<T> * getNext(){
			return next ;
		}

		void setNext(Node<T> * p){
			next = p ;
		}
};

template <class T> class Queue {
	
	private : 
		Node<T> * top ;
		Node<T> * bottom ;
		
	public : 
		//constructor
		Queue(T d){
			cout << "Queue constructor called" << endl ;
			top = new Node<T>(d) ;
			bottom = top ;
		}

		// destructor
		~Queue(){
			cout << "Queue destructor called" << endl ;
			while(!isEmpty()){
				remove();
			}
		}

		void add(T item){
			Node<T> * n = new Node<T>(item);
			if (bottom == nullptr){ 
				top = n ;
			}
			else {
				bottom->setNext(n);
			}
			bottom = n ;
			n->setNext(nullptr) ;		
		}

		T remove(){
			T item ;
			if( top == nullptr){
				cout << "remove() impossible, Queue empty." << endl ;

			}
			else {
				item = top->getData() ;
				Node<T> * toRemove(top) ;
				top = top->getNext() ;
				if (top == nullptr) { bottom = nullptr ;}
				delete toRemove;
				toRemove = nullptr ;
				return item ;	
			}
			
		}	

		T peek(){ // return top item of stack
			if( top == nullptr) {
				cout << "Queue is empty ! "; 
			}
			else{
				return top->getData() ;	
			}
			
		}

		bool isEmpty(){
			return (top == nullptr) ;
		}

		void printQueue(){
		 	Node<T> * n(top);
		 	if(isEmpty()){
		 		cout << "Queue is empty --> printout impossible\n" ;
		 		return ;
		 	}
		 	cout << "Queue printout  : "  ;
		 	while( n != nullptr){
		 		cout << n->getData() << " | " ;
		 		n = n->getNext() ;
		 	}
		 	cout << endl ;
		}
};

int main(){
	// test of queues class.
	cout << "Creating a queue" << endl ;
	Queue<int> q = Queue<int>(5) ;
	
	cout << "Add 5 to queue" << endl ;
	q.add(5) ;
	q.printQueue();

	cout << "Add 6 to queue" << endl ;
	q.add(6) ;
	q.printQueue();

	cout << "Add 7 to queue" << endl ;
	q.add(7) ;
	q.printQueue();

	cout << "Add 8 to queue" << endl ;
	q.add(8) ;
	q.printQueue();

	cout << "Add 9 to queue" << endl ;
	q.add(9) ;
	q.printQueue();

	cout << "Add 10 to queue" << endl ;
	q.add(10) ;
	q.printQueue();


	cout << "TOP OF THE QUEUE : " << q.peek() << endl ;
	

	cout << "Process queue element" << endl ;
	q.remove() ;
	q.printQueue();

	cout << "Process queue element" << endl ;
	q.remove() ;
	q.printQueue();

	cout << "Process queue element" << endl ;
	q.remove() ;
	q.printQueue();

	cout << "Process queue element" << endl ;
	q.remove() ;
	q.printQueue();

	cout << "Process queue element" << endl ;
	q.remove() ;
	q.printQueue();

	cout << "Process queue element" << endl ;
	q.remove() ;
	q.printQueue();

	cout << "Process queue element" << endl ;
	q.remove() ;
	q.printQueue();

	cout << "Process queue element" << endl ;
	q.remove() ;
	q.printQueue();

	cout << "Process queue element" << endl ;
	q.remove() ;
	q.printQueue();

	cout << "TOP OF THE QUEUE : " << q.peek() << endl ;

	return 0;
}
/* g++ sortFile.cpp -o sortFile

*/