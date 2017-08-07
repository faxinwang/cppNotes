#include"algostuff.hpp"
using namespace std;

/*
	bool
	next_permutation(BidirectionalIter beg, BidirectionalIter end)
	
	bool
	prev_permutation(BidirectionalIter beg, BidirectionalIter end)
	
*/

int main(){
	vector<int> coll;
	INSERT_ELEMENTS(coll,1,3);
	PRINT_ELEMENTS(coll,"on entry: ");
	
	//premute elements until they are sorted
	//runs through all permutions because the elements sorted now
	while(next_permutation(coll.begin(),coll.end())){
		PRINT_ELEMENTS(coll);
	}
	PRINT_ELEMENTS(coll,"afterward: ");
	
	//permute until descending sorted
	//this is the next permutation after ascending sorting
	//so the loop ends immediately
	while(prev_permutation(coll.begin(),coll.end())){
		PRINT_ELEMENTS(coll);
	}
	PRINT_ELEMENTS(coll,"now: ");
	
	//permute elements until they are sorted in descending order
	//runs through all permutations because the elements are sorted
	//in descending order now
	while(prev_permutation(coll.begin(),coll.end())){
		PRINT_ELEMENTS(coll);
	}
	PRINT_ELEMENTS(coll,"afterward: ");
	
	return 0;
} 
