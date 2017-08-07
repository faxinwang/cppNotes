#include"algostuff.hpp"
using namespace std;
/*
Search first and last possible position
	pair<ForwardIter,ForwardIter>
	equal_range(ForwardIter beg, ForwardIter end, const T& value)
	
	pair<ForwardIter,ForwardIter>
	equal_range(ForwardIter beg, ForwardIter end, const T& value,
				BinaryPredicate op)
	
	* associative containers provide equivalent member functions that provide 
	  better performance
	* this is equivalent to make_pair(lower_bound(...),upper_bound(...))
*/

int main(){
	typedef list<int> IntList;
	IntList coll;
	INSERT_ELEMENTS(coll,1,9);
	INSERT_ELEMENTS(coll,1,9);
	coll.sort();
	PRINT_ELEMENTS(coll);
	
	//print first and last position 5 could get inserted
	pair<IntList::iterator, IntList::iterator> range;
	range = equal_range(coll.begin(),coll.end(),5);
	
	cout<<"5 could get position "
		<<distance(coll.begin(),range.first)+1
		<<" up to "
		<<distance(coll.begin(),range.second)+1
		<<" without breaking the sorting"<<endl;
	
	return 0;
}
