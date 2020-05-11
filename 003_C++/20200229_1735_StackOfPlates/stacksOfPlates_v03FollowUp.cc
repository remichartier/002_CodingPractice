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
				cout << "Can not pop() : Stack is empty !!! " << endl ;
			}
			else {
				T item = top->getData() ;
				Node<T> * n = top ;
				top = top->getNext() ;
				delete n ;
				n = nullptr ;
				--size;
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
				cout << "Can not peek() : Stack is empty !!!" << endl ; 
			}
			else{
				return top->getData() ;	
			}			
		}

		T pullBottom(){
			// need to start from top, search node such as node-->next = ptr_null
			// and remember previous node.
			// save data T.
			// remove this node
			//return T
			T data ;
			Node<T> * p1(top) ;
			Node<T> * p2(top->getNext()) ;
			if(p2 != nullptr){

				while( p2->getNext() != nullptr){
					p1 = p2;
					p2 = p2->getNext() ;
				}
				// when goes out, bottom is p2, previous is p1
				// memorize Data
				data = p2->getData() ;
				
				// free bottom --> call destructor.
				delete p2 ;
				p1->setNext(nullptr);
				return data;
				
			}
			
			else { // case p2 == nullptr ie only 1 node
				data = pop();
				return data ;
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

FOLLOW UP : 
Implement a function popAt(int index) which performs a pop operation on a 
specific sub-stack.

	--> This would mean that a stack size could be less than the maximum 
	Capacity.
	But it is ok because stacks keep track of their sizes

	So it just have to test if index is within the number of stacks we have, 
	and then pops from the stack.

	However, if a particular stack becomes empty, we would need to remove it 
	from the vector array. and --nbStack... 

	// erase the 6th element
  	myvector.erase (myvector.begin()+5);


*/

/* Implementation about trickier solution suggested by book : 

	"Rollover" system. I pop element froms tack1, we need to 
	remove bottom element of stack2 and push it ont stack1, 
	and then need t orollover from stack 3 to stack2, stack 4 to 3, etc ...
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
			// problem with following code, need to check why .. : 

			//Had problem due to getSize() using "-- size" instead of "--size"
			// but now working ok.
			while (nbStack > 0){
				pop() ;
			}

			//In the meantime, replacing by following code
			/*for ( int i =nbStack-1;i>=0;--i){
				removeStackFromList(i);
			}*/
			
		}

		// Methods
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
			// alternative : if (currentStack->isEmpty()){
				listOfStacks.pop_back() ;
				--nbStack ;
				// free currentStack...
				currentStack->~Stack();
			}
			//return data popped
			return data ;
		}


		void removeStackFromList(int index){
			if(index >= nbStack) {return;}
			if(!listOfStacks[index]->isEmpty()) {return;}
			// free/delete stack.
			cout << "stack empty --> deleting stack removing stack from listOfStacks" << endl ;
			listOfStacks[index]->~Stack() ;
			listOfStacks.erase(listOfStacks.begin()+index) ;
			--nbStack ;
		}

		T popAt(int index){
			if((index < 0) || (index > nbStack)){
				cout << "impossible to popAt(" << index << ") -- returning -1" << endl ;
				return -1;
			}

			T data = listOfStacks[index]->pop();

			cout << "popAt(" << index << ") == " << data << endl ;

			if (listOfStacks[index]->getSize() == 0){
				removeStackFromList(index) ;
			}
			else { // implementation "rollover" solution
				// if not the last stack ...(index)
				// data = pullBottom stack @ (index +1) 
				// if next stack become empty --> remove it from array.
				// and then listOfStacks[index]->push(data)

				// then should do that for next stack until stack does not have 
				// any next stack.

				// Note : T popHead(index) removes Head(ie bottom) of stack
				// Current stack object only know top of stacks.
				// --> we need another field to access the bottom of the stack.
				// but it would be too difficult to remove a bottom as we 
				// do not have next/previous nodes.
				// so anytime we need to search bottom node, we'll have to search for it ...
				// Implementation -->

				// if/while not the last stack ...(index)
				int i = index ;
				while( i < nbStack -1){
					// data = pullBottom stack @ (index +1)
					T bottomData = listOfStacks[i +1]->pullBottom() ;
					cout << "pullBottom() from next stack : " << bottomData << endl ;
					
					
					// if next stack becomes empty --> remove it from array.
					if (listOfStacks[i + 1]->isEmpty()){
						// free/delete stack.
						removeStackFromList(i+1) ;
					}
					// and then listOfStacks[index]->push(data)
					listOfStacks[i]->push(bottomData) ;

					++i;
					cout << "loop" << endl;	
				}
				
			}
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
	
	s->popAt(0);
	s->print() ;

	s->popAt(0);
	s->print() ;

	s->popAt(0);
	s->print() ;

	s->popAt(0);
	s->print() ;

	s->popAt(0);
	s->print() ;
	

	s->~SetOfStacks() ;
	s->print() ;
	

	


	return 0;
}
/* g++ sortFile.cpp -o sortFile

*/
