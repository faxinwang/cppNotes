#include"algostuff.hpp"
using namespace std;
/*
Merge consecutive sorted Ranges
	void 
	inplace_merge(BidirectionalIter beg1, BidirectionalIter end1beg2,
				  BidirectionalIter end2)
	void 
	inplace_merge(BidirectionalIter beg1, BidirectionalIter end1beg2,
				  BidirectionalIter end2, BinaryPredicate op)
	* both forms merge the consecutive sorted source ranges [beg1,end1beg2) and
	  [end1beg2,end2) so that the range [beg1,end2) contains the elements as a
	  sorted summary range.
*/

int main(){
	list<int> coll;
	
	INSERT_ELEMENTS(coll,1,7);
	INSERT_ELEMENTS(coll,1,8);
	PRINT_ELEMENTS(coll);
	
	//find beginning of second part(element after 7)
	list<int>::iterator pos;
	pos=find(coll.begin(),coll.end(),7);
	++pos;
	//merge into one sorted range
	inplace_merge(coll.begin(),pos,coll.end());
	PRINT_ELEMENTS(coll);
	
	return 0;
}
