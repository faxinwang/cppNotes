#include"algostuff.hpp"
using namespace std;

/*
Replacing Values Inside a Sequence
	void
	replace(ForwardIter beg, ForwardIter end,
			const T& oldValue, const T& newValue)
	void
	replace_if(ForwardIter beg,ForwardIter end,
			   UnaryPredicate op, const T& newValue)
*/

int main(){
	list<int> coll;
	
	INSERT_ELEMENTS(coll,2,7);
	INSERT_ELEMENTS(coll,4,9);
	
	PRINT_ELEMENTS(coll,"coll: ");
	
	//replace all elements with value 6 with 42
	replace(coll.begin(),coll.end(),6,42);
	PRINT_ELEMENTS(coll,"coll: ");
	
	//replace all elements with value less than 5 with 0
	replace_if(coll.begin(),coll.end(),
			bind2nd(less<int>(),5),
			0);
	PRINT_ELEMENTS(coll,"coll: ");
		
	return 0;
}
