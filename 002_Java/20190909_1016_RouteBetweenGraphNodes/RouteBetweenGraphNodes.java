/* Description : given a directed graph, design an algorithm to find out wheter there is a route between two nodes

Hints #127
*/
enum State {Unvisited,Visiting,Visited};

public class Node{
	private String name;
	private Node[] adj;
	private status;
}

public boolean findRoute(Graph g, Node src, Node dest){

	if ((g==Null) || (src == Null) or (dest == Null)){
		return;
	}
	// operates as a queue for Breadth first search
	LinkedList<Node> q = new LinkedList<Node>();

	for each (Node u:g.getNodes()){
		u.status = Unvisited;
	}

	
	src.status = Visiting;
	q.add(src);

	Node u;
	while(!q.isEmpty()){
		u = q.removeFirst();
		if(u!=Null){
			for(Node v: u.getAdjacent[]){
				if(u.status == Unvisited){
					if(v = src){
						return(true);
					}
					v.status = visiting;
					q.add(v);
				}
			}
		}
		u.state = visited;
	}

	return false;

}




/* javac ....java
	java ...

*/