/* Description : 

3 types on edits on a string : insert char, remove char, replace char.

Given 2 strings, write function to check if they are one edit (or zero edits) away.
ex : 
pale, ple -> true
pale, pbale --> true
pales, pale --> true
pale, bale --> true
pale, bake --> false

Analysis :
- scrolll the characters.
- if 2 chars are different, need to find out if it is a insertion, a removal, or a replacement
- insertion : &a[i],&b[i+1] strings are equal.
- removal : &a[i+1],&b[i] strings are equal.
- replacement : &a[i+1],&b[i+1] strings are equal ...

*/

import  java.lang.Math;

public class OneAway {

	public static boolean isOneAway(String s1, String s2){
		int l1 = s1.length();
		int l2 = s2.length();
		System.out.println("For the 2 following strings : " + s1 + " --> " + s2);
		if(s1.equals(s2)) {System.out.println("2 strings are identical");return(true);}
		if((l1 == 0) || (l2 == 0)) {System.out.println("one of the strings is empty, length=0");return(false);}
		// if size differences > 1 --> false
		if (Math.abs(l1 - l2) >1) {System.out.println("2 strings sizes differs more than 1 character");return(false);}

		// to simplify, I will convert the strings into char arrays. But no, will not simplyfy at all --> cancelling.
		//char[] a = s1.toCharArray();
		//char[] b = s2.toCharArray();

		// char by char, if different, we analyse if it is just an insert, a remove, or a replacement.
		//to not forget, if size different, we'll have index issues ...
		for(int i=0;(i<l1)&&(i<l2);i++){
			if(s1.charAt(i)!=s2.charAt(i)){
				// check if it is just a matter of an insertion
				String temp1 = s1.substring(i,l1-1);
				if (temp1.equals(s2.substring(i+1,l2-1))){
					System.out.println("This is only a character insertion. Character inserted: " + s2.charAt(i));
					return(true);					
				}
				// check if it a matter of character removal
				temp1 = s1.substring(i+1,l1-1);
				if (temp1.equals(s2.substring(i,l2-1))){
					System.out.println("This is only a character removal. Character removed : " + s1.charAt(i));
					return(true);					
				}
				// check if it is a matter of 1 character replaced
				temp1 = s1.substring(i+1,l1-1);
				if (temp1.equals(s2.substring(i+1,l2-1))){
					System.out.println("This is only a character replaced. Character : " + s1.charAt(i) + " replaced by character : " + s2.charAt(i));
					return(true);					
				}
				// if not of those cases --> need to return false
				System.out.println("This is not a One Away difference");
				return(false);
			}
		}

		return(true);
	}

	public static void main(String[] args){

		isOneAway("pale", "ple") ;
		isOneAway("pale", "pbale") ;
		isOneAway("pales", "pale") ;
		isOneAway("pale", "bale") ;
		isOneAway("pale", "bake") ;


	}
}

/* javac OneAway.java
	java OneAway

*/