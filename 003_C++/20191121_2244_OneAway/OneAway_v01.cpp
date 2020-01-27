/* Description : 
3 types on edits on a string : insert char, remove char, replace char.

Given 2 strings, write function to check if they are one edit (or zero edits) away.
ex : 
pale, ple -> true
pale, pbale --> true
pales, pale --> true
pale, bale --> true
pale, bake --> false


*/

#include <string>
#include <iostream>
using namespace std;

bool isOneAway(string s1,string s2){
	int i(0),j(0);
	int n(0);
	// 0 edits
	if (s1 == s2) {return(true);}
	//1 edit

	// if insert : 
	// (size + 1), then compare char by char, if one char different, pass to next one, if more char differnts --> return false.
	if (s1.size() == s2.size() -1){
		while((i<s1.size()) && (n<2)){
			if(s1[i]!=s2[j]){
				n++;
				j++;
			}
			else{ i++; j++;}
		}
		if(n==1){return true;}
		else { return false;}
	}


	// if remove :
	// (size - 1) 
	if (s1.size() == s2.size() +1){
		while((j<s2.size()) && (n<2)){
			if(s1[i]!=s2[j]){
				n++;
				i++;
			}
			else{ i++;j++;}
		}
		if(n<=1){return true;}
		else { return false;}
	}


	// if replace :
	// equal size 
	if (s1.size() == s2.size()){
		while((i<s1.size()) && (n<2)){
			if(s1[i]!=s2[i]){
				n++;
			}
			i++;
		}
		if(n==1){return true;}
		else { return false;}
	}

	// if not found, return false
	return false;
}

void printResult(string s1,string s2){
	if(isOneAway(s1,s2)){
		cout << s1 << ", " << s2 << " --> true\n" ;
	}
	else {
		cout << s1 << ", "<< s2 << " --> false\n" ;
	}
}

int main(){
	
	printResult("pale","ple");
	printResult("pale","pbale");
	printResult("pales","pale");
	printResult("pale","bale");
	printResult("pale","bake");

	return 0;
}
/* g++ sortFile.cpp -o sortFile

*/