#include"algostuff.hpp"
using namespace std;

/*
Removing elements in a sequence
	ForwardIter
	remove(ForwardIter beg, ForwardIter end, const T& value)
	
	ForwardIter
	remove(ForwardIter beg, ForwardIter end, UnaryPredicate op)
	
	* list provide an equivalent member function remove(),which offers better 
	  performance	   
*/ 

int main(){
	vector<int> coll;
	INSERT_ELEMENTS(coll,2,6);
	INSERT_ELEMENTS(coll,4,9);
	INSERT_ELEMENTS(coll,1,7);
	PRINT_ELEMENTS(coll,"coll:\t\t\t");
	
	//remove all elements with value 5
	vector<int>::iterator pos;
	pos=remove(coll.begin(),coll.end(),5);
	PRINT_ELEMENTS(coll,"size not changed:\t");
	
	coll.erase(pos,coll.end());
	PRINT_ELEMENTS(coll,"size changed:\t\t");
	
	//remove all elements less than 4
	coll.erase(remove_if(coll.begin(),coll.end(),
						 bind2nd(less<int>(),4)),
			   coll.end());	
	PRINT_ELEMENTS(coll,"<4 removed:\t\t");
	
	return 0;
}
