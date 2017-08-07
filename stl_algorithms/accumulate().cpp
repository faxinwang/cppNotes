#include"algostuff.hpp"
using namespace std;
/*
Computing the result of one sequence
	T
	accumulate(InputIter beg, InputIter end, T initValue)
	
	T
	accumulate(InputIter beg, InputIter end, T initValue, BinaryFunc op)
	
	* the first form computes and returns the sum of initValue and all elements
	  in the range [beg,end),in particular,is calls
	  	initValue = initValu,elem
	  for each elements. 
	* the second form computes and returns the result of colling op for initValue
	  and all elements in the range [beg,end),it calls
	  	initValue = op(initValue,elem)
	  for each elements
	* if the range is empty,both forms return initValue
*/

int main(){
	vector<int> coll;
	INSERT_ELEMENTS(coll,1,9);
	PRINT_ELEMENTS(coll);
	
	//process sum of elements
	cout<<"sum: "
		<<accumulate(coll.begin(),coll.end(),0)
		<<endl;
	
	//process sum of elements less 100
	cout<<"sum: "
		<<accumulate(coll.begin(),coll.end(),-100)
		<<endl;
	
	//process product of elements
	cout<<"product: "
		<<accumulate(coll.begin(),coll.end(),
					 1,
					 multiplies<int>())
		<<endl;
	
	//process product of elements(use 0 as initial value
	cout<<"product: "
		<<accumulate(coll.begin(),coll.end(),
				   0,
				   multiplies<int>())
		<<endl;
	return 0;
} 
