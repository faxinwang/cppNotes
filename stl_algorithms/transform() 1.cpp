#include"algostuff.hpp"
using namespace std;

/*
Transforming and combining Elements
	OutputIter
	transform(InputIter srcBeg, InputIter srcEnd,
			  OutputIter destBef,
			  UnaryFunc op)
	* the first form has four arguments.It transform elements from a source to a 
	  destination range.Thus,it copies and modifies alements in one step
*/


int main(){
	vector<int> coll1;
	list<int> coll2;
	INSERT_ELEMENTS(coll1,1,5);
	INSERT_ELEMENTS(coll1,-5,0);
	PRINT_ELEMENTS(coll1,"coll1: ");
	//negate all elements in coll1
	transform(coll1.begin(),coll1.end(),
			  coll1.begin(),
			  negate<int>());
	PRINT_ELEMENTS(coll1,"negated: ");
	
	//transform elements of coll1 into coll2 with ten times their value
	transform(coll1.begin(),coll1.end(),
			  back_inserter(coll2),
			  bind2nd(multiplies<int>(),10));
	PRINT_ELEMENTS(coll2,"coll2: ");
	
	//print coll2 negatively and in reverse order
	transform(coll2.rbegin(),coll2.rend(),
			  ostream_iterator<int>(cout," "),
			  negate<int>());
	cout<<endl;
	
	
	return 0;
} 
