#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <bits/stdc++.h> 

using namespace std;

void sortFile(string inputFile,string outputFile){

	//ifstream file(inputFile,ios::in);
	ifstream file(inputFile);
	// opens outpout file
	ofstream fout(outputFile);

	vector<string> lines ;

	while(file.peek() != EOF){
		string s;
		getline(file,s);
		lines.push_back(s);
	}
	file.close();

	// sort lines
	sort(lines.begin(),lines.end());

	for(auto l:lines){
		fout << l << "\n";
	}

	fout.close();
	lines.empty();

}

int main(){

	sortFile("a.txt","b.txt");
	//sortFile("c.txt","b.txt");

	return(0);
}

/* g++ sortFile.cpp -o sortFile

*/