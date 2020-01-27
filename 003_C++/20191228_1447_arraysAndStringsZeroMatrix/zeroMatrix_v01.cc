/* Description :
	Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.
	Hints : #17, #74, #102 
*/
#include <string>
#include <iostream>
using namespace std;

void zeroMatrix(int[][] matrix, int nbRows, int nbCol){

	// return if nbRows or nbCol are null or matrix is null
	int zeroRow(-1),zeroColumn(-1);
	for(int i=0;i<nbRows;i++){
		for(int j=0;j<nbCol;i++){
			if (matrix[i][j] == 0){
				if (zeroRow == -1){
					// first 0 found --> initialize zeroRow and zeroColumn
					zeroRow = i ;
					zeroColumn = j ;	
				}
				else{
					matrix[zeroRow][j] = 0;
					matrix[i][zeroColumn] = 0;
				}
			}
		}
	}

	// now all rows and columns to fill with zeros are marked in row zeroRow and column zeroColumn

	// fill required columns with zeros.
	// avoid zeroColumn/zeroRow
	for(int i=0;i<nbRows;i++){
		if (i!= zeroRow){
			if (matrix[i][zeroColumn] == 0){
				// fill row i with zeros
				for(int j=0;j<nbCol;i++){
					matrix[i][j] = 0;
				}
			}
		}
	}	

	// fill required rows with zeros
	// avoir zeroColumn/zeroRow
	for(int j=0;j<nbCol;j++){
		if(j!=zeroColumn){
			if(matrix[zeroRow][j] == 0){
				for(int i=0;i<nbRows;i++){
					matrix[i][j] = 0;
				}
			}
		}
	}

	// then fill zeroColumn and zeroRow with zeros
	for(int i=0;i<nbRows;i++){
		matrix[i][zeroColumn] = 0;
	}	
	for(int j=0;j<nbCol;j++){
		matrix[zeroRow][j] = 0;
	}
}

int main(){
	return 0;
}
/* g++ sortFile.cpp -o sortFile

*/