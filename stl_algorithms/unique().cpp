#include"algostuff.hpp"
using namespace std;

/*
Removing Consecutive Duplicates
	ForwardIter
	unique(ForwardIter beg, ForwardIter end)
	
	ForwardIter
	unique(ForwardIter beg, ForwardIter end,BinaryPredicate op)
	
	* both form collapse consecutive equal elements by removing the following duplicates
	* both form compare elements with the previous that was not removed, so only when
	  the elements in the sequence are sorted does it remove all duplicates.
*/


int main(){
	//source data
	int source[]={1,4,4,6,1,2,2,3,1,6,6,6,5,7,5,4,4};
	int sourceNum=sizeof(source)/sizeof(source[0]);
	
	vector<int> coll;
	
	//initialize coll with elements from source
	copy(source,source+sourceNum,
		 back_inserter(coll));
	PRINT_ELEMENTS(coll);
	
	//remove consecutive duplicate
	vector<int>::iterator pos;
	pos = unique(coll.begin(),coll.end());
	
	//print elements not removed use new logical end
	copy(coll.begin(),pos,ostream_iterator<int>(cout," "));
	cout<<"\n\n";
	
	//initialize coll with elements from source
	copy(source,source+sourceNum,coll.begin());
	PRINT_ELEMENTS(coll);
	
	//remove elements if there was a previous greater elements
	coll.erase(unique(coll.begin(),coll.end(),greater<int>()),
				coll.end());
	PRINT_ELEMENTS(coll);
	
	//initialize coll with elements from source
	copy(source,source+sourceNum,coll.begin());
	sort(coll.begin(),coll.end());
	copy(coll.begin(),unique(coll.begin(),coll.end()),
		 ostream_iterator<int>(cout," "));
	
	
	return 0;
}
