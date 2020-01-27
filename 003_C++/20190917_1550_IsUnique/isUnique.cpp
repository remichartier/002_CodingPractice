/*
Algo to implement if a string has all unique characters. What if you can not use additional data structures ?
*/
#include <iostream>
#include <string>
using namespace std;

#define MAX 255
/* no hash table in c++, we'll say all characters can be contained into int.*/
bool isUnique(char* s){
	bool used[MAX];

	// init array used[]
	for(int i=0;i<MAX;i++){
		used[i]=false;
	}

	if (s==NULL) return(false);

	int j(0);
	while (s[j]!='\0'){
		char c = s[j];
		if (used[c]) return (false);
		used[c] = true;
		++j;
	}

	return(true);
} 

int main(){

	char a[] = "uniqe";

	if(isUnique(a)){
		cout << a << " is unique" << "\n";
	}
	else{
		cout << a << " is NOT unique" << "\n";	
	}
}



/* g++ sortFile.cpp -o sortFile

*/