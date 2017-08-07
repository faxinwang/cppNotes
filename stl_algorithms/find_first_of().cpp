#include"algostuff.hpp"
using namespace std;

/*
Search First of Several Possible Elements
	ForwardIter
	find_first_of(ForwardIter beg1, ForwardIter end1,
				  FrowardIter beg2, ForwardIter end2)
				  
	ForwardIter
	find_first_of(ForwardIter beg1, ForwardIter end1,
				  FrowardIter beg2, ForwardIter end2,
				  BinaryPredicate op)
	
	* return the position of the first element in the range [beg1,end1) 
	  that is also in the range [beg2,end2)
	* both return end if no matching elements are found
*/

int main(){
	vector<int> coll;
	list<int> searchcoll;
	INSERT_ELEMENTS(coll,1,11);
	INSERT_ELEMENTS(searchcoll,3,5);
	
	PRINT_ELEMENTS(coll,"coll: ");
	PRINT_ELEMENTS(searchcoll,"searchcoll: ");
	
	//search first occurrence of an element of searchcoll in coll
	vector<int>::iterator pos;
	pos=find_first_of(coll.begin(),coll.end(),
					  searchcoll.begin(),searchcoll.end());			  
	cout<<"first element of searchcoll in coll is "
		<<distance(coll.begin(),pos)+1
		<<"th element "<<*pos<<endl;
	
	//search last occurrence of an element of searchcoll in coll
	vector<int>::reverse_iterator rpos;
	rpos=find_first_of(coll.rbegin(),coll.rend(),
					   searchcoll.begin(),searchcoll.end());
	cout<<"last element of searchcoll in coll is "
		<<distance(coll.begin(),rpos.base()) //notice: rpos.base() is coll here
		<<"th element "<<*rpos<<endl;
	
	return 0;
}
