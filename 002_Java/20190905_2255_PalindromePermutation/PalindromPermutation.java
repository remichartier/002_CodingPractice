/* Description : given a string, write a function to check if it is a permutation of a palindrome
A palindrome is a word or phrase that is the same forwards and backwards
A permutation is a rearangment of letters.
ex :
"tact coa" False
true : "taco cat", "atco cta", etc ...
hints : you should not generate all permutations.
hints : what does it mean palindrome.
hints : have you tried hash table ? you should be able to get this down in O(n)
hints : can you reduce the space usage by using a bit vector ?
*/

// given a string, may need to remove the spaces.
// should be case insensitive.
// if not counting the spaces, chars should be multiple of 2, except 1 char if size (string - spaces) is odd.
// if size string-spaces is even --> all chars shoudl be multipe of 2.
// Palindrome : order of first letters should be same as last letters going backword. except for the spaces. But this should be the only requirement ...
//--> remove spaces.
//--> check order forward and backword. if even size, increment/decrement should meet in middle which is not a position. If odd size, should meet in middle which is a position.

public class PalindromPermutation {

	// problem of this implementation : String can not use [] ... So should have been better to use char[] in Java.
	// also hints suggest to use hash table and even to optimize with bit vector ....
	// also, prb here is question is asking if it is a palindrom permutation, not asking if the string is a palindrom only.... so 
	// the forward/backward test is out of subject ..

	// --> need to redo the function to check if it is a palindrom word ...

	// another exercise would be to use bitvectors :
	static public boolean checkPalindrome3BitVectors(char[] s){
		// a to z --> 26 chars. An int of 32 bits would be enoughth
		int bitvector = 0 ;
		// idea is to flip the bit of letter whenever met.
		// not counting the spaces, if even size --> bitVector should end up as 0.
		// if odd sizre --> bit Vector should have only 1 bit set. exemple of 00010000. 00010000 -1 = 00001111, AND 00010000 = 0 property
		boolean evenSize = false;
		int noSizeSpace = 0;
		int nbOnes=0;

		// count size without spaces and fill bitvector
		for (int i=0;i<s.length;i++){
			if (s[i] != ' '){
				noSizeSpace++;
				// how to flip bit vector ?
				// calculate position
				int pos = (int)s[i] -(int)'a';
				bitvector = flipBit(bitvector,pos); 
			}
		}

		// according to bitvector, decide if Palindrom string or not.
		if (noSizeSpace%2 == 0) evenSize=true;

		//now need to check if bitvector is full of 0 or if there are 1s, and if 1s, only one or serverals, + evenSize.

		if(evenSize){
			if(bitvector==0) return(true);
			else return(false);
		}
		else{
			// need to check that there is only an one bit to one, otherwise it is not a Palindrome permutation
			if (bitvector ==0) return(false);
			else{
				for(int i=0;i<32;i++){
					if((bitvector&(1<<i)) ==1) {
						nbOnes++;
						if (nbOnes>1) return(false);
					} 
				}
			}
		}

		return(true);
	}

	static public int flipBit(int vect, int pos){
		// if 0 set 1
		// if 1 set 0
		// at the right position ...
		int ret ;
		int bit;
		int mask = 1<<pos ;
		bit = mask & vect;
		if (bit==0){
			ret = mask | vect ;
		}
		else{
			ret = ~mask & vect ;
		}
		return(ret);
	}

	static public boolean checkPalindrome2(char[] s){

		// if not counting the spaces, even size --> all chars # should be factors of 2.
		// we assume all chars are same case.
		// if not counting the spaces, even size --> all chars # should be factors of 2, only one should be 1 count.

		int MAX = 256;
		int size = s.length;
		int nbSpaces = 0;
		boolean even = false;
		int[] hash = new int[MAX]; // all initialized to 0 by default.
		int oddCount = 0;

		//count nb of spaces in s :
		//+ fill the hash table
		for(char c:s){
			if(c ==' ') nbSpaces++;
			else {
				//System.out.println("index of character : " + (int)c);
				hash[(int)c] += 1;
			}
		}
		even = ((size - nbSpaces)%2 == 0);
		//if(even) System.out.println("Even size");
		//else System.out.println("Odd size");

		// --> if even, no unique character, and all other characters are multiples of 2.
		// --> if not even, 1 unique character, and all other characters are multiples of 2.
		// we can define a hash table, index is the char value, value is the count of chars.

		// now can check if hash count are multiple of 2s or odd numbers and how many ones ...
		for(int i=0;i<MAX;i++){
			//System.out.println("study character value : " + hash[i]);
			if (hash[i]%2 == 1) {
				if(even) {
					//System.out.println();
					//System.out.println("return false because even size but some chars numbers are not multiple of 2");
					return(false);
				}
				else{
					oddCount++;
					if (oddCount>1) {
						//System.out.println();
						//System.out.println("return false because odd size and more than one char is counted in even number");
						return(false);
					}
				}
			}
		}
		return(true);
	}

// not done yet : we should make sure chars are between a and z...

	static public boolean checkPalindrom(String s){
		int size = s.length();
		int forward = 0;
		int backward = size -1;

		if (size==0) return(false);

		while(forward <= backward){
			while (s.charAt(forward) == ' ') {
				forward++;
			}
			while (s.charAt(backward) == ' ') {
				backward--;
			}
			if (s.charAt(forward) != s.charAt(backward)) {return(false);}
			forward++;
			backward--;
		}

		return(true);
	}

	static public void testPalindrom(String s){
		System.out.print(s + " is");
		if (!checkPalindrom(s)) System.out.print(" not");
		System.out.println(" a Palindrome Permutation string.");
	}

	static public void testPalindrom2(char[] s){
		String str = new String(s);
		System.out.print(str + " is");
		if (!checkPalindrome2(s)) System.out.print(" not");
		System.out.println(" a Palindrome Permutation string.");
	}

	static public void testPalindrom3(char[] s){
		String str = new String(s);
		System.out.print(str + " is");
		if (!checkPalindrome3BitVectors(s)) System.out.print(" not");
		System.out.println(" a Palindrome Permutation string.");
	}

	public static void main(String[] args){
		String a = "tact coa" ;
		String b = "taco cat" ;
		String c = "atco cta" ;
		String g = "atcod cta" ;

		char[] d = a.toCharArray() ;
		char[] e = b.toCharArray() ;
		char[] f = c.toCharArray() ;
		char[] h = g.toCharArray() ;

		//testPalindrom(a);
		//testPalindrom(b);
		//testPalindrom(c);
		testPalindrom2(d);
		testPalindrom2(e);
		testPalindrom2(f);
		testPalindrom2(h);
		testPalindrom3(d);
		testPalindrom3(e);
		testPalindrom3(f);
		testPalindrom3(h);

// note : 2 or 3 may not be working, but spent to much times on them, switching to another exercise.
	}
}


/* javac PalindromPermutation.java
	java PalindromPermutation

*/