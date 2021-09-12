/* """Implement a function recursively to get the desired
Fibonacci sequence value.
Your code should have the same input/output as the 
iterative code in the instructions."""

def get_fib(position):
    return -1

# Test cases
print get_fib(9)
print get_fib(11)
print get_fib(0)
*/
#include <iostream>


int get_fib(int n, int& call_counter){
    call_counter++;
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    return (get_fib(n - 1, call_counter) + get_fib(n - 2, call_counter));
}

int main(){

    int nb_of_calls(0);

    std::cout << "get_fib(9) should be 34 = " << get_fib(9,nb_of_calls) <<\
     " with get_fib() called " << nb_of_calls << " times" << std::endl;
    nb_of_calls = 0;

    std::cout << "get_fib(11) should be 89 = " << get_fib(11, nb_of_calls) <<\
     " with get_fib() called " << nb_of_calls << " times" << std::endl;
    nb_of_calls = 0;


    std::cout << "get_fib(0) should be 0 = " << get_fib(0, nb_of_calls) <<\
     " with get_fib() called " << nb_of_calls << " times" << std::endl;
    nb_of_calls = 0;

    return 0;
}

/* ./main.exe 
get_fib(9) should be 34 = 34 with get_fib() called 109 times
get_fib(11) should be 89 = 89 with get_fib() called 287 times
get_fib(0) should be 0 = 0 with get_fib() called 1 times */