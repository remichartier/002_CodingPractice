/* """Implement quick sort in Python.
Input a list.
Output a sorted list."""
def quicksort(array):
    return []

test = [21, 4, 1, 3, 9, 20, 25, 6, 21, 14]
print quicksort(test)
*/

#include <iostream>
#include <vector>


void print_vector(std::vector<int> test){
	for(size_t i=0; i < test.size(); i++){
		if(i==0){
			std::cout << "test = {" << test[i];
		}
		else{
			std::cout << ", " << test[i];	
		}
		if(i == test.size() -1){
			std::cout << "}" << std::endl;
		}
	}	
}

void sortHelper(std::vector<int> & test,size_t left, size_t right){
	int pivot;
	int mem;

	// take last element as pivot
	pivot = right;
	for(size_t i=left; i <= right; i++){
		if ((i == pivot) ||\
		 ((test[i] <= test[pivot]) && (i < pivot)) ||\
		 ((test[i] > test[pivot]) && (i > pivot)) ){
			continue;
		}
		while((test[i] > test[pivot]) && (i < pivot)){
			mem = test[i]; // 21
			test[i] = test[pivot -1]; //21
			test[pivot -1] = test[pivot]; //14
			test[pivot] = mem; //21
			pivot = pivot -1; //14
		}
		while((test[i] <= test[pivot]) && (i > pivot)){
			mem = test[i];
			test[i] = test[pivot +1];
			test[pivot +1] = test[pivot];
			test[pivot] = mem;
			pivot = pivot +1;
		}
	}

	// print result of current quick sort
	std::cout << "Pivot = " << pivot << " ; ";
	print_vector(test);

	if(pivot -1 > left){
		std::cout << "sortHelper(test, left = "<< left << ", pivot -1 = " <<\
		 pivot -1 << ");" << std::endl; 
		sortHelper(test,left, pivot -1);
	}
	if(pivot +1 < right){
		std::cout << "sortHelper(test, pivot +1 = "<< pivot +1 << ", right = " <<\
		 right << ");" << std::endl; 
		sortHelper(test,pivot +1, right);	
	}
}


void quicksort(std::vector<int> & test){
	int length = test.size();
	sortHelper(test, 0, length -1);
}


int main(){
	std::vector<int> test = {21, 4, 1, 3, 9, 20, 25, 6, 21, 14};
	std::cout << "Starting array : " ;
	print_vector(test);

	quicksort(test);

	std::cout << "Ending array : " ;
	print_vector(test);

	return 0;
}

// g++ main.cpp -o main.exe