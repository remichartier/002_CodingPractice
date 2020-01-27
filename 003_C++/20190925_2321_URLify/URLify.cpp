/* Description : Write method to replace all spaces in a string with '%20'. 
Assume the string as sufficient space at the end to hold the additionnal characters, and that you are given a "true" length of the string
If implementing in java, please use a character array so that you can perform this operation in place.

Example : 
input "Mr John Smith      " 
Output "MrJohn Smith      "
*/

#include <string>
#include <iostream>
using namespace std; 

void URLify(string& s,int trueLength){

	int size(s.length());
	int nbSpaces(0);
	int a(trueLength-1);
	//int a(s.length());
	int b;

	if(size + trueLength == 0) return;

	// compute number of relevant spaces.
	for(int i=0;i<trueLength;++i){
		if(s[i]==' ') nbSpaces+=1;
	}

	b = trueLength + (2*nbSpaces) -1; // position b at end of new string.

	while((b>0)&(a>0)){
		if (s[a] != ' '){
			s[b] = s[a];
		}
		else{
			s[b]='0'; b-=1;
			s[b]='2'; b-=1;
			s[b]='%';
		}
		a-=1;
		b-=1;
	}

}

int main(){
	string s="Mr John Smith    ";
	string s2="MrJohn Smith    ";

	cout << "original string :" << "**" << s << "**\n" ;
	URLify(s,13);
	cout << "modified string :" << "**" << s << "**\n" ;
	 
	cout << "original string :" << "**" << s2 << "**\n" ;
	URLify(s2,12);
	cout << "modified string :" << "**" << s2 << "**\n" ;


	return 1;
}


/* g++ sortFile.cpp -o sortFile

*/