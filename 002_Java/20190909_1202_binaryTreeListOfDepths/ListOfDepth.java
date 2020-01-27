/* Description : 

Given a binary tree, design an algorithm which creates a linked list of all nodes at each depth(if you hava a tree of depth D, youĺl have D linked list)
Hints
#107 Try modifying the graph search algorithm to track the depth from the root.
#123 a hash table or array that maps from level number to nodes at that level might also be useful
#135 you should be able to come up with an algorithm involving both depth first search and breadth first search

1st method :

Create ArrayList or Hash table of LinkedList, for easyness, ArrayList
arr[0] contains LinkedList depth 0
arr[1] contains LinkedList depth 1

scroll the tree recursively and fill the arr[] + LinkeList accordingly.

First method : return ArrayList, input root binary tree. This method will call recursive function on the root, giving input node, arrayList, depth. 
arr = listOfDepth(node.left,arr,depth+1);
*/

public ArrayList listOfDepth(TreeNode root){
	if (root = Null){
		return Null;
	}
	ArrayList<LinkedList> arr = new ArrayList<LinkedList>();
	return listOfDepth(root,arr,0);
}

public ArrayList listOfDepth(TreeNode node, ArrayList arr, int depth){

	if (node == Null){
		return(arr);
	}
	if(arr.size<depth+1){
		arr.add(new LinckedList<TreeNode>(node));
		arr[depth].next=Null;
	}
	else{
		arr[depth].push_back(new TreeNode(node));
		arr[depth].getLastNode().next == Null;
	}
	arr = listOfDepth(node.left,arr,depth+1);
	arr = listOfDepth(node.right,arr,depth+1); 
	return arr ;
}

/* for breadth search algorithm, if know nodes on level i, so nodes level i+1 are childrends of level i nodes */

public ArrayList listOfDepth(TreeNode root){
	
	int depth = 0;

	if(root==Null){
		return(Null);
	}

	ArrayList<LinkedList> arr = new ArrayList<LinkedList>();
	LinkedList<TreeNode> l = new LinkedList<TreeNode>;
	arr.add(l);
	
	for (int d=0;d<=arr.size-1;d++){
		l = arr[d];
		while(l!= Null){
			if(l.node.left!=Null) && (l.node.right != Null){
				if (arr.size<=d){
					arr.add(new LinkedList<TreeNode>);
				}
				if(l.node.left!=Null){
					arr[d+1].add(l.node.left);
				}
				if(l.node.right!=Null){
					arr[d+1].add(l.node.right);
				}
				l = l.next;
			}
		}
	}

	return arr ;

}


/* javac ....java
	java ...

*/