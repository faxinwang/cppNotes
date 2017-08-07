#include"algostuff.hpp"
using namespace std;
/*
Swapping Elements
	ForwardIter
	swap_ranges(ForwardIter1 beg1,ForwardIter1 end1,
				ForwardIter2 beg2)
	
	* to swap all elements of a container of the same type,use its 
	  swap() member function which usually has constant complexity
*/


int main(){
	vector<int> coll1;
	deque<int> coll2;
	
	INSERT_ELEMENTS(coll1,1,9);
	INSERT_ELEMENTS(coll2,11,23);
	
	PRINT_ELEMENTS(coll1,"coll1: ") ;
	PRINT_ELEMENTS(coll2,"coll2: ");
	
	//swap elements of coll1 with corresponding elmenets of coll2
	deque<int>::iterator pos;
	pos=swap_ranges(coll1.begin(),coll1.end(),
				   coll2.begin());
				   
	PRINT_ELEMENTS(coll1,"coll1: ") ;
	PRINT_ELEMENTS(coll2,"coll2: ");
	if(pos!=coll2.end()){
		cout<<"first element not modified in coll2: "<<*pos<<endl; 
	}
	
	//mirror first here with last three elements in coll2
	swap_ranges(coll2.begin(),coll2.begin()+3,
				coll2.rbegin());
	PRINT_ELEMENTS(coll2,"\ncoll2: ");
	
	
	return 0;
}
