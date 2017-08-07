#include"algostuff.hpp"
using namespace std;
/*
Searching first or last possible position
	ForwardIter
	lower_bound(ForwardIter beg, ForwardIter end, const T& value)
	ForwardIter
	lower_bound(ForwardIter beg, ForwardIter end, BinaryPredicate op)
	
	ForwardIter
	upper_bound(ForwardIter beg, ForwardIter end, const T& value)
	ForwardIter
	upper_bound(ForwardIter beg, ForwardIter end, BinaryPredicate op)
	
	* all algorighms returns end if there is no such value
	* to obtain the result from both lower_bound() and upper_bound(),use equal_range()
	* associative containers provide equivalent member functions that provide 
	  better performance
*/


int main(){
	list<int> coll;
	
	INSERT_ELEMENTS(coll,1,9);
	INSERT_ELEMENTS(coll,1,9);
	
	coll.sort();
	PRINT_ELEMENTS(coll);
	
	//print first and last position 5 could get inserted
	list<int>::iterator pos1,pos2;
	
	pos1=lower_bound(coll.begin(),coll.end(),5);
	pos2=upper_bound(coll.begin(),coll.end(),5);
	
	cout<<"5 could get position "
		<<distance(coll.begin(),pos1)+1
		<<" up to "
		<<distance(coll.begin(),pos2)+1
		<<" without breaking the sorting"<<endl;
	//insert 3 at first possible position without breaking the sorting
	coll.insert(lower_bound(coll.begin(),coll.end(),
							3)
				,3);
	//insert 7 at last possible position without breaking the sorting
	coll.insert(upper_bound(coll.begin(),coll.end(),
							7),
				7);
	PRINT_ELEMENTS(coll);
	
	return 0;
}
