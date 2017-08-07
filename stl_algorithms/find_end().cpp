#include"algostuff.hpp"
using namespace std;

/*
Search Last Subrange
	ForwardIter
	find_end(ForwardIter beg1, ForwardIter end1,
			ForwardIter beg2, ForwardIter end2)
	
	ForwardIter
	find_end(ForwardIter beg1, ForwardIter end1,
			ForwardIter beg2, ForwardIter end2,
			BinaryPredicate op)
*/

int main(){
	deque<int> coll;
	list<int> subcoll;
	INSERT_ELEMENTS(coll,1,7);
	INSERT_ELEMENTS(coll,1,7);
	
	INSERT_ELEMENTS(subcoll,1,7);
	
	PRINT_ELEMENTS(coll,"coll: ");
	PRINT_ELEMENTS(subcoll,"subcoll: ");
	
	//search last occurrence of subcoll in coll
	deque<int>::iterator pos;
	pos=find_end(coll.begin(),coll.end(),
				subcoll.begin(),subcoll.end());
	//loop while subcoll found as subrange of coll
	deque<int>::iterator end(coll.end());
	while(pos!=end){
		//print position of first element
		cout<<"subcoll found starting with "
			<<distance(coll.begin(),pos)+1
			<<"th element"
			<<endl;
			
		//search next occurrence of subcoll
		end=pos;
		pos=find_end(coll.begin(),end,
				subcoll.begin(),subcoll.end());
	}
	
	return 0;
}
