/* Description :
Describe how you could use a single array to implement 3 stacks.

Hints : #2, 12, 38, 58
12 : we could simulate 3 stacks by dividing array by 3. One might actually be much bigger than the others, through. Can we be more lexible with the divisions ?

38 : if you want to allow or flexible divisions, you can shift stacks around. Can you ensure that all available capacity is used ?

58
Try thinking about the array as circular, such that the end of the array "wraps around"to the start 
of the array

Approach 1 : fixed division
Approach 2 : flexible divisions
*/

/* reflexion algorithm

	Stack is LIFO LastInFirstOut.
	Maintain 3 parts of an array keeping track of the borders of the stacks ie the bottoms of the stacks.

	+ the 3 tops of the stacks.

	3 main functions for stacks : 
	isEmpty;
	push(item);
	item=pop();
	peek()

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