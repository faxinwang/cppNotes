#include"algostuff.hpp"
using namespace std;
/*
Checking whether several elements are present
	bool
	includes(InputIter1 beg1, InputIter1 end1,
			 InputIter2 beg2, InputIter2 end2)
	bool
	includes(InputIter1 beg1, InputIter1 end1,
			 InputIter2 beg2, InputIter2 end2,
			 BinaryPredicate op)
*/

int main(){
	list<int> coll;
	vector<int> search;
	
	INSERT_ELEMENTS(coll,1,9);
	PRINT_ELEMENTS(coll,"coll: ");
	
	search.push_back(3);
	search.push_back(4);
	search.push_back(7);
	PRINT_ELEMENTS(search,"search: ");
	
	//check whether all elements in search are also in coll
	if(includes(coll.begin(),coll.end(),
				search.begin(),search.end())){
		cout<<"all elements of search are also in coll"<<endl;				
	}
	else{
		cout<<"not all elements of search are also in coll"<<endl;
	}
	
	return 0;
}
