#include"algostuff.hpp"
using namespace std;

/*
Moving elements to the front
	BidirectionalIter
	partition(BidirectionalIter beg, BidirectionalIter end, UnaryPredicate op)
	
	BidirectionalIter
	stable_partition(BidirectionalIter beg, BidirectionalIter end,
					 UnaryPrediate op)
*/


int main(){
	vector<int> coll1;
	vector<int> coll2;
	
	INSERT_ELEMENTS(coll1,1,9);
	INSERT_ELEMENTS(coll2,1,9);
	PRINT_ELEMENTS(coll1,"coll1: ");
	PRINT_ELEMENTS(coll2,"coll2: ");
	cout<<endl;
	
	//move all even elements to the front
	vector<int>::iterator pos1,pos2;
	pos1=partition(coll1.begin(),coll1.end(),
				   not1(bind2nd(modulus<int>(),2)));
	pos2=stable_partition(coll2.begin(),coll2.end(),
						  not1(bind2nd(modulus<int>(),2)));
	
	//print collection and first odd element
	PRINT_ELEMENTS(coll1,"coll1: ");
	cout<<"first odd elements: "<<*pos1<<endl;
	PRINT_ELEMENTS(coll2,"coll2: ");
	cout<<"first odd elements: "<<*pos2<<endl;
	
	
	
	return 0;
}
