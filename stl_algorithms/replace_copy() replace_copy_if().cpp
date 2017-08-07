#include"algostuff.hpp"
using namespace std;

/*
Copying and Replacing Elements
	OutputIter
	replace_copy(InputIter srcBeg,InputIter srcEnd,
				 OutputIter destBeg,
				 const T& oldValue,const T& newValue)
	OutputIter
	replace_copy_if(InputIter srcBeg,InputIter srcEnd,
					OutputIter destBeg,
					UnaryPredicate op,const T& newValue)
*/


int main(){
	list<int> coll;
	INSERT_ELEMENTS(coll,2,6);
	INSERT_ELEMENTS(coll,4,9);
	PRINT_ELEMENTS(coll);
	
	//print all elements with value 5 replaced wiht 55
	replace_copy(coll.begin(),coll.end(),
				 ostream_iterator<int>(cout," "),
				 5,55);
	cout<<endl;
	
	//print all elements with a value less than 5 replaced with 42
	replace_copy_if(coll.begin(),coll.end(),
					ostream_iterator<int>(cout," "),
					bind2nd(less<int>(),5),
					42);
	cout<<endl;
	
	//print each element while each odd element is replaced with 0
	replace_copy_if(coll.begin(),coll.end(),
					ostream_iterator<int>(cout," "),
					bind2nd(modulus<int>(),2),
					0);
	cout<<endl;
	
	return 0;
}
