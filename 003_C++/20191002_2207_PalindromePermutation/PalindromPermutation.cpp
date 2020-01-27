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

/* Analysis :
- make asumption we do not care about spaces.
- Asumption all minor cases.
- having to iterators, one starting at index 0, the other at index string.length() -1, disregarding the spaces, letters should be identical
until the pointers meet together at the middle of the string ...
*/
#include <string>
#include <iostream>
using namespace std;

#define MAX 255;

bool checkStringPalindromPermutation(string a){
	int i(0),j(a.length() -1);

	if(a.length() == 0) return false;

	while(i<=j){
		while(a[i]==' '){++i;}
		while(a[j]==' '){--j;}
		// at this stage, a[i] and a[j] should contain real characters and not spaces
		// --> so we can compare
		if (a[i]==a[j]){
			++i;
			--j;
		}
		else {return false;}
	}printResult(a);
	
	return true;
}

/*  note : first implementation wrong because permutation is unordered !!!
 --> need to write down another function to take into account the permutation issue...

Permutation of palindrome would mean :
- All chars are in double quantities ie number is a factor of 2, may be except 1 char ie number is unven.
- so algo is to scroll the string, note down the characters in an hash table use alternative 0/1 when finding those characters. 
- Suppose only ascii characters.
- At the end, all should be at 0 except 1 at 1 ...

*/


bool checkStringPalindromPermutation2(string a){
	int hash[MAX];
	if (a.length() == 0){return false;}

	for(int i=0;i<MAX;++i){
		hash[i]=0;
	}

	// to complete






}


void printResult(string a){

	cout << a << " is" ;
	if(!checkStringPalindromPermutation(a)){
		cout << " not";
	}
	cout << " a palindrome permutation." << "\n";
}


int main(){
	string a = "tact coa";
	string b = "taco cat";
	string c = "atco cta";

	printResult(a);
	printResult(b);
	printResult(c);
	
	return 1;
}
/* g++ sortFile.cpp -o sortFile

*/