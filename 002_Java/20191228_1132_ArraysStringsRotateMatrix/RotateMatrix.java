import java.util.*;

/* Description : 
Given an image represented by NxN matrix, where each pixel in the image is 4 bytes, 
Write a method to rotate the image by 90 degrees.
Can you do this in place ?
*/

/*
- store top layer except last element.
- left layer to top
- bottom layer to left
- right layer to bottom
- store to right layer
- Then do to sub layers.

how many layers ?
2x2 --> 1 layer. length = 4 1/2 length = 2
3x3 --> 1 layer. l 9, l/2 = 4
4x4 --> 2 layers. l = 16, l/2 = 
5x5 --> 2 layers.
6x6 --> 3 layers. 
nb layers = n/2 ....

*/

// NOT FINISHED, JUST FOR STUDY ....
// quite difficult for me to understand process + offset concept.

public class RotateMatrix{

	void rotate(int matrix[][]){

		int n = matrix.length ;
		for(int layer=0;layer<n/2;layer++){  // for each layer
			int first = layer ; // first element = layer number.
			int last = n - 1 - layer; // last element = n -1 - layer number
			for (int i=first; i < last;i++){
				int offset = i - first ;
				int top = matrix[first][i];
				// move left to top
				matrix[first][i] = matrix[last-i][first];
				// move bottom to left
				matrix[last-i][first] = matrix[last][last-i]; // here instead of last-i --> last - offset

				// move right to bottom
				matrix[last][last-i] = matrix[i][last];
				// move top to right
				matrix[i][last]; = top; 
			} // for element of layer

		} //for layer loop


	}

	public static void main(String[] args){
		int[][] matrix = new int[4][3];
		int n = matrix.length;
		System.out.println(n);
	}

}


/* javac ....java
	java ...

*/