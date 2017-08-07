#include"algostuff.hpp"
using namespace std;

/*
Rotating Elements Inside a Sequence
	void
	rotate(ForwardIter beg, ForwardIter newBeg,ForwardIter end)
	
	* rotates elements in the range[beg,end) so that *newBeg is the new 
	  first elements after the call
	* the caller must ensure that newBeg is a valid position in the range [beg,end)
	  otherwise, the call results in underfine behavior
*/



int main(){
	vector<int> coll;
	INSERT_ELEMENTS(coll,1,9);
	PRINT_ELEMENTS(coll,"coll: ");
	//rotate one element to the left
	rotate(coll.begin(),coll.begin()+1,coll.end());
	PRINT_ELEMENTS(coll,"one left: ");
	
	//rotate two element to the right
	rotate(coll.begin(),coll.end()-2,coll.end());
	PRINT_ELEMENTS(coll,"two right: ");
	
	//rotate so that elements with value 4 is the begining
	rotate(coll.begin(),
		   find(coll.begin(),coll.end(),4),
		   coll.end());
	PRINT_ELEMENTS(coll,"4 first: ");
	
	return 0;
}
