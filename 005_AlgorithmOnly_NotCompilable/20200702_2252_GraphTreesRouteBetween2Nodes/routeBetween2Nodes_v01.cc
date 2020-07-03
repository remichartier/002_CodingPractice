/* route between 2 nodes

Given a directed graph, design an algorithm to find out whether there is a route between 2 nodes

Hints : #127 

Directed --> can not find via bidirectional search.
Need to use a BFS Breadth First Algorithm, will be the fastest.
*/

// Note : exercise just for Algorithm, not for C++ coding accuracy
// Not compiling.


//#include <iostream>
//#include <vector>
//#include <stdlib.h>     /* srand, rand */
//#include <utility> 		/* swap */

using namespace std;

template <class T> class Node {
		T data;
		vector<Node<T>> neighboor;
};


template <class T> class Graph {
	
		vector<Node<T>>  nodes ;
};

boolean areNodesConnected(Node nodeA, Node nodeB){
	Queue queue = new Queue();
	if((nodeA == Null) || (nodeB == Null)){
		raiseException();
	}

	queue.enqueue(nodeA);
	nodeA.visited = true;


	while(!queue.isEmpty()){
		Node r = queue.dequeue();

		if (r == nodeB){
			return(true);
		}
		for (n in neighboor) {
			if( n = nodeB){
				return(true);
			}
			if (n.visited == false) {
				n.visited = true;
				queue.enqueue(n); 
			}
		}
	}

	// end of Algorithm
	// nodeB not found in graph ==> return(false)
	return(false);
}




int main(){

	//Stack<int> * s = new Stack<int>(0) ;
	//s->~Stack() ;
	return 0;
}
/* g++ sortFile.cpp -o sortFile

*/
