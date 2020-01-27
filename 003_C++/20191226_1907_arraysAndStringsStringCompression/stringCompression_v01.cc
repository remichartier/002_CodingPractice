/* Description : 
Implement a method to perform basic string compression using the counts of repeated characters.
ex : aabcccccaaa woudl become a2b1c5a3
if compressed stream not smaller than original string, method should return the original string.
Assume string has only uppercase and lowercase characters.
*/
#include <string>
#include <iostream>
using namespace std;

void compress(string input, string& out){
	int i(0);
	while(i < input.size()){
		int n(1);
		out += input.at(i);
		cout << "\n" << "sortie fonction " << input << " " << out << "\n" ;
		i++;
		//cout << "character " << in[i] << "\n" ;
		while((i<input.size()) && (input.at(i) == input.at(i-1)) ) {
			//cout << "\n" << "sortie fonction " << input << " " << out << "\n" ;
			n++;
			i++;
		}
		string buffer;
		buffer=to_string(n);
		out += buffer;
	}
	//cout << "\n" << "sortie fonction " << input << " " << out << "\n" ;
}


int main(){
	string  s = "aabcccccaaa";
	string sCompressed;
	
	//cout << s << " = " << sCompressed << "\n";
	
	compress(s,sCompressed);
	cout << s << " = " << sCompressed;
	return 1;
}
/* g++ sortFile.cpp -o sortFile

*/