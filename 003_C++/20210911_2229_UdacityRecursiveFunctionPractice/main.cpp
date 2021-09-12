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

int get_fib(int n){
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    return (get_fib(n - 1) + get_fib(n - 2));
}

int main(){

    std::cout << "get_fib(9) should be 34 = " << get_fib(9) << std::endl;
    std::cout << "get_fib(11) should be 89 = " << get_fib(11) << std::endl;
    std::cout << "get_fib(0) should be 0 = " << get_fib(0) << std::endl;
    return 0;
}
