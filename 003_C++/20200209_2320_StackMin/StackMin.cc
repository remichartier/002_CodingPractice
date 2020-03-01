/* Description :
How would you design a stack, which in addition to push and pop, 
has a function min() which returns the minimum element ? 
push, pop min should operate in O(1) time.
Hints : #27, 59, 78
*/

/* 

*/
#include<iostream>
using namespace std;

// Not yet compiled neither used
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
		// Destructor : not needed. Default one is enough
};


// Not yet compiled neither used.
template <class T> class Stack {
	
	private : 
		Node<T> * top ;
	public : 
		//constructor
		Stack(T d){
			top = new Node<T>(d) ;
		}

		// destructor 
		~Stack(){
			cout << "destructor() Stack called"<< endl ;
			// need to pop all the nodes ....
			while(!isEmpty()){
				pop();
			}
		}

		T pop(){
			if (top == nullptr){ return NULL ;}
			T item = top->data ;
			Node<T> * n(top);
			top = top->next ;
			delete n ;
			n = nullptr;
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

		void printStack(){
			if(top == nullptr){
				cout << "Stack is empty" << endl ;
				return ;
			}
			Node<T> * p(top) ;
			while(p!=nullptr){
				cout << "; " << p->data << " " ;
				p = p->next ;
			}
		}
};

/* Description :
How would you design a stack, which in addition to push and pop, has a function min() which returns the minimum element ? push, pop min should operate in O(1) time.
Hints : #27, 59, 78
*/

/* 
- Need 2nd item in node to indicate the minimum of all values so far.
- Because when pushing, we compare to the minimum already pushed.
- However when popping, we do not have history of minimums so far, we would have to scroll all the stack
to calculate the minimum, which we do not have the ability to (no methods exist to do so)
*/

template <class T> class NodeMin {
	private : 
		T data;
		T stackMin;
		NodeMin<T> * next;
	public : 
		// Constructor
		NodeMin<T> (T d,T minValue){
			cout << "NodeMin constructor called" << endl ;
			data = d;
			stackMin = minValue ;
			next = nullptr ;
		}
		// Destructor
		~NodeMin (){
			cout << "Destructor() NodeMin called" << endl ;
		}

		T getData(){
			return data ;
		}
		T getMin(){
			return stackMin ;
		}
		NodeMin<T> * getNext(){
			return next ;
		}
		void setNext(NodeMin<T> * n){
			next = n ;
		}
};

template <class T> class StackMin {
	
	private : 
		NodeMin<T> * top ;
	public : 
		//constructor
		StackMin(T d){
			cout << "StackMin constructor called" << endl ;
			// for the first node of the stack, minimum is the item itself.
			top = new NodeMin<T>(d,d) ;
		}

		// destructor 
		~StackMin(){
			cout << "destructor() StackMin called"<< endl ;
			// need to pop all the nodes ....
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
				NodeMin<T> * n(top) ;
				top = top->getNext() ;
				delete n ;
				n = nullptr ;
				return item ;
			}
		}

		void push(T item){
			// need first to collect minimum of current stack. (top->stackMin)
			// Then compare to item and decide about new minimum.
			T minimum = item < top->getMin() ? item : top->getMin() ;
			NodeMin<T> * n = new NodeMin<T>(item,minimum) ;
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

		// add function min()
		T min(){
			if( isEmpty()){
				cout << "Impossible to calculate Minimum : Stack is empty !!!" ;
			}
			else{
				// return Min value of top Node ...
				return top->getMin() ;	
			}
			
		}

		void printStack(){
			if(isEmpty()){
				cout << "Stack is empty" << endl ;
				return ;
			}
			NodeMin<T> * p(top) ;
			while(p!=nullptr){
				cout << "; " << p->getData() << " (min : " << p->getMin() << ") " ;
				p = p->getNext() ;
			}
			cout << endl ;

		}

};

/* still needed to be done : 
study how to prevent issues when top = nullptr in methods. --> done.
study the pointers/delete needs. --> done.
study the destructors needs. --> done.
Study the core dump at the end. --> done.
 
Test back the basic stack : compile + execute + test.
Do same with the queue.

*/

int main(){

	StackMin<int> * numbers = new StackMin<int>(0) ;
	numbers->printStack() ;

	cout << "push()" << endl ;
	numbers->push(10);
	numbers->printStack() ;
	cout << "minStack is : " << numbers->min() << endl ;

	cout << "push()" << endl ;
	numbers->push(5);
	numbers->printStack() ;
	cout << "minStack is : " << numbers->min() << endl ;

	cout << "push()" << endl ;
	numbers->push(15);
	numbers->printStack() ;
	cout << "minStack is : " << numbers->min() << endl ;

	cout << "push()" << endl ;
	numbers->push(1);
	numbers->printStack() ;
	cout << "minStack is : " << numbers->min() << endl ;

	cout << "push()" << endl ;
	numbers->push(-1);
	numbers->printStack() ;
	cout << "minStack is : " << numbers->min() << endl ;
	
	cout << "pop()" << endl ;
	numbers->pop();
	numbers->printStack() ;
	cout << "minStack is : " << numbers->min() << endl ;

	cout << "pop()" << endl ;
	numbers->pop();
	numbers->printStack() ;
	cout << "minStack is : " << numbers->min() << endl ;

	cout << "pop()" << endl ;
	numbers->pop();
	numbers->printStack() ;
	cout << "minStack is : " << numbers->min() << endl ;

	cout << "pop()" << endl ;
	numbers->pop();
	numbers->printStack() ;
	cout << "minStack is : " << numbers->min() << endl ;

	cout << "pop()" << endl ;
	numbers->pop();
	numbers->printStack() ;
	cout << "minStack is : " << numbers->min() << endl ;

	cout << "pop()" << endl ;
	numbers->pop();
	numbers->printStack() ;
	cout << "minStack is : " << numbers->min() << endl ;

	cout << "pop()" << endl ;
	numbers->pop();
	numbers->printStack() ;
	cout << "minStack is : " << numbers->min() << endl ;

	cout << "pop()" << endl ;
	numbers->pop();
	numbers->printStack() ;
	cout << "minStack is : " << numbers->min() << endl ;
	
	delete numbers ;
	numbers = nullptr ;

	return 0;
}
/* g++ sortFile.cpp -o sortFile

*/