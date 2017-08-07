#include"algostuff.hpp"
using namespace std;

/*
Removing Elements While Copying
	OutputIter
	remove_copy(InputIter srcBeg, InputIter srcEnd,
				OutputIter destBeg,
				const T& value)
	OutputIter
	remove_copy_if(InputIter srcBeg, InputIter srcEnd,
				   OutputIter destBeg,
				   UnaryPredicate op)
*/

int main(){
	list<int> coll1;
	
	INSERT_ELEMENTS(coll1,1,6);
	INSERT_ELEMENTS(coll1,1,9);
	PRINT_ELEMENTS(coll1);
	
	//print elements without those having the value 3
	remove_copy(coll1.begin(),coll1.end(),
				ostream_iterator<int>(cout," "),
				3);
	cout<<endl;
	//print elements without those having a value greater than 4
	remove_copy_if(coll1.begin(),coll1.end(),
				ostream_iterator<int>(cout," "),
				bind2nd(greater<int>(),4));
	cout<<endl;
	
	//copy all elements greater than 3 into a multiset
	multiset<int> coll2;
	remove_copy_if(coll1.begin(),coll1.end(),
				   inserter(coll2,coll2.end()),
				   bind2nd(less<int>(),3));
	PRINT_ELEMENTS(coll2);
	
	return 0;
}
