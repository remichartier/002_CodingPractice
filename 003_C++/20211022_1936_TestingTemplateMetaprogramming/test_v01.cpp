#include<iostream>
#include<vector>

#define WHITE 0
#define BLACK 1
#define EMPTY -1

using namespace std;

template <int N> class Board{
private:
	//vector<int> maze = vector<int>(N);
	vector<vector<int>> maze; // = vector<vector<int>>(N);
public:
	Board(){
		vector<int> row(N, EMPTY);
		for(size_t i=0; i < N; ++i){
			maze.push_back(row);
		}

	}

	void print(){
		for(auto r: maze){
			for(auto c: r){
				cout << c << ", " ;
			} 
			cout << endl;
		}
	}

	
};

int main()
{
    int n = 3;
    Board<9> b;
 
    // Create a vector of size n with
    // all values as 10.
    //vector<int> vect(n, 10);
    //vector<vector<int>> vect2(9,vector<int>(9));
 
    //for (int x : vect)
    //    cout << x << " ";
 	
 	b.print();

    return 0;
}