#include"algostuff.hpp"
using namespace std;

/*
Removing Duplicates While Copying
	OutputIter
	unique_copy(InputIter beg, InputIter end,OutputIter destBeg)
	
	OutputIter
	unique_copy(InputIter beg,InputIter end,
				OutputIter destBeg,
				BinaryPredicate op)
*/

bool differenceOne(int elem1,int elem2){
	return elem1+1==elem2 || elem1-1==elem2;
}

int main(){
	int source[]={1,4,4,6,1,2,2,3,1,6,6,6,5,7,5,4,4};
	int sourceNum=sizeof(source)/sizeof(source[0]);
	
	//initialize coll with elements from source
	list<int> coll;
	copy(source,source+sourceNum,back_inserter(coll));
	PRINT_ELEMENTS(coll);
	
	//print elements with consecutive duplicate removed
	unique_copy(coll.begin(),coll.end(),
				ostream_iterator<int>(cout," "));
	cout<<endl;
	
	//print elements without consecutive duplicate that differ by one
	unique_copy(coll.begin(),coll.end(),
				ostream_iterator<int>(cout," "),
				differenceOne);
	cout<<endl;
	
	
	return 0;
}
