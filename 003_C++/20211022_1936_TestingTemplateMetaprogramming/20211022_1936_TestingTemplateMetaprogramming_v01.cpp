#include<iostream>
#include<vector>

using namespace std;

template<int N> class Board{

	private:
		int n(3);
		vector<int> maze(n,-1);	
};

int main(){
	Board<9> board;
}
