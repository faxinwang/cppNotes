#include"algostuff.hpp"
using namespace std;

/*
Copy Elements
	OutputIter
	copy(InputIter srcBeg, InputIter srcEnd, OutputIter destBeg)
	
	OutputIter
	copy_backward(BidirectionalIter1 srcBeg,BidirectionalIter1 srcEnd,
		 BidirectionalIter1 destEnd)
	
	* destBeg or destEnd should not be part of [srcBeg,srcEnd)
	* to modify elements while they are being copied,use transform() or replace_copy()
	* to remove elements while they are being copied,use remove_copy() and remove_copy_if()
*/


int main(){
	vector<int> coll1;
	list<int> coll2;
	
	INSERT_ELEMENTS(coll1,1,9);
	
	//copy elements of coll1 into coll2
	//use back inserter to insert instead of overwrite
	copy(coll1.begin(),coll1.end(),back_inserter(coll2));
	copy(coll2.begin(),coll2.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
	
	//copy elements of coll1 into coll2 in reverse order
	//now overwriting
	copy(coll1.rbegin(),coll1.rend(),coll2.begin());
	copy(coll2.begin(),coll2.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
	
	
	return 0;
}
