#include"algostuff.hpp"
using namespace std;

/*
	void
	sort(RandomAccessIter beg, RandomAccessIter end)
	
	void
	sort(RandomAccessIter beg, RandomAccessIter end, BinaryPredicate op)
*/

int main(){
	deque<int> coll;
	INSERT_ELEMENTS(coll,1,9);
	INSERT_ELEMENTS(coll,1,9);
	PRINT_ELEMENTS(coll,"on entry: ");
	
	//shullfe elements
	random_shuffle(coll.begin(),coll.end());
	PRINT_ELEMENTS(coll,"random shuffled: ");
	
	//sort elements
	sort(coll.begin(),coll.end());
	PRINT_ELEMENTS(coll,"ascending sorted: ");
	
	//sorted reverse
	sort(coll.begin(),coll.end(),greater<int>());
	PRINT_ELEMENTS(coll,"descending sorted: ");
	

	return 0;
}
