
#include <iostream>
using namespace std;
/* Implement a function void reverse(char* str) in C or C++ which reverses a null-terminated string */

void revers(char* str){

	// need to know the length ...
	int size(0);
	char c;
	while(str[size] != '\0'){
		size++;
	}

	// now that we know the size, we can start to swap the characters.
	for (int i=0;i<(size/2);++i){

		c = str[i];
		str[i] = str[size-1-i];
		str[size-1-i] = c;
	}

}


// NOTE : NOTE COMPILED NEITHER VERIFIED, JUST FOR WRITING TEST.


/*
NOT : gcc Multiples3And5_v01.c -o Multiples3And5_v01

Use g++ (and a .cpp file extension) for C++ code.

g++ Multiples3And5_v01.cpp -o Multiples3And5_v01

*/
