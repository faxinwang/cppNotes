#include"algostuff.hpp"
using namespace std;

/*
Rotating Elements while Copying
	OutputIter
	rotate_copy(ForwardIter beg,
				ForwardIter newBeg,
				ForwardIter end,
				OutputIter destBeg)
	* returns the position after the last copied element in the destination range
*/



int main(){
	set<int> coll;
	INSERT_ELEMENTS(coll,1,9);
	PRINT_ELEMENTS(coll);
	
	//print elements rotated one element to the left
	set<int>::iterator pos=coll.begin();
	advance(pos,1);
	rotate_copy(coll.begin(),
				pos,
				coll.end(),
				ostream_iterator<int>(cout," "));
	cout<<endl;
	
	//print elements rotated two element to right
	pos=coll.end();
	advance(pos,-2);
	rotate_copy(coll.begin(),
				pos,
				coll.end(),
				ostream_iterator<int>(cout," "));
	cout<<endl;
	
	//print elements rotated so that elements with value 4 is the beginning
	rotate_copy(coll.begin(),
				coll.find(4),
				coll.end(),
				ostream_iterator<int>(cout," "));
	cout<<endl;

	return 0;
}
