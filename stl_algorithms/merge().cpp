#include"algostuff.hpp"
using namespace std;
/*
Mergeing elements
	OutputIter
	merge(InputIter beg1, InputIter end1,
		  InputIter beg2, InputIter end2,
		  OutputIter destBeg)
	OutputIter
	merge(InputIter beg1, InputIter end1,
		  InputIter beg2, InputIter end2,
		  OutputIter destBeg, BinaryPredicate op)
	
	* list provide a special a special member function,merge(),to merge the 
	  elements of two list
	* to ensure that elements that are in both source ranges end up in the 
	  destination range only once, use set_union()
	* to process only the elements that are in both source ranges, use 
	  set_intersection()
	  
*/
int main(){
	list<int> coll1;
	set<int> coll2;
	
	//fill both collection with some sorted elements
	INSERT_ELEMENTS(coll1,1,6);
	INSERT_ELEMENTS(coll2,3,8);
	
	PRINT_ELEMENTS(coll1,"coll1: ");	
	PRINT_ELEMENTS(coll2,"coll2: ");
	
	//print merge sequence
	cout<<"merged: ";
	merge(coll1.begin(),coll1.end(),
		  coll2.begin(),coll2.end(),
		  ostream_iterator<int>(cout," "));
	
	return 0;
}
