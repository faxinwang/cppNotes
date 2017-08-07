#include"algostuff.hpp"
using namespace std;

/*
Heap Algorithms
	void
	make_heap(RandomAccessIter beg, RandomAccessIter end)
	void
	make_heap(RandomAccessIter beg, RandomAccessIter end, BinaryPredicate op)
	
	void
	push_heap(RandomAccessIter beg, RandomAccessIter end)
	void
	push_heap(RandomAccessIter beg, RandomAccessIter end, BinaryPredicate op)
	
	void
	pop_heap(AandomAccessIter beg, RandomAccessIter end)
	void
	pop_heap(RandomAccessIter beg, RandomAccessIter end, BinaryPredicate op)
	
	void
	sort_heap(RandomAccessIter beg, RandomAccessIter end)
	void
	sort_heap(RandomAccessIter beg, RandomAccessIter end, BinaryPredicate op)
*/

int main(){
	vector<int> coll;
	INSERT_ELEMENTS(coll,3,7);
	INSERT_ELEMENTS(coll,5,9);
	INSERT_ELEMENTS(coll,1,4);
	
	PRINT_ELEMENTS(coll,"on entry: ");
	
	//convery collection into a heap
	make_heap(coll.begin(),coll.end());
	PRINT_ELEMENTS(coll,"after make_heap(): ");
	
	//pop next elements out of the heap
	pop_heap(coll.begin(),coll.end());
	coll.pop_back();
	PRINT_ELEMENTS(coll,"after pop_heap(): ");
	
	//push new elements into the heap
	coll.push_back(17);
	push_heap(coll.begin(),coll.end());
	PRINT_ELEMENTS(coll,"after push_heap(): ");
	
	//convery heap into a sorted collection
	//NOTE: after the call it's no longer a heap
	sort_heap(coll.begin(),coll.end());
	PRINT_ELEMENTS(coll,"after sort_heap(): ");

	
	return 0;
}
