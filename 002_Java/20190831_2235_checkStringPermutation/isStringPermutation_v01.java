

/*
Given 2 strings, write a method to decide if one is the permutation of the other

*/
import java.util.Arrays; 

class IsPermutation {

	static final int MAX = 256;

	static public boolean isPermute(String a, String b){
		int[] charTable = new int[MAX]; /* it will by default set all values to 0 */
		int sizeA = a.length();
		int sizeB = b.length();
		if((sizeA==0)||(sizeB==0)||(sizeA!=sizeB)||(a.equals(b))){
			return(false);
		}
		for(int i=0;i<sizeA;i++){
			charTable[(int)a.charAt(i)]++;
		}
		for(int i=0;i<sizeA;i++){
			if ((charTable[(int)b.charAt(i)]-=1)<0){
				return(false);
			}
		}

		return(true);
	}

	// using toCharArray()
	static public boolean isPermuteSorted(String a, String b){
		int sizeA = a.length();
		int sizeB = b.length();
		char[] a_array = a.toCharArray();
		char[] b_array = b.toCharArray();

		if((sizeA==0)||(sizeB==0)||(sizeA!=sizeB)||(a.equals(b))){
			return(false);
		}
		
		Arrays.sort(a_array);
		Arrays.sort(b_array);
		if(!a_array.equals(b_array)){return(false);}

		return(true);
	}

	static public void main(String[] args){
		String a = "implement";
		String b = "tnemelpmi";
		String c = "slip";
		String d = "tneme0pmi";

		System.out.print( a + " and " + a + " are");
		if (!isPermute(a,a)){
			System.out.print(" not");
		}
		System.out.println( " permuted");

		System.out.print( a + " and " + b + " are");
		if (!isPermute(a,b)){
			System.out.print(" not");
		}
		System.out.println( " permuted");

		System.out.print( a + " and " + c + " are");
		if (!isPermute(a,c)){
			System.out.print(" not");
		}
		System.out.println( " permuted");

		System.out.print( a + " and " + d + " are");
		if (!isPermute(a,d)){
			System.out.print(" not");
		}
		System.out.println( " permuted");

		///////////////////////////////////////////////////////////

		System.out.print( a + " and " + a + " are");
		if (!isPermuteSorted(a,a)){
			System.out.print(" not");
		}
		System.out.println( " permuted");

		System.out.print( a + " and " + b + " are");
		if (!isPermuteSorted(a,b)){
			System.out.print(" not");
		}
		System.out.println( " permuted");

		System.out.print( a + " and " + c + " are");
		if (!isPermuteSorted(a,c)){
			System.out.print(" not");
		}
		System.out.println( " permuted");

		System.out.print( a + " and " + d + " are");
		if (!isPermuteSorted(a,d)){
			System.out.print(" not");
		}
		System.out.println( " permuted");


	}
}


/*a = "implement"
b = "tnemelpmi"
c = "slip"
d = "tneme0pmi"

javac isTringPermutation_v01.java
java IsPermutation
*/


