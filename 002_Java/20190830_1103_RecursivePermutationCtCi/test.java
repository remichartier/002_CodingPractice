
class PermutationTest {

	public static void permutation(String str) {
		permutation(str,"");
	}


	public static void permutation(String str, String prefix) {
		System.out.println("Call to permutation(" + str + "," + prefix + ")") ;
		if (str.length() == 0) {
			System.out.println("length = 0 -->" + prefix) ;
		}
		else {
			for(int i=0; i < str.length(); i++) {
				String rem = str.substring(0,i) + str.substring(i+1);
				System.out.println("i = " + i + "; rem = str.substring(0,i) + str.substring(i+1); --> " + rem) ;
				System.out.println("call to rem permutation(rem,prefix + str.charAt(i)); -->permutation("+ rem + "," + prefix + str.charAt(i) + ")") ;
				permutation(rem,prefix + str.charAt(i));
			}
		}
	}

	public static void main (String[] args)
    {
        String str="two";
		permutation(str,"");

    }
}

/*
javac test.java 
java PermutationTest.class


*/






