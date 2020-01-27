/* Description : Write method to replace all spaces in a string with '%20'. 
Assume the string as sufficient space at the end to hold the additionnal characters, and that you are given a "true" length of the string
If implementing in java, please use a character array so that you can perform this operation in place.

Example : 
input "Mr John Smith      " 13
Output "MrJohn Smith      "
*/

public class URLify{

	public static void printCharArray(char[] c, String name){
		String s = new String(c);
		System.out.println(name + " : " + s);

	}
	public static void convert(char[] src, int trueSize, int realSize){
		//s.replace(" ","%20");
		// scroll char array. Anytime finds a space, need to move rest of the string of 2 characters to be able to include the %20.
		// This is too complicated.
		// define another array to keep the original src as a reference.
		char[] oriSrc = new char[realSize];

		// cp content src[] into oriSrc[]
		for (int i=0;i<realSize;i++){
			oriSrc[i] = src[i];
		}
		//printCharArray(oriSrc, "oriSrc");
		//printCharArray(src, "src");

		int j=0;
		// now scroll oriSrc and insert %20 for any space met or insert current src char
		for(int i=0;i<trueSize;i++){
			if (oriSrc[i] != ' ') {
				src[j] = oriSrc[i];
				j++;
			}
			else {
				// write % in current position on src[] and '20' in next 2 positions.
				src[j] = '%';
				j++;
				src[j] = '2';
				j++;
				src[j] = '0';
				j++;
			}
			//printCharArray(src, "src");
		}

		// when over, src contains all spaces replaced by %20.

	}

	public static void convert2(char[] s, int trueSize, int realSize) {
		int nbSpaces = 0;
		int size = 0;
		// count number of spaces in s
		for(int i=0;i<trueSize;i++) {
			if(s[i] == ' ') nbSpaces++ ;
		}
		// Given the number of spaces --> we can calculate how many chars to add (+2 for each spaces) and therefore the size at the end of the process.
		size = trueSize + 2*nbSpaces ;
		// --> last index will be (size -1)
		int index = size -1 ;

		// so now can start by the end of the original string, index (truesize -1) copy to (size -1)
		for(int i=trueSize-1;i>=0;i--){
			if(s[i]!=' ') {
				s[index] = s[i];
				index--;
			}
			else {
				// if space, add a '0' to s[index]
				s[index] = '0';
				// and add 2 and then % to previous characters.
				index--;
				s[index] = '2';
				index--;
				s[index] = '%';
				index--;
			}
		}
	}

	public static void main(String[] args){
		// please use a character array so that you can perform this operation in place
		String s = "Mr John Smith      ";
		int true_s = 13;
		char[] a = s.toCharArray();
		System.out.println("realsize : " + s.length());
		convert(a,true_s,s.length());
		String newString = new String(a);
		System.out.println(newString);

		a = s.toCharArray();
		convert2(a,true_s,s.length());
		printCharArray(a, "result convert2()");
		// with books hints : always better to modify a string to start by the end.
		// you may have to count the number of spaces ...
	}

}

/* javac URLify.java
	java URLify

*/