#include"algostuff.hpp"
using namespace std;
/*
	bool
	binary_search(ForwardIter beg, ForwardIter end, const T& value)
	
	bool
	binary_search(ForwardIter beg, ForwardIter end, const T& value,
				  BinaryPredicate op)
	
	* to obtain the position of an elements for which you are search,
	  use lower_bound(),upper_bound(),or equal_range()
*/

int main(){
	list<int> coll;
	INSERT_ELEMENTS(coll,1,9);
	PRINT_ELEMENTS(coll);
	
	//check existence of elements with value 5
	if(binary_search(coll.begin(),coll.end(),5)){
		cout<<"5 is present"<<endl;
	}
	else{
		cout<<"5 is not present"<<endl;
	}
	
	//check existence of elements with value 42
	if(binary_search(coll.begin(),coll.end(),42)){
		cout<<"42 is present"<<endl;
	}
	else{
		cout<<"42 is not present"<<endl;
	}
	
	return 0;
}
