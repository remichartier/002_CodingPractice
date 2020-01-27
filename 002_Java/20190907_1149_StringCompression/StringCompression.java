/* Description : 
Implement a method to perform basic string compression using the counts of repeated characters.
ex : aabcccccaaa woudl become a2b1c5a3
if compressed stream not smaller than original string, method should return the original string.
Assume string has only uppercase and lowercase characters.
*/

public class StringCompression{

	public static int countIdenticalChar(String s, int pos){
		int count = 1;
		char c = s.charAt(pos);
		int l = s.length();

		while ((pos + count <= l-1) && (s.charAt(pos+count) == c)){
			count++;
		}
		return(count);
	} 

	public static String compress(String s){
		String ret = "";
		int l = s.length();
		int i = 0;
		int cnt = 0 ;
		
		if (s.length() == 0) return(s);
		// read char + subsequent similar chars and add them to ret string.
		while(i<l-1){
			cnt = countIdenticalChar(s,i);
			ret = ret + (s.charAt(i)) + cnt ;
			i += cnt;
		}
		// return string is complete at end of the loop.
		// need to return the shortest string between s and ret
		if(ret.length() <= l) return(ret);
		else return(s);
	}

	public static String compress2(String s){
		//String ret = "";
		int l = s.length();
		int i = 0;
		int cnt = 0 ;
		StringBuilder ret = new StringBuilder();
		
		if (s.length() == 0) return(s);
		// read char + subsequent similar chars and add them to ret string.
		while(i<l-1){
			cnt = countIdenticalChar(s,i);
			//ret = ret + (s.charAt(i)) + String.valueOf(cnt) ;
			ret.append(s.charAt(i));
			ret.append(cnt);
			i += cnt;
		}
		// return string is complete at end of the loop.
		// need to return the shortest string between s and ret
		if(ret.length() <= l) return(ret.toString());
		else return(s);

	}

	// solution with StringBuilder as suggested in the book :


	static public void main(String[] args){

		String a = "aabcccccaaa";
		String result = "";

		result = compress(a);
		System.out.println("String : " + a + " is compressed in : " + result);
		result = compress2(a);
		System.out.println("String : " + a + " is compressed in : " + result);

	}
}


/* javac StringCompression.java
	java StringCompression

*/