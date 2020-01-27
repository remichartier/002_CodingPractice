/* Description : given a sorted (increasing order) array with unique integer elements, 
write an algorithm to create a binary search tree with minimal height

Hints #19, #73, #116

minimal tree --> match number all nodes on left subtree compared to right subtree --> middle of array should be on top of the tree --> root.
 --> would mean half of the elements would be less than the root and half would be greater than it. 

--> proceed to build the tree in this fashion --> middle of each subsection of the array becomes the root of the node. left half of the array become left subtree, 
right half of the array becomes the right subtree.

Recurse createMinimalBST method. Entry parameters : subsection of the array and returns the root of a minimal tree for that array.

Algorithm : 

1. insert into the tree the middle element of the array.

2. Insert(into the left subtree) the left subarray elements.

3. Insert(into the right subtree) the right subarray elements.

4. Recurse

*/

TreeNode createMinimalBST(int array[]){
	return createMinimalBST(array,0, array.length -1);
}

TreeNode createMinimalBST(int arr[],int start,int end){
	if(end<start){
		return Null;
	}

	int mid = (start+end)/2;
	TreeNode n = new TreeNode(arr[mid]);
	n.left = createMinimalBST(arr,start, mid -1) ;
	n.right = createMinimalBST(arr, mid+1,end) ;
	return(n);

}




/* javac ....java
	java ...

*/