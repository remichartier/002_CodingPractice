/*"""You're going to write a binary search function.
You should use an iterative approach - meaning
using loops.
Your function should take two inputs:
a Python list to search through, and the value
you're searching for.
Assume the list only has distinct elements,
meaning there are no repeated values, and 
elements are in a strictly increasing order.
Return the index of value, or -1 if the value
doesn't exist in the list."""

def binary_search(input_array, value):
    """Your code goes here."""
    return -1

test_list = [1,3,9,11,15,19,29]
test_val1 = 25
test_val2 = 15
print binary_search(test_list, test_val1)
print binary_search(test_list, test_val2)*/

#include <iostream>
#include <vector>


int binary_search(std::vector<int> list, int value){

    int size = list.size();
    int left = 0;
    int right = size -1;
    int middle = int((left + right) / 2);
    
    if(list[middle] == value)
            return middle;
    
    //std::cout << "middle : " << middle << std::endl;
    while ((middle > left) && (middle < right)){
        if(value < list[middle])
            right = middle -1;
        else
            left = middle +1;
        middle = int((left + right) / 2);        
        if(list[middle] == value)
            return middle;
    }    
    return -1;
}

int main(){
    std::vector<int> test_list({1,3,9,11,15,19,29});
    int test_val1(25);
    int test_val2(15);

    std::cout << "Should be -1 : "<< binary_search(test_list, test_val1) << std::endl;
    std::cout << "Should be 4 : "<< binary_search(test_list, test_val2) << std::endl;

    return 0;
}