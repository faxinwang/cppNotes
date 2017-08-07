#include"algostuff.hpp"
using namespace std;

/*
	RandomAccessIter
	partial_sort_copy(InputIter srcBeg, InputIter srcEnd,
					  RandomAccessIter destBeg,RandomAccessIter destEnd)
	
	RandomAccessIter
	partial_sort_copy(InputIter srcBeg, InputIter srcEnd,
					  RandomAccessIter destBeg,RandomAccessIter destEnd,
					  BinaryPredicate op)
	* both form are a combination of copy() and partial_sort()
	* they copy elements from the source range sorted into the destination range
	* the number of elements that are sorted and copied is the minimum number of
	  elements in the source range and in the destination range
*/

int main(){
	deque<int> coll1;
	vector<int> coll6(6);
	vector<int> coll30(30);
	
	INSERT_ELEMENTS(coll1,3,7);
	INSERT_ELEMENTS(coll1,2,6);
	INSERT_ELEMENTS(coll1,1,5);
	PRINT_ELEMENTS(coll1);
	
	//copy elements of coll1 sorted into coll6
	
	vector<int>::iterator pos6;
	pos6=partial_sort_copy(coll1.begin(),coll1.end(),
						   coll6.begin(),coll6.end());
	cout<<endl;
	//print all copied elements
	copy(coll6.begin(),pos6,
		 ostream_iterator<int>(cout," "));
	cout<<endl;
	
	//copy element of coll1 sorted into coll30
	vector<int>::iterator pos30;
	pos30=partial_sort_copy(coll1.begin(),coll1.end(),
							coll30.begin(),coll30.end(),
							greater<int>());
	//print all copied elements
	copy(coll30.begin(),pos30,
		 ostream_iterator<int>(cout," "));
	cout<<endl;
	return 0;
}
