#include"algostuff.hpp"
using namespace std;

/*
Search the First Difference
	pair<InputIter1,InputIter2>
	mismatch(InputIter1 beg1, InputIter1 end1,
			 InputIter2, beg2)
			 
	pair<InputIter1,InputIter2>
	mismatch(InputIter1 beg1, InputIter1 end1,
			 InputIter2, beg2,
			 BinaryPredicate op)
	
	* the first form returns the first two corresponding elements of range [beg1,end) and the 
	  ragne starting with beg2 that differ
	* the second form returns the first two corresponding elements of range [beg,end) and the 
	  range starting with beg2 for which the binary predicate op(elem1,elem2) yields false
*/

int main(){
	vector<int> coll1;
	list<int> coll2;
	INSERT_ELEMENTS(coll1,1,6);
	for(int i=1;i<=16;i*=2){
		coll2.push_back(i);
	}
	coll2.push_back(3);
	
	PRINT_ELEMENTS(coll1,"coll1: ");
	PRINT_ELEMENTS(coll2,"coll2: ");
	
	//find first mismatch
	pair<vector<int>::iterator,list<int>::iterator> values;
	values = mismatch(coll1.begin(),coll1.end(),coll2.begin());
	if(values.first==coll1.end()){
		cout<<"no mismatch"<<endl;
	}
	else{
		cout<<"first mismatch: "
			<<*values.first<<" and "
			<<*values.second<<endl;
	}
	
	//find first position where the elements of coll1 is not 
	//lest than the corresponding elements of coll2
	values=mismatch(coll1.begin(),coll1.end(),
					coll2.begin(),
					less_equal<int>());
	if(values.first == coll1.end()){
		cout<<"coll1 alwasy less-or-equal than coll2"<<endl;
	}
	else{
		cout<<"not less-or-equal: "
			<<*values.first<<" and "
			<<*values.second<<endl;
	}
	
	
	return 0;
}
