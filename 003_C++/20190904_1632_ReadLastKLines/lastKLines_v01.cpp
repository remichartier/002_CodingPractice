
#include <iostream>
using namespace std;
/* 
Write a method to print the last K lines of an input file using C++
*/

bool lastKLines(int k, string filename) {

	if((k <=0 ) | filename.empty()) return(false);

	istream file(filename); opens file name filename.

	string buffer[k];
	int current ; // pointer to next element in circular array.

	while(file.peek() != EOF){

		file.getline(file, buffer[current%k]);
		current++ ;
	}

	//FORGOT CASE  current++ < k ...
	
	// out of while when reached the EOF.
	// just need to print the K lines now.
	for(int i=current;i<current + k;i++){
		cout << buffer[current%k];
	}

// NOTE : NOTE COMPILED NEITHER VERIFIED, JUST FOR WRITING TEST.
}

/*
NOT : gcc Multiples3And5_v01.c -o Multiples3And5_v01

Use g++ (and a .cpp file extension) for C++ code.

g++ Multiples3And5_v01.cpp -o Multiples3And5_v01

*/
