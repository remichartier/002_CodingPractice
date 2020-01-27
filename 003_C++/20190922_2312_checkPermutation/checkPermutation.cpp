/*
Given 2 strings, write a method to decide if one is a permutation of the other 
*/

/* brainstorm : permutation of the other --> have same length. Have same number of characters. Should we count the spaces ?

Another solution from book to investigate : use a sorting function.
int hashTable[MAX] = {i}; ---> would initialize first element to i and rest to 0
int hashTable[MAX] = {i}; ---> would initialize first element to 0 and rest to 0

*/

#include <string>
#include <iostream>
#include <array>
#include <algorithm>    // std::sort
#include <vector>
using namespace std; 

#define MAX 255

bool isPermutation(string s1, string s2){
	int hashTable[MAX];
	if (s1.size() != s2.size()){ 
		cout << "sizes differ" << "\n";
		return false;
	}
	/* if use order function --> nlog(n) or worst case n2 --> better use O(n)*/
	/*Could use simple hash table using ascii char table, limited 255 chars
	hypothesis all are lower case
	*/
	for(int i=0;i<MAX;++i) {hashTable[i]=0;}
	// fill hashTable with content s1
	for(int i=0;i<s1.size();++i) {
		int c= s1[i];
		hashTable[c]+=1;
	}
	// decrease by chars found in s2
	for(int i=0;i<s2.size();++i) {
		int c= s2[i];
		hashTable[c]-=1;
		if (hashTable[c]<0) {
			cout << "problem on char : " << s2[i] << "\n" ;
			return(false);
		}
	}
	return(true);

}
bool myFunction(char c1,char c2){
	return(c1<c2);
}

bool isPermutationSort(string s1, string s2){
	//vector<char> v1(s1.begin(),s1.end());
	//vector<char> v2(s2.begin(),s2.end());
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	return(s1==s2);
}

void compareStrings(string a,string b){
	if(isPermutation(a,b)){
		cout << b << " is permutation of " << a << "\n" ; 
	}
	else{
		cout << b << " is NOT a permutation of " << a << "\n" ; 
	}	
}

void compareStringsSort(string a,string b){
	if(isPermutationSort(a,b)){
		cout << b << " is permutation of " << a << "\n" ; 
	}
	else{
		cout << b << " is NOT a permutation of " << a << "\n" ; 
	}	
}

void compareStringsFunctionPointer(string a,string b,bool (*fp)(string,string)){
	if(fp(a,b)){
		cout << b << " is permutation of " << a << "\n" ; 
	}
	else{
		cout << b << " is NOT a permutation of " << a << "\n" ; 
	}	
}

int main(){

	string a = "implement";
	string b = "tnemelpmi";
	string c = "slip";
	string d = "tneme0pmi";

	compareStrings(a,b);
	compareStrings(a,c);
	compareStrings(a,d);

	cout << "=================" << "\n";
	cout << "COMPARE WITH SORT" << "\n";
	cout << "=================" << "\n";

	compareStringsSort(a,b);
	compareStringsSort(a,c);
	compareStringsSort(a,d);
	
	cout << "=================" << "\n";
	cout << "COMPARE WITH FUNCTION POINT CALL" << "\n";
	cout << "=================" << "\n";

	compareStringsFunctionPointer(a,b,&isPermutation);
	compareStringsFunctionPointer(a,b,&isPermutationSort);
	compareStringsFunctionPointer(a,c,&isPermutation);
	compareStringsFunctionPointer(a,c,&isPermutationSort);
	compareStringsFunctionPointer(a,d,&isPermutation);
	compareStringsFunctionPointer(a,d,&isPermutationSort);

	return(1);

}


/* g++ sortFile.cpp -o sortFile

*/