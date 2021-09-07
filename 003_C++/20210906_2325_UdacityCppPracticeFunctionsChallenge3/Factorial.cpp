/* Functions
In this quiz, I want you to write a function called factorial that returns an int. 
A factorial is a mathematical operation designated by a !! operator 
and returns the product of a number and every whole number between it and 0. 
For example:

4! = 4 \cdot 3 \cdot 2 \cdot 1 = 244!=4⋅3⋅2⋅1=24

You'll write your code within Factorial.cpp. Good luck!
*/

#include "Factorial.h"

// Your code goes here! 
// See Factorial.h for your method's signature (eg, its args and return value).
int Factorial(int n){
	int f(1);
	for(int i=1; i<=n; i++){
		f *= i;
	}
	return(f);
}


/* g++ factorial.cpp main.cpp -o factorial.exe

*/