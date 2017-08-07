#include"algostuff.hpp"
using namespace std;

/*
Reversing the Order of Elemens
	void
	reverse(BidirectionalIter beg, BidirectionalIter end)
	
	OutputIter
	reverse_copy(BidirectionalIter beg, BidirectionalIter end,
				 OutputIter destBeg)
	* list provide an equivalent member function reverse(), which offers better 
	  performance.
*/


int main(){
	vector<int> coll;
	INSERT_ELEMENTS(coll,1,9);
	PRINT_ELEMENTS(coll,"coll: ");
	
	//reverse order of elements
	reverse(coll.begin(),coll.end());
	PRINT_ELEMENTS(coll,"coll: ");
	
	//reverse order from second to last but one
	reverse(coll.begin()+1,coll.end()-1);
	PRINT_ELEMENTS(coll,"coll: ");
	
	//print all of them in reverse order
	reverse_copy(coll.begin(),coll.end(),
				 ostream_iterator<int>(cout," "));
	cout<<endl;
	
	
	return 0;
}
