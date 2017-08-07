#include"algostuff.hpp"
using namespace std;

/*
	InputIter
	find(InputIter beg, InputIter end, const T& value)
	
	InputIter
	find_if(InputIter beg, InputIter end, UnaryPredicate op)
	
	*both forms return end if no matching elements are found
*/

int main(){
	
	list<int> coll;
	INSERT_ELEMENTS(coll,1,9);
	INSERT_ELEMENTS(coll,1,9);
	
	PRINT_ELEMENTS(coll,"coll: ");
	
	//find fisrt elements with value 4
	list<int>::iterator pos1;
	pos1 = find(coll.begin(),coll.end(),4);
	/* find second element with value 4
	*-node: continue the search behind the first 4(if any)
	*/
	list<int>::iterator pos2;
	if(pos1!=coll.end()){
		pos2=find(++pos1,coll.end(),4);
	}
	//print all elements from first to second 4(both included)
	if(pos1!=coll.end() && pos2!=coll.end()){
		copy(--pos1,++pos2,ostream_iterator<int>(cout," "));
		cout<<endl;
	}
	return 0;
}
