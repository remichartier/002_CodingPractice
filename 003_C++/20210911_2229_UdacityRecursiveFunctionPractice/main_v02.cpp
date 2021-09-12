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
#include <vector>


int get_fib(int n, int& call_counter, std::vector<int> & l){
    // have a static vector size n+1,    
    call_counter++;
    if(n <= 0){
        l[0] = 0;
        return 0;
    }
    if(n == 1){
        l[1] = 1;
        return 1;
    }
    if(l[n-1] == 0){
        l[n-1] == get_fib(n - 1, call_counter, l);
    }
    if(l[n-2] == 0){
        l[n-2] == get_fib(n - 2, call_counter, l);
    }
    l[n] = l[n-1] + l[n-2];
    return(l[n]);
    //return (get_fib(n - 1, call_counter) + get_fib(n - 2, call_counter));
    //return (get_fib(n - 1, call_counter, l) + l[n-2]);
    //return (get_fib(n - 1, call_counter, l));

}

int main(){

    int nb_of_calls(0);

    std::vector<int> list(89,0);

    std::cout << "get_fib(9) should be 34 = " << get_fib(9,nb_of_calls, list) <<\
     " with get_fib() called " << nb_of_calls << " times" << std::endl;
    nb_of_calls = 0;


    for(auto& a : list){
        a = 0;
    }
    std::cout << "get_fib(11) should be 89 = " << get_fib(11, nb_of_calls, list) <<\
     " with get_fib() called " << nb_of_calls << " times" << std::endl;
    nb_of_calls = 0;

    for(auto& a : list){
        a = 0;
    }
    std::cout << "get_fib(0) should be 0 = " << get_fib(0, nb_of_calls, list) <<\
     " with get_fib() called " << nb_of_calls << " times" << std::endl;
    nb_of_calls = 0;

    return 0;
}

/* ./main.exe without optimization with a list
get_fib(9) should be 34 = 34 with get_fib() called 109 times
get_fib(11) should be 89 = 89 with get_fib() called 287 times
get_fib(0) should be 0 = 0 with get_fib() called 1 times */

/*./main.exe 
get_fib(9) should be 34 = 34 with get_fib() called 10 times
get_fib(11) should be 89 = 89 with get_fib() called 12 times
get_fib(0) should be 0 = 0 with get_fib() called 1 times

*/