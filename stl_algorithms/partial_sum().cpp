#include"algostuff.hpp"
using namespace std;
/*
Converting relative values into absolute values
	OutputIter
	partial_sum(InputIter beg, InputIter end,
				OutputIter destBeg)
	OutputIter
	partial_sum(InputIter beg, InputIter end,
				OutputIter destBeg, BinaryFunc op)
	* For the value
		a1 a2 a3 ...
	  they compute either
	  	a1,a1+a2,a1+a2+a3,...
	  or
	  	a1,a1 op a2,a1 op a2 op a3,...
*/
int main(){
	vector<int> coll;
	INSERT_ELEMENTS(coll,1,6);
	PRINT_ELEMENTS(coll);
	
	//print all partial sums
	partial_sum(coll.begin(),coll.end(),
				ostream_iterator<int>(cout," "));
	cout<<endl;
	
	//print all partial product
	partial_sum(coll.begin(),coll.end(),
				ostream_iterator<int>(cout," "),
				multiplies<int>());
	cout<<endl;
	
	return 0;
}
