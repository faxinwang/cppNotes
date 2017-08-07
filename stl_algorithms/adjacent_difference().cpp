#include"algostuff.hpp"
using namespace std;
/*
Converting absolute values into relative values
	OutputIter
	adjacent_difference(InputIter beg1, InputIter end,
						OutputIter destBeg)
	OutputIter
	adjacent_difference(InputIter beg1, InputIter end,
						OutputIter destBeg, BinaryFunc op)
	* For the values
		a1 a2 a3 a4...
	  they compute and write either the values
	   	a1,a2-a1,a3-a2,a4-a3,...
	  or 
		a1,a2 op a1,a3 op a2, a4 op a3,...
*/
int main(){
	deque<int> coll;
	INSERT_ELEMENTS(coll,1,6);
	PRINT_ELEMENTS(coll);
	
	//print all differences between elements
	adjacent_difference(coll.begin(),coll.end(),
						ostream_iterator<int>(cout," "));
	cout<<endl;
	
	//print all sums with the predecessors
	adjacent_difference(coll.begin(),coll.end(),
						ostream_iterator<int>(cout," "),
						plus<int>());
	cout<<endl;
	
	//print all products between elements
	adjacent_difference(coll.begin(),coll.end(),
						ostream_iterator<int>(cout," "),
						multiplies<int>());
	cout<<endl;
	
	
	return 0;
}
