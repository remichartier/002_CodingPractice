import java.util.ArrayList;

/*
Algo to implement if a string has all unique characters. What if you can not use additional data structures ?
*/

class  IsUniqueString {

	static final int MAX = 256;

	public static boolean isUnique(String s){

		ArrayList<Character> hash = new ArrayList<Character>();

		int n = s.length();
		char c;
		if (n == 0){return(false);}
		if (n == 1){return(false);}

		hash.add(s.charAt(0)) ;

		for(int i=1;i<n;i++){
			c = s.charAt(i) ;
			if(hash.contains(c)){
				return(false);
			}
			else {
				hash.add(c);
			}
		}

		return(true);
	}

	public static boolean isUniqueCharVector(String s){

		boolean[] asciiTable = new boolean[MAX];
		/* we suppose only ASCII Chars --> Max = 128 */

		int n = s.length();

		int  c;
		if (n == 0){return(false);}
		if (n == 1){return(false);}

		asciiTable[(int)s.charAt(0)] = true ;

		for(int i=1;i<n;i++){
			c = (int)s.charAt(i) ;
			
			if(asciiTable[c]){
				return(false);
			}
			else {
				asciiTable[c] = true;
			}
			
		}
		
		return(true);
	}

	public static void main (String[] args){

		String a = "implement";

		System.out.print("the string " + a + " is ");
		if(isUnique(a) == false) {
			System.out.print(" not ");
		}
		System.out.println("unique");

		a = "sleep";

		System.out.print("the string " + a + " is ");
		if(isUnique(a) == false) {
			System.out.print(" not ");
		}
		System.out.println("unique");


		a = "slip";


		System.out.print("the string " + a + " is ");
		if(isUnique(a) == false) {
			System.out.print(" not ");
		}
		System.out.println("unique");



		a = "implement";

		System.out.print("the string " + a + " is ");
		if(isUniqueCharVector(a) == false) {
			System.out.print(" not ");
		}
		System.out.println("unique");

		a = "sleep";

		System.out.print("the string " + a + " is ");
		if(isUniqueCharVector(a) == false) {
			System.out.print(" not ");
		}
		System.out.println("unique");


		a = "slip";


		System.out.print("the string " + a + " is ");
		if(isUniqueCharVector(a) == false) {
			System.out.print(" not ");
		}
		System.out.println("unique");


	}
}


/*
a = "implement"
b = "sleep"
c = "slip"
*/

/*
javac isUniqueString_v01.java
java  IsUniqueString

*/


