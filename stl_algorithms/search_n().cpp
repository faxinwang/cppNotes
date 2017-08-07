#include"algostuff.hpp"
using namespace std;

/*
	InputIter
	search_n(InputIter beg, InputIter end, Size n, const T& value)
	
	InputIter
	search_n(InputIter beg, InputIter end, Size n, const T& value,BinaryPredicate op)
	
	* the two algorithms return the position of the first of n consecutive elements in the range
	* both return end if no matching elements are found
*/



int main(){
	deque<int> coll;
	
	INSERT_ELEMENTS(coll,1,9);
	PRINT_ELEMENTS(coll);
	
	//find 4 consecutive elements with value 3
	deque<int>::iterator pos;
	pos=search_n(coll.begin(),coll.end(),4,3);
	
	//print result
	if(pos!=coll.end()){
		cout<<"4 consecutive elements with value 3 start with "
			<<distance(coll.begin(),pos)+1
			<<"th element"<<endl;
	}else{
		cout<<"no 4 consecutive elements with value 3 found"<<endl;
	}
	
	//find 4 consecutive elements with value greater than 3
	pos=search_n(coll.begin(),coll.end(),4,3,greater<int>());
	
	//print result
	if(pos!=coll.end()){
		cout<<"4 consecutive elements with value > 3 start with "
			<<distance(coll.begin(),pos)+1
			<<"th element"<<endl;
	}else{
		cout<<"no 4 consecutive elements with value > 3 found"<<endl;
	}
	
	
	return 0;
}
