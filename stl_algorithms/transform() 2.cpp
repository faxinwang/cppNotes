#include"algostuff.hpp"
using namespace std;
/*
Comebining Elements of Two Sequences
	OutputIter
	transform(InputIter beg1,InputIter end1,
			  InputIter beg2,
			  OutputIter destBeg,
			  BinaryFunc op)
			  
	* Calls op(elem1,elem2) for all corresponding elements from the two source range
	  and writes each result to the destination range
*/


int main(){
	vector<int> coll1;
	list<int> coll2;
	
	INSERT_ELEMENTS(coll1,1,9);
	PRINT_ELEMENTS(coll1,"coll1: ");
	
	//square each element
	transform(coll1.begin(),coll1.end(),
			  coll1.begin(),
			  coll1.begin(),
			  multiplies<int>());
	PRINT_ELEMENTS(coll1,"coll1 squared: ");
	
	//add each element traversed forward with each element travsersed backward and
	//insert result into coll2
	transform(coll1.begin(),coll1.end(),
			  coll1.rbegin(),
			  back_inserter(coll2),
			  plus<int>());
	PRINT_ELEMENTS(coll2,"coll2: ");
	
	cout<<"diff: ";
	transform(coll1.begin(),coll1.end(),
			  coll2.begin(),
			  ostream_iterator<int>(cout," "),
			  minus<int>());
	cout<<endl;
	
	
	return 0;
}
