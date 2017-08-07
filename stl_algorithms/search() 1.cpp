#include"algostuff.hpp"
using namespace std;

/*
	ForwardIter1
	search(ForwardIter1 beg1, ForwardIter1 end1,
			ForwardIter2 beg2, ForwardIter2 end2)
	
	ForwardIter1
	search(ForwardIter1 beg1, ForwardIter1 end1,
			ForwardIter2 beg2, ForwardIter2 end2,
			BinaryPredicate op)
	
	* both forms return the position of the first element of first subrange matching 
	  the range [beg2,end2) in range [beg1,end1)
	* both return end if no matching range are found
*/

int main(){
	deque<int> coll;
	list<int> subcoll;
	INSERT_ELEMENTS(coll,1,7);
	INSERT_ELEMENTS(coll,1,7);
	
	INSERT_ELEMENTS(subcoll,3,6);
	
	PRINT_ELEMENTS(coll,"coll: ");
	PRINT_ELEMENTS(subcoll,"subcoll: ");
	
	//search first occurrence of subcoll in coll
	deque<int>::iterator pos;
	pos=search(coll.begin(),coll.end(),subcoll.begin(),subcoll.end());
	
	//loop while subcoll found as subrange of coll
	while(pos!=coll.end()){
		//print position of first element
		cout<<"subcoll found starting with "
			<<distance(coll.begin(),pos)+1
			<<"th element"
			<<endl;
			
		//search next occurrence of subcoll
		pos = search(++pos,coll.end(),subcoll.begin(),subcoll.end());
	}
	
	
	return 0;
}
